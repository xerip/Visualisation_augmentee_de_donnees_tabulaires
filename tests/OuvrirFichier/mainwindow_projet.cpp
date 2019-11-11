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
}

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
    QString fileName = nom_fichier;
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text); //mode lecture seulement
    QTextStream flux(&fichier);
    QString ligne;
    while (!flux.atEnd()) //atEnd = eof
    {
        ligne = flux.readLine(); //lecture ligne par ligne
        //cout << ligne.toStdString() << endl;
    }
}
