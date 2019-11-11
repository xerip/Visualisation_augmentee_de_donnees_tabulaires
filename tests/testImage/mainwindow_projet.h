#ifndef MAINWINDOW_PROJET_H
#define MAINWINDOW_PROJET_H

#include "ui_mainwindow_projet.h"
#include "dialogtrier.h"
#include "dialogcolorier.h"
#include "dialogpixel.h"

#include <QStandardItemModel>

class MainWindow_projet : public QMainWindow, private Ui::MainWindow_projet
{
    Q_OBJECT

private:
    int _ordreTri=0; // croissant par défaut
    int _currentCol=0;  // Colonne 0 selectionnée par défaut

    QStandardItemModel *_model;
    QStandardItemModel *_modelColor;
    //QModelIndex _currentIndex;

public:
    explicit MainWindow_projet(QWidget *parent = nullptr);
    ~MainWindow_projet();

protected:
    void ouvrir_dialogue_importer();

    QString ouvrir_dialogue();
    void lire_fichier(QString fichier);
    void trier();

    void copy_col_of_model(QStandardItemModel *modelSrc, QStandardItemModel *modelDest,
                           int colSrc, int colDest);



signals:
    void signalTest(int col);

protected slots:
    void on_importer();

    void on_pushButton_trier();
    void on_pushButton_colorier();
    void on_pushButton_valider();

    void on_clicked_TB(QModelIndex index);

};

#endif // MAINWINDOW_PROJET_H
