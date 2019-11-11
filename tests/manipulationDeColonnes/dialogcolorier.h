#ifndef DIALOGCOLORIER_H
#define DIALOGCOLORIER_H

#include "ui_dialogcolorier.h"

#include <cstdlib>
#include <ctime>

#include <QStandardItemModel>

class DialogColorier : public QDialog, private Ui::DialogColorier
{
    Q_OBJECT

private:
    int couleurUtilises[26][26][26]; // PROBLEME TAILLE TROP GRANDE
    QStandardItemModel *_model;

public:
    //explicit DialogColorier(QWidget *parent = 0);
    explicit DialogColorier(QWidget *parent, QStandardItemModel *_model);
    int colors_empty();

    QStandardItemModel *model();

protected:
    void convert_color(int &color_r, int &color_v, int &color_b);

protected slots:
    void on_colorChanged();
    void on_reinitColor();
    void on_colorAleatoire();
    void on_valid_color();

    void on_testPaint(QModelIndex _myIndex);

};

#endif // DIALOGCOLORIER_H
