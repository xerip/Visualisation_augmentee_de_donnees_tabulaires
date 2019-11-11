#include "mainwindow_projet.h"

#include <QApplication>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QHeaderView>
#include <QMimeData>

#include <QToolTip>



// TMP
#include <cstdlib>
#include <ctime>
using namespace std;

MainWindow_projet::MainWindow_projet(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    _currentCol = -1;
    setAcceptDrops(true);

    // Menu bar
    // Fichier
    connect( actionImporter, SIGNAL(triggered()), this, SLOT(on_importer()) );
    connect( actionGenererAl, SIGNAL(triggered()), this, SLOT(on_generer()) );
    connect( actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()) );
    // Edition
    connect( actionTrier, SIGNAL(triggered()), this, SLOT(on_trier()) );
    connect( actionColorier, SIGNAL(triggered()), this, SLOT(on_colorier()) );
    connect( actionValider, SIGNAL(triggered()), this, SLOT(on_valider()) );
    connect( actionA_propos, SIGNAL(triggered()), this, SLOT(on_help()));

    // Push buttons
    connect( myPBTrier, SIGNAL(pressed()), this, SLOT(on_trier()) );
    connect( myPBColorier, SIGNAL(pressed()), this, SLOT(on_colorier()) );
    connect( _myPBValider, SIGNAL(pressed()), this, SLOT(on_valider()) );

    // TableView
    connect( _myTableView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_clicked_TB(QModelIndex)) );
}

MainWindow_projet::~MainWindow_projet()
{
    delete _model;
    delete _modelColor;
    delete _progress;
}



/********************************** MENU BAR *************************************/

void MainWindow_projet::on_importer()
{
    QString nom_fichier = ouvrir_dialogue_importer();
    if (QString::compare(nom_fichier, "") == 0) {
        return;
    }
    lire_fichier(nom_fichier);
    //lire_fichier("../test.csv");
    enable_interactions();
}

void MainWindow_projet::on_generer()
{
    DialogGenerer dlg;
    if (dlg.exec()) {
        int nbCol = dlg.nb_col();
        int nbRow = dlg.nb_row();
        //qDebug() << "nbCol : " << nbCol << ", nbRow : " << nbRow;
        creer_tableau_aleatoire(nbCol, nbRow);
    }
    else {
        ;
    }
}

QString MainWindow_projet::ouvrir_dialogue_importer()
{
    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",
                                                   tr("../"),
                                                   "*.csv");
    return nom_fichier;
}

void MainWindow_projet::lire_fichier(QString nom_fichier)
{
    _model = new QStandardItemModel;

    QString fileName = nom_fichier;
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text); //mode lecture seulement
    QTextStream flux(&fichier);
    QString ligne;
    int lineindex=0;
    while (!flux.atEnd()) //atEnd = eof
    {
        ligne = flux.readLine(); //lecture ligne par ligne
        QStringList liste_val = ligne.split(",", QString::SkipEmptyParts);
        for (int col=0; col < liste_val.size(); ++col) {
                    QString val = liste_val.at(col);
                    QStandardItem *item = new QStandardItem(val);
                    _model->setItem(lineindex, col, item);
                }
                lineindex++;
    }

    _myTableView->setModel(_model);
    _myTableView->show();
    _myTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myTableView->setSelectionBehavior(QAbstractItemView::SelectColumns);
    _currentCol = 0;

    fichier.close();
}

void MainWindow_projet::trierTableView()
{
    if (_ordreTri) // Décroissant
        _myTableView->sortByColumn(_currentCol, Qt::DescendingOrder);
    else
        _myTableView->sortByColumn(_currentCol, Qt::AscendingOrder);
}


/******************** SIGNAUX D'EDITION *******************************/

void MainWindow_projet::on_trier()
{
    DialogTrier dlt;
    if (dlt.exec()) {
        _ordreTri = dlt.ordre_tri();
        if (_myTableView == nullptr) {
            qDebug() << "table vide, on ne peut pas trier" << endl;
        }
        else {
            qDebug() << "trier" << endl;
            trierTableView();
        }
    }
    else {
        ;
    }
}



void MainWindow_projet::on_colorier()
{
    if (_currentCol < 0) return;
    _modelColor =  new QStandardItemModel;
    copy_col_of_model(_model, _modelColor, _currentCol, 0);

    DialogColorier dlt(nullptr, _modelColor);
    if (dlt.exec()) {

        _modelColor->removeColumn(1);
        copy_col_of_model(dlt.model(), _model, 0, _currentCol);
    }
    else {
        ;
    }
}

void MainWindow_projet::on_valider()
{
    if (_currentCol < 0) return;

    int ok=1;
    QVector< QVector<QColor> > tabColor = extraire_couleurs(&ok);
    if (!ok) return;

    DialogPixel dlp(nullptr, tabColor);
    if (dlp.exec()) {
    }
    else {
        ;
    }
}

void MainWindow_projet::on_help()
{
    DialogHelp dlh;
    if (dlh.exec()) {
    }
    else {
        ;
    }
}

/********** AUTRES SIGNAUX *****************/

// Simple click sur la QTableView (pour traduire un click sur une colonne)
void MainWindow_projet::on_clicked_TB(QModelIndex index)
{
    _currentCol = index.column();
}

void MainWindow_projet::dragEnterEvent(QDragEnterEvent *event)
{
    if ((event->mimeData()->hasUrls())) // drag de fichiers seulement
    {
        if (event->mimeData()->urls().size()==1) // 1 fichier seulement
            event->acceptProposedAction(); // on accepte le drag de 1 fichier seulement
    }
    qDebug() << "dragevent" << endl;
}

void MainWindow_projet::dropEvent(QDropEvent *event)
{
    const QUrl url = event->mimeData()->urls()[0]; //chemin (url) du fichier droppé
    QString chemin_fichier = url.toLocalFile();
    qDebug() << "fichier droppé:" << chemin_fichier;
    QString nom_fichier = (chemin_fichier.split("/", QString::SkipEmptyParts)).back(); //nom du fichier
    QString ext = (nom_fichier.split(".", QString::SkipEmptyParts)).back(); //extension
    if (ext == "csv") {
        lire_fichier(chemin_fichier); //on lit le fichier seulement si c'est un fichier csv
        enable_interactions();
    }
}

/*************** UTILITAIRE ************************/

void MainWindow_projet::creer_tableau_aleatoire(int rows , int cols)
{
    _model = new QStandardItemModel;
    int lineindex=0;
    for (int row=0; row < rows; ++row)
    {
        for (int col=0; col < cols; ++col)
        {
             QString val = QString::number(rand()%(rows*cols));
             QStandardItem *item = new QStandardItem(val);
             _model->setItem(lineindex, col, item);
        }
        lineindex++;
    }
    _myTableView->setModel(_model);
    _myTableView->show();
    _myTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myTableView->setSelectionBehavior(QAbstractItemView::SelectColumns);
    _currentCol = 0;
    enable_interactions();
}

/*------------------------------------------------------------------------------------------------
 * Copie la colonne @colSend du modèle @model1, et l'insère à la colonne n°@colDest
 * de @model2
 * Pour que la fonction marche, il faut lui passer en arguments des attributs d'une instance.
*------------------------------------------------------------------------------------------------*/
void MainWindow_projet::copy_col_of_model(QStandardItemModel *modelSrc,
                                                         QStandardItemModel *modelDest,
                                                         int colSrc, int colDest)
{
    for (int i=0; i<modelSrc->rowCount(); i++) {
        QModelIndex modelSrcInd = modelSrc->index(i, colSrc);

        QStandardItem *myItem = modelSrc->itemFromIndex(modelSrcInd)->clone();
        modelDest->setItem(modelSrcInd.row(), colDest, myItem);
    }
}


QVector< QVector< QVector<int> > > MainWindow_projet::initialiser_couleurs_occuppees(int col)
{
    QVector< QVector<int>> vecInf(26, QVector<int>(26));
    QVector< QVector< QVector<int> > > testV (26, vecInf);

    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                testV[r][v][b] = 0;
            }
        }
    }
    for (int row=0; row<_model->rowCount(); row++)
    {
        QModelIndex modelInd = _model->index(row, col);
        //on recupere la couleur de la cellule
        QBrush brush = _model->itemFromIndex(modelInd)->background();
        QColor color = brush.color();
        int r = color.red();
        int g = color.green();
        int b = color.blue();

        // Si une couleur est déjà là
        if (r>0 && g>0 && b>0) {
            testV[r/10][g/10][b/10]=1;
        }
    }
    return testV;
}

QVector< QVector<QColor> > MainWindow_projet::extraire_couleurs(int *retourOk)
{
    int sizeX = _model->columnCount();
    int sizeY = _model->rowCount();
    QVector< QVector< QVector<int> > > couleurOccupeesV(26);
    QVector< QVector<QColor> > tab_color(sizeX, QVector<QColor>(sizeY));

    _progress = new QProgressDialog("Coloration...", "Annulation", 0, sizeX*sizeY, this);
    _progress->setWindowModality(Qt::WindowModal);
    int kProgress = 0;

    for (int col=0; col<_model->columnCount(); col++)
    {
        couleurOccupeesV = initialiser_couleurs_occuppees(col);

        for (int row=0; row<_model->rowCount(); row++)
        {
            if (_progress->wasCanceled()) {
                tab_color.clear();
                *retourOk = 0;
                return tab_color;
            }
            QModelIndex modelInd = _model->index(row, col);
            //on recupere la couleur de la cellule
            QBrush brush = _model->itemFromIndex(modelInd)->background();
            QColor color = brush.color();
            int r = color.red();
            int g = color.green();
            int b = color.blue();

            //Si il n'y a pas de couleur
            if ((r==0)&&(g==0)&&(b==0))
            {
                if (colors_empty(couleurOccupeesV)) {
                    _progress->cancel();
                    qDebug() << "Erreur, il n'a plus de couleurs disponibles";
                    tab_color.clear();
                    return tab_color;
                }

                do {
                    if (_progress->wasCanceled()) {
                        tab_color.clear();
                        *retourOk = 0;
                        return tab_color;
                    }
                    r = rand()%(25+1-0) +0;
                    g = rand()%(25+1-0) +0;
                    b = rand()%(25+1-0) +0;
                }
                while (couleurOccupeesV[r][g][b]);
                couleurOccupeesV[r][g][b]=1;
                tab_color[col][row].setRgb(r*10,g*10,b*10);

                //colorier occurences
                QString val = modelInd.data().toString();
                for (int new_row=0; new_row<_model->rowCount(); new_row++) {
                    QModelIndex Ind = _model->index(new_row, col);
                    QString valLigne = Ind.data().toString();
                    if (QString::compare(val, valLigne) == 0) {
                        tab_color[col][new_row].setRgb(tab_color[col][row].red(),
                                                       tab_color[col][row].green(),
                                                       tab_color[col][row].blue());
                    }
                }
            }
            else //Si il y a une couleur
            {
                tab_color[col][row].setRgb(r,g,b);
            }
            kProgress++;
            _progress->setValue(kProgress);
        }
    }

    return tab_color;
}


int MainWindow_projet::colors_empty(QVector< QVector< QVector<int> > > couleursOccupees)
{
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                if (!couleursOccupees[r][v][b]) return 0;
            }
        }
    }
    return 1;
}


void MainWindow_projet::display_model(QStandardItemModel *model)
{
    for (int col=0; col<model->columnCount(); col++)
    {
        qDebug() << "col " << col;
        for (int ligne=0; ligne < model->rowCount(); ligne++)
        {
            QModelIndex modelInd = model->index(ligne, col);
            QBrush brush = model->itemFromIndex(modelInd)->background();
            QColor color = brush.color();
            int r = color.red();
            int g = color.green();
            int b = color.blue();
            qDebug() << "ligne " << ligne << modelInd.data().toString()
                     << " r : " << r
                     << " g : " << g
                     << " b : " << b
                     << "\t";
        }
    }

}

void MainWindow_projet::enable_interactions()
{
    myPBTrier->setEnabled(true);
    actionTrier->setEnabled(true);
    myPBColorier->setEnabled(true);
    actionColorier->setEnabled(true);
    _myPBValider->setEnabled(true);
    actionValider->setEnabled(true);
}
