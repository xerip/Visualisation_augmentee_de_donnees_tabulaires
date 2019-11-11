#ifndef MAINWINDOW_PROJET_H
#define MAINWINDOW_PROJET_H

#include "ui_mainwindow_projet.h"
#include "dialogtrier.h"
#include "dialogcolorier.h"

class MainWindow_projet : public QMainWindow, private Ui::MainWindow_projet
{
    Q_OBJECT

public:
    explicit MainWindow_projet(QWidget *parent = 0);

protected:
    void ouvrir_dialogue_importer();
    void ouvrir_dialogue_trier();
    void ouvrir_dialogue_colorier();

protected slots:
    void on_importer();
    void on_pushButton_trier();
    void on_pushButton_colorier();
};

#endif // MAINWINDOW_PROJET_H
