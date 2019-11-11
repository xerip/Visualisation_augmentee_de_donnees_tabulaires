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

    int colors_empty(QVector< QVector< QVector<int> > > couleursOccupees);
    void trouverPremiereCouleurLibre(QVector< QVector< QVector<int> > > couleursOccupees,
                                     int &r, int &g, int &b);

protected:

    QString ouvrir_dialogue_importer();
    void lire_fichier(QString fichier);
    void trierTableView();

    void copy_col_of_model(QStandardItemModel *modelSrc, QStandardItemModel *modelDest,
                           int colSrc, int colDest);

    QVector< QVector< QVector<int> > > initialiser_couleurs_occuppees(int col);
    QVector<QVector<QColor> > extraire_couleurs();
    void display_model(QStandardItemModel *model);



signals:
    void signalTest(int col);

protected slots:
    void on_importer();

    void on_trier();
    void on_colorier();
    void on_valider();

    void on_clicked_TB(QModelIndex index);

};

#endif // MAINWINDOW_PROJET_H
