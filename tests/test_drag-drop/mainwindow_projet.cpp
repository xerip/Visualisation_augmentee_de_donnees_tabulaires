#include "mainwindow_projet.h"
#include <string>
#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <iostream>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemView>
#include <QDragEnterEvent> // **a add**
#include <QDropEvent> // **a add**
#include <QHeaderView> // **a add ?**
#include <QMimeData> // **a add**
using namespace std;


#include <time.h>
#include <string>

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
    setAcceptDrops(true); // *************** RAJOUT DE CETTE LIGNE ******************
}

// *********************** RAJOUT DE CES DEUX FONCTIONS !!! *****************************
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
    if (ext == "csv")
        lire_fichier(chemin_fichier); //on lit le fichier seulement si c'est un fichier csv
}
// **************************************************************************************

void MainWindow_projet::on_importer()
{
    qDebug() << __FUNCTION__ << endl;
    //QString nom_fichier = ouvrir_dialogue();
    //lire_fichier(nom_fichier);
    creer_tableau_aleatoire(1000,1000);
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

void MainWindow_projet::lire_fichier(QString nom_fichier) //en attente pour changer titre des colonnes
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

void MainWindow_projet::creer_tableau_aleatoire(int x , int y)
{
    QStandardItemModel *model = new QStandardItemModel;
    int lineindex=0;
    for (int i=0; i < x; ++i)
    {
        for (int j=0; j < y; ++j)
        {
             QString val = QString::number(rand()%(x*y));
             QStandardItem *item = new QStandardItem(val);
             model->setItem(lineindex, j, item);
        }
        lineindex++;
    }
    _myTableView->setModel(model);
    _myTableView->show();
    _myTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myTableView->setSelectionBehavior(QAbstractItemView::SelectColumns);
}

void MainWindow_projet::trier()
{
    // METHODES POSSIBLES

    // void QTableView::sortByColumn(int column, Qt::SortOrder order)
}

void MainWindow_projet::extraire_colonne()
{
    // METHODES POSSIBLES

    // int QTableView::columnAt(int x) const
    // int QTableView::columnViewportPosition(int column) const

    // [slot] void QTableView::selectColumn(int column)
    // [slot] void QTableView::selectRow(int row)

    // int QTableView::columnWidth(int column) const
}

void MainWindow_projet::colorer()
{
    // METHODES POSSIBLES

    // [override virtual protected] void QTableView::paintEvent(QPaintEvent *event)
}














