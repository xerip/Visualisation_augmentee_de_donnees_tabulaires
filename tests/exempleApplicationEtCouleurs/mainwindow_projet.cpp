#include "mainwindow_projet.h"

#include <QApplication>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>


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
}

/* MENU BAR */

void MainWindow_projet::on_importer()
{
    qDebug() << __FUNCTION__ << endl;
    ouvrir_dialogue_importer();
}

void MainWindow_projet::ouvrir_dialogue_importer()
{
    qDebug() << __FUNCTION__ << endl;

    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",
                                                   QString(),
                                                   "");
    QMessageBox::information(this, "Fichier",
                             "Vous avez sélectionné :\n" + fichier);
}


/* PUSH BUTTONS */

void MainWindow_projet::on_pushButton_trier()
{
    qDebug() << __FUNCTION__ << endl;
    ouvrir_dialogue_trier();
}

void MainWindow_projet::ouvrir_dialogue_trier()
{
    qDebug() << __FUNCTION__ << endl;
    DialogTrier dlt;
    if (dlt.exec()) {
        ;
    }
    else {
        ;
    }
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





