#ifndef MAINWINDOW_PROJET_H
#define MAINWINDOW_PROJET_H

#include "ui_mainwindow_projet.h"

class MainWindow_projet : public QMainWindow, private Ui::MainWindow_projet
{
    Q_OBJECT

public:
    explicit MainWindow_projet(QWidget *parent = 0);

protected:
    //void ouvrir_fichier ();
    QString ouvrir_dialogue();
    void lire_fichier(QString fichier);

protected slots:
    //void on_ouvrir_fichier();
    void on_importer();
};

#endif // MAINWINDOW_PROJET_H
