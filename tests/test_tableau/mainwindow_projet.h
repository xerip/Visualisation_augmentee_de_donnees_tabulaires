#ifndef MAINWINDOW_PROJET_H
#define MAINWINDOW_PROJET_H

#include "ui_mainwindow_projet.h"

class MainWindow_projet : public QMainWindow, private Ui::MainWindow_projet
{
    Q_OBJECT

public:
    explicit MainWindow_projet(QWidget *parent = 0); //nullptr = 0, ma version marche pas wesh
    void extraire_colonne();

protected:
    //void ouvrir_fichier ();
    QString ouvrir_dialogue();
    void lire_fichier(QString fichier);
    void trier();
    void colorer();

protected slots:
    //void on_ouvrir_fichier();
    void on_importer();
};

#endif // MAINWINDOW_PROJET_H
