#include "mainwindow_projet.h"

#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>



// TMP
#include <cstdlib>
#include <ctime>


MainWindow_projet::MainWindow_projet(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    /*
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    */

    _currentCol = -1;

    connect(actionImporter, SIGNAL(triggered()), this, SLOT(on_importer()));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(myPBTrier, SIGNAL(pressed()), this, SLOT(on_pushButton_trier()));
    connect(myPBColorier, SIGNAL(pressed()), this, SLOT(on_pushButton_colorier()));

    // TEST TMP
    // SIGNAL ---> clicked(QModelIndex)
    // int QModelIndex::column() const
    // [slot] void QTableView::selectColumn(int column)

    connect(_myTableView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_clicked_TB(QModelIndex)));



    // TEST
    //connect(_myTableView, SIGNAL (doubleClicked(QModelIndex)), this, SLOT(on_testPaint(QModelIndex)));
}

MainWindow_projet::~MainWindow_projet()
{
    delete _model;
    delete _modelColor;
}


/************************ TEST ****************************/

void MainWindow_projet::on_testPaint(QModelIndex index)
{

    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    _currentCol = index.column();
    qDebug() << "doubleClicked into column " << _currentCol;

    int idCaseTab = index.internalId();
    QStandardItem *caseTab;
    //QStandardItem *caseTab = new QStandardItem(QString("Coucou"));
    //QStandardItem caseTab;

    QColor color;
    color.setRgb( rand()%(250-0) +0,
                  rand()%(250-0) +0,
                  rand()%(250-0) +0 );
    //QPalette pal;
    //pal.setColor( QPalette::Window, color );
    QBrush brush;
    brush.setColor( color);
    //caseTab->setBackground( brush );
    //caseTab.setBackground( brush );

    // TEST
    //QItemSelectionModel *selectionModel = _myTableView->selectionModel();
    //QModelIndexList indexes = selectionModel->selectedIndexes();

    //model->setItem(index.row(), caseTab);


    QString text = QString("coucou");
    caseTab = _model->takeItem(index.row(), _currentCol);
    caseTab->setBackground( brush );
    caseTab->setForeground( brush );
    _model->setItem(index.row(), index.column(), caseTab);


    //QList<QStandardItem *> tmpColonne = _model->takeColumn(index.column());
    //QList<QStandardItem *> myColonne( tmpColonne );
    //QList<QStandardItem *> myColonne (tmpColonne);
    //_model->appendColumn(tmpColonne);
    //_model->appendColumn(myColonne);

    //_model->insertColumn(index.column(), tmpColonne);
    //_model->appendColumn(myColonne);

    //_model->setData(index, text);


    QStandardItemModel *_model2 =  new QStandardItemModel;

    QList<QStandardItem *> myColonne;
    for (int i=0; i<_model->rowCount(); i++) {
        //QModelIndex modelInd = _model->index(i, _currentCol);

        //caseTab = _model->takeItem(modelInd.row(), _currentCol);
        //QStandardItem *caseTab2 = _model->itemFromIndex(modelInd);
        //caseTab2 = _model->takeItem(index.row(), _currentCol);
        //_model2->setItem(modelInd.row(), 0, caseTab2);


        //QString val = modelInd.data().toString();
        //QStandardItem *myItem = new QStandardItem(val);
        //_model2->setItem(modelInd.row(), 0, myItem);

        //myColonne.append(caseTab2);
    }
    //_model->insertColumn(index.column(), myColonne);
    //_model->appendColumn(myColonne);

    /*
    _myTableView2->setModel(_model2);
    _myTableView2->show();
    _myTableView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myTableView2->setSelectionBehavior(QAbstractItemView::SelectColumns);
    */


    //QItemSelectionModel *selectionModel = _myTableView->selectionModel();
    //QModelIndexList indexes = selectionModel->selectedIndexes();

    /*
    foreach(index, indexes) {
        //QString text = QString("(%1, %2)").arg(index.row()).arg(index.column());
        //model->setData(index, text);
        //model->setItem(index.row(), caseTab);
    }
    */

    //modele1->itemFromIndex(modele1->index(i,j))->setBackground(QBrush(uneQColorQuelconque));


}



/* MENU BAR */

void MainWindow_projet::on_importer()
{
    qDebug() << __FUNCTION__ << endl;
    QString nom_fichier = ouvrir_dialogue();
    lire_fichier(nom_fichier);
}

QString MainWindow_projet::ouvrir_dialogue()
{
    qDebug() << __FUNCTION__ << endl;

    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",
                                                   QString(),
                                                   "");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + nom_fichier);
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
    //QItemSelectionModel *selectionModel = _myTableView->selectionModel();
    //QModelIndexList indexes = selectionModel->selectedIndexes();
    //_currentIndex = indexes[0];

    fichier.close();
}

void MainWindow_projet::trier()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;
    // METHODES POSSIBLES
    // void QTableView::sortByColumn(int column, Qt::SortOrder order)

    qDebug() << "tri sur colonne " << _currentCol << endl;
    if (_ordreTri) // Décroissant
        _myTableView->sortByColumn(_currentCol, Qt::DescendingOrder);
    else
        _myTableView->sortByColumn(_currentCol, Qt::AscendingOrder);

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


/* PUSH BUTTONS */

void MainWindow_projet::on_pushButton_trier()
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
            trier();
        }
    }
    else {
        ;
    }
    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


void MainWindow_projet::on_pushButton_colorier()
{
    qDebug() << __FUNCTION__ << endl;
    ouvrir_dialogue_colorier();
}

void MainWindow_projet::ouvrir_dialogue_colorier()
{
    qDebug() << __FUNCTION__ << endl;

    //delete _modelColor;
    if (_currentCol == -1) return;
    _modelColor =  new QStandardItemModel;
    copy_col_of_model(_model, _modelColor, _currentCol, 0);

    DialogColorier dlt(nullptr, _modelColor);
    if (dlt.exec()) {
        QStandardItemModel *newModelColor = dlt.model();
        copy_col_of_model(_modelColor, _model, 0, _currentCol);
        //tmpColonne = newModelColor->takeColumn(0);
        //_model->insertColumn(_currentCol, tmpColonne);
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
 * Pour que la fonction marche, il faut lui passer des attributs d'une instance comme arguments.
*------------------------------------------------------------------------------------------------*/
void MainWindow_projet::copy_col_of_model(QStandardItemModel *modelSrc,
                                                         QStandardItemModel *modelDest,
                                                         int colSrc, int colDest)
{
    qDebug() << __FUNCTION__ << endl;
    for (int i=0; i<modelSrc->rowCount(); i++) {
        QModelIndex modelSrcInd = modelSrc->index(i, colSrc);


        //QString val = modelSrcInd.data().toString();

        //QColor color = modelSrcInd.data().;
        //qDebug() << "color = " << color;

        //int brush = modelInd.data();
        //qDebug() << "brush = " << brush;

        /*
        QStandardItem *myItem (modelSrc->itemFromIndex(modelSrcInd));
        qDebug() << myItem->data().toString() << endl;
        modelDest->setItem(modelSrcInd.row(), colDest, myItem);
        */

        /*
        QStandardItem *myItem = new QStandardItem(val);
        modelDest->setItem(modelSrcInd.row(), colDest, myItem);
        QModelIndex modelDestInd = modelDest->index(i, colDest);
        //modelDest->itemFromIndex(modelDestInd)->setBackground(QColor (color));
        */

        QStandardItem *myItem = modelSrc->itemFromIndex(modelSrcInd)->clone();
        modelDest->setItem(modelSrcInd.row(), colDest, myItem);
    }
}



