#ifndef MAINWINDOW_PROJET_H
#define MAINWINDOW_PROJET_H

#include "ui_mainwindow_projet.h"
#include "dialogtrier.h"
#include "dialogcolorier.h"

class MainWindow_projet : public QMainWindow, private Ui::MainWindow_projet
{
    Q_OBJECT

private:
    int _ordreTri=0; // croissant par défaut
    int _currentCol=0;  // Colonne 0 selectionnée par défaut

public:
    explicit MainWindow_projet(QWidget *parent = 0); //nullptr=0, version qt de pierre est pourrie

protected:
    void ouvrir_dialogue_importer();
    void ouvrir_dialogue_colorier();

    QString ouvrir_dialogue();
    void lire_fichier(QString fichier);
    void trier();

signals:
    void signalTest(int col);

protected slots:
    void on_importer();

    void on_pushButton_trier();
    void on_pushButton_colorier();

    void on_clicked_TB(QModelIndex index);
};

#endif // MAINWINDOW_PROJET_H
