#include "mainwindow_projet.h"

#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <QStandardItemModel>
#include <iostream>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QHeaderView>
using namespace std;


MainWindow_projet::MainWindow_projet(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    /*
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    */

    connect(actionImporter, SIGNAL(triggered()), this, SLOT(on_importer()));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(myPBTrier, SIGNAL(pressed()), this, SLOT(on_pushButton_trier()));
    connect(myPBColorier, SIGNAL(pressed()), this, SLOT(on_pushButton_colorier()));

    // TEST TMP
    // SIGNAL ---> clicked(QModelIndex)
    // int QModelIndex::column() const
    // [slot] void QTableView::selectColumn(int column)


    connect(_myTableView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_clicked_TB(QModelIndex)));
    //connect(_myTableView, SIGNAL(signalTest(int)), this, SLOT(selectColumn(int)));

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
    QStandardItemModel *model = new QStandardItemModel;

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
                    model->setItem(lineindex, i, item);
                }
                lineindex++;
    }

    _myTableView->setModel(model);
    _myTableView->show();
    _myTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myTableView->setSelectionBehavior(QAbstractItemView::SelectColumns);

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
        if (_myTableView == 0) {
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
    DialogColorier dlt;
    if (dlt.exec()) {
        ;
    }
    else {
        ;
    }
}


/********** AUTRES SIGNAUX *****************/

void MainWindow_projet::on_clicked_TB(QModelIndex index)
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    //qDebug() << "emit signalTest();";
    //emit signalTest(1);

    _currentCol = index.column();
    qDebug() << "clicked into column " << _currentCol;
    qDebug() << "row " << index.row();
    QStringList list;
    QAbstractItemModel *model =_myTableView->model();

    for(int i = 0; i < model->rowCount(); i++)
    {
        QModelIndex index = model->index(i, _currentCol);
        //model->setItemData(index, Qt::blue);
        list.append(index.data().toString());
    }
    for (int x=0;x<list.size();x++) cout << list[x].toStdString() << endl;
}




