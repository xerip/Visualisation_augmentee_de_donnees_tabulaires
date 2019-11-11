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

    _currentCol = -1;

    connect(actionImporter, SIGNAL(triggered()), this, SLOT(on_importer()));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(myPBTrier, SIGNAL(pressed()), this, SLOT(on_pushButton_trier()));
    connect(myPBColorier, SIGNAL(pressed()), this, SLOT(on_pushButton_colorier()));
    connect(_myPBValider, SIGNAL(pressed()), this, SLOT(on_pushButton_valider()));

    connect(_myTableView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_clicked_TB(QModelIndex)));

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
    //QString nom_fichier = ouvrir_dialogue();
    //lire_fichier(nom_fichier);
    lire_fichier("../test.csv");
}

QString MainWindow_projet::ouvrir_dialogue()
{
    qDebug() << __FUNCTION__ << endl;

    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",
                                                   QString(),
                                                   "");
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

void MainWindow_projet::trier()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    qDebug() << "tri sur colonne " << _currentCol << endl;
    if (_ordreTri) // Décroissant
        _myTableView->sortByColumn(_currentCol, Qt::DescendingOrder);
    else
        _myTableView->sortByColumn(_currentCol, Qt::AscendingOrder);

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


/******************** PUSH BUTTONS *******************************/

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

    if (_currentCol < 0) return;
    _modelColor =  new QStandardItemModel;
    copy_col_of_model(_model, _modelColor, _currentCol, 0);

    DialogColorier dlt(nullptr, _modelColor);
    if (dlt.exec()) {
        copy_col_of_model(_modelColor, _model, 0, _currentCol);
    }
    else {
        ;
    }
}

void MainWindow_projet::on_pushButton_valider()
{
    qDebug() << __FUNCTION__ << endl;

    if (_currentCol < 0) return;

    DialogPixel dlp;
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



