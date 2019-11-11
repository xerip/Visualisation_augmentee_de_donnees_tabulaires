#include "mainwindow_projet.h"

#include <QApplication>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QTextStream>

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <QVector3D>

// TMP
#include <cstdlib>
#include <ctime>


MainWindow_projet::MainWindow_projet(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    _currentCol = -1;

    /*
    _myTableView->setDragEnabled(true);
    _myTableView->viewport()->setAcceptDrops(true);
    */

    // Menu bar
    connect( actionImporter, SIGNAL(triggered()), this, SLOT(on_importer()) );
    connect( actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()) );

    connect( actionTrier, SIGNAL(triggered()), this, SLOT(on_trier()) );
    connect( actionColorier, SIGNAL(triggered()), this, SLOT(on_colorier()) );
    connect( actionValider, SIGNAL(triggered()), this, SLOT(on_valider()) );

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
}



/********************************** MENU BAR *************************************/

void MainWindow_projet::on_importer()
{
    qDebug() << __FUNCTION__ << endl;
    QString nom_fichier = ouvrir_dialogue_importer();
    lire_fichier(nom_fichier);
    //lire_fichier("../test.csv");
}

QString MainWindow_projet::ouvrir_dialogue_importer()
{
    qDebug() << __FUNCTION__ << endl;

    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",
                                                   tr("../"),
                                                   "*.csv");
    //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + nom_fichier);
    return nom_fichier;
}

void MainWindow_projet::lire_fichier(QString nom_fichier)
{
    //QStandardItemModel *model = new QStandardItemModel;
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
        //for (int x=0;x<liste_val.size();x++) cout << liste_val[x].toStdString() << endl;
        for (int i=0; i < liste_val.size(); ++i) {
                    QString val = liste_val.at(i);
                    QStandardItem *item = new QStandardItem(val);
                    _model->setItem(lineindex, i, item);
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
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    qDebug() << "tri sur colonne " << _currentCol << endl;
    if (_ordreTri) // Décroissant
        _myTableView->sortByColumn(_currentCol, Qt::DescendingOrder);
    else
        _myTableView->sortByColumn(_currentCol, Qt::AscendingOrder);

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


/******************** SIGNAUX D'EDITION *******************************/

void MainWindow_projet::on_trier()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;
    DialogTrier dlt;
    if (dlt.exec()) {
        _ordreTri = dlt.ordre_tri();
        if (!_ordreTri)
            qDebug() << "ordre de tri croissant" << endl;
        else
            qDebug() << "ordre de tri décroissant" << endl;
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
    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}



void MainWindow_projet::on_colorier()
{
    qDebug() << "<" << __FUNCTION__ << ">";
    qDebug() << __FUNCTION__ << endl;

    if (_currentCol < 0) return;
    _modelColor =  new QStandardItemModel;
    copy_col_of_model(_model, _modelColor, _currentCol, 0);


    DialogColorier dlt(nullptr, _modelColor);
    if (dlt.exec()) {
        //copy_col_of_model(_modelColor, _model, 0, _currentCol);

        _modelColor->removeColumn(1);
        copy_col_of_model(dlt.model(), _model, 0, _currentCol);
        /*
        qDebug() << "\nMODEL" << endl;
        display_model(_model);
        qDebug() << "\nMODELCOLOR" << endl;
        display_model(_modelColor);
        */
    }
    else {
        ;
    }
    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void MainWindow_projet::on_valider()
{
    qDebug() << __FUNCTION__ << endl;

    if (_currentCol < 0) return;

    clock_t temps;
    srand(time(NULL));

    QVector< QVector<QColor> > tabColor = extraire_couleurs();

    temps=clock();
    qDebug() << "extraction couleurs en " << (double) temps/CLOCKS_PER_SEC << "s";

    /*
    for (int l=0; l<_model->rowCount();l++)
        qDebug() << tabColor[0][l].red()<< " "<< tabColor[0][l].green()<<" "<< tabColor[0][l].blue()<<endl;
    */


    //DialogPixel dlp;
    DialogPixel dlp(nullptr, tabColor);
    if (dlp.exec()) {
    }
    else {
        ;
    }
}


/********** AUTRES SIGNAUX *****************/

// Simple click sur la QTableView (pour traduire un click sur une colonne)
void MainWindow_projet::on_clicked_TB(QModelIndex index)
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    //qDebug() << "emit signalTest();";
    //emit signalTest(1);

    //_currentIndex = index;
    _currentCol = index.column();
    qDebug() << "clicked into column " << _currentCol;
    qDebug() << "colonne courante =  " << _currentCol;


    //send_modelColor();
}


/*************** UTILITAIRE ************************/

/*------------------------------------------------------------------------------------------------
 * Copie la colonne @colSend du modèle @model1, et l'insère à la colonne n°@colDest
 * de @model2
 * Pour que la fonction marche, il faut lui passer en arguments des attributs d'une instance.
*------------------------------------------------------------------------------------------------*/
void MainWindow_projet::copy_col_of_model(QStandardItemModel *modelSrc,
                                                         QStandardItemModel *modelDest,
                                                         int colSrc, int colDest)
{
    qDebug() << __FUNCTION__ << endl;
    for (int i=0; i<modelSrc->rowCount(); i++) {
        QModelIndex modelSrcInd = modelSrc->index(i, colSrc);

        QStandardItem *myItem = modelSrc->itemFromIndex(modelSrcInd)->clone();
        modelDest->setItem(modelSrcInd.row(), colDest, myItem);
    }
}


QVector< QVector< QVector<int> > > MainWindow_projet::initialiser_couleurs_occuppees(int col)
{
    //int couleurOccupees[26][26][26];

    //qDebug() << "<" << __FUNCTION__ << ">";

    // QVector<QVector3D> couleurOccupeesV3D(26);
    //qDebug() << couleurOccupeesV3D;

    // QVector< QVector<QColor> > tab_color(sizeX, QVector<QColor>(sizeY));

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
        if (r>0 && g>0 && b>0)
        {
            //qDebug() << "r = " << r << ", g = " << g << ", b = " << b;
            testV[r/10][g/10][b/10]=1;
        }
    }
    //qDebug() << "</" << __FUNCTION__ << ">" << endl;
    return testV;
}

QVector< QVector<QColor> > MainWindow_projet::extraire_couleurs()
{
    qDebug() << "<" << __FUNCTION__ << ">";


    int sizeX = _model->columnCount();
    int sizeY = _model->rowCount();
    //QColor *tab_color = new QColor[sizeX][sizeY];

    QVector< QVector< QVector<int> > > couleurOccupeesV(26);
    //couleurOccupeesV = test_initV(0);

    // Create
    QVector< QVector<QColor> > tab_color(sizeX, QVector<QColor>(sizeY));
    // Exemple
    // Write
    //vec[2][3].setRgb(23, 34, 56);
    // Read
    //QColor a = vec[2][3];

    for (int col=0; col<_model->columnCount(); col++)
    {
        //qDebug() << "\ncol " << col;
        couleurOccupeesV = initialiser_couleurs_occuppees(col);

        for (int row=0; row<_model->rowCount(); row++)
        {
            QModelIndex modelInd = _model->index(row, col);
            //on recupere la couleur de la cellule
            QBrush brush = _model->itemFromIndex(modelInd)->background();
            QColor color = brush.color();
            int r = color.red();
            int g = color.green();
            int b = color.blue();

            //qDebug() << "row " << row;

            //Si il n'y a pas de couleur // TMP pour l'instant la couleur 0 0 0 signifie absence de couleur
            if ((r==0)&&(g==0)&&(b==0))
            {
                if (colors_empty(couleurOccupeesV)) {
                    qDebug() << "Erreur, il n'a plus de couleurs disponibles";
                    tab_color.clear();
                    return tab_color;
                }
                r = rand()%(25+1-0) +0;
                g = rand()%(25+1-0) +0;
                b = rand()%(25+1-0) +0;
                // Si couleur déjà prise
                if (couleurOccupeesV[r][g][b]) {
                    // On cherche itérativement une autre couleur qui soit libre.
                    trouverPremiereCouleurLibre(couleurOccupeesV, r, g, b);
                }
                couleurOccupeesV[r][g][b]=1;

                //QColor coul = QColor(r*10,g*10,b*10);
                //tab_color[col][row] = coul;
                tab_color[col][row].setRgb(r*10,g*10,b*10);


                //colorier occurences
                QString val = modelInd.data().toString();
                for (int new_row=0; new_row<_model->rowCount(); new_row++) {
                    QModelIndex Ind = _model->index(new_row, col);
                    QString valLigne = Ind.data().toString();
                    if (QString::compare(val, valLigne) == 0) {
                        //tab_color[col][new_row]=tab_color[col][row];
                        tab_color[col][new_row].setRgb(tab_color[col][row].red(),
                                                       tab_color[col][row].green(),
                                                       tab_color[col][row].blue());
                    }
                }
            }
            else //Si il y a une couleur
            {
                //_couleurOccupees[r/10][g/10][b/10]=1;
                //QColor coul = QColor(r*10,g*10,b*10);
                //QColor coul = QColor(r, g, b);
                //tab_color[col][row] = coul;
                tab_color[col][row].setRgb(r,g,b);
            }
        }
    }


    /*
    for (int l=0; l<_model->rowCount();l++)
        qDebug() << tab_color[0][l].red()<< " "<< tab_color[0][l].green()<<" "<< tab_color[0][l].blue()<<endl;
    */

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
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


/*---------------------------------------------------------------------------------------------------
 * Parcours itérativement le tableau @couleurUtilises et renvoie les indices @r @g @b
 * de la première couleur trouvée libre (==0)
 * Vérifier avant que le tableau ne soit pas déja remplit (permet d'optimiser le temps de calcul)
 * Commence aux indices+1 de @r, @g et @b.
 * -------------------------------------------------------------------------------------------------*/
void MainWindow_projet::trouverPremiereCouleurLibre(QVector< QVector< QVector<int> > > couleursOccupees,
                                                    int &r, int &g, int &b)
{
    //qDebug() << "<" << __FUNCTION__ << ">" << endl;

    int c1, c2, c3;
    int choix = rand()%(2+1-0) +0;
    switch (choix) {
        case 0:
            c1=r;   c2=g;   c3=b;
            break;
        case 1:
            c1=g;   c2=b;   c3=r;
            break;
        default:
            c1=b;   c2=r;   c3=g;
            break;
    }

    //qDebug() << "choix " << choix << "c1=" << c1 << "c2=" << c2 << "c3=" << c3;


    int c1Base = c1, c2Base=c2, c3Base=c3;
    c1++; c2++; c3++;
    int bouclesAutorises=0;
    while (c1!=c1Base && bouclesAutorises<26)
    {
        if (c1>25) c1=0;
        //qDebug() << "\nc1 : " << c1;

        while (c2!=c2Base)
        {
            if (c2>25) c2=0;
            //qDebug() << "\nc2 : " << c2;

            while (c3!=c3Base)
            {
                if (c3>25) c3=0;
                //qDebug() << "c3 : " << c3;

                if (!couleursOccupees[c1][c2][c3]) {
                    r = c1; g=c2;   b=c3;
                    return;
                }
                c3++;
            }
            c3++;
            c2++;
        }
        c2++;
        c1++;
        bouclesAutorises++;
    }

    //qDebug() << "</" << __FUNCTION__ << ">" << endl;
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
