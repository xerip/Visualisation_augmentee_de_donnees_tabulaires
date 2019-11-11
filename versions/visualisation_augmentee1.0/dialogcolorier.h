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
    int couleurUtilises[26][26][26];
    QStandardItemModel *_model;
    int _currentRow=0;
    /*
    struct attribCouleur {
        int idRow=-1;
        int r=-1, g=-1, b=-1;
    };
    attribCouleur *tabAttribCouleur;
    */

    void initialiser_couleurs_disponibles();

public:
    //explicit DialogColorier(QWidget *parent = 0);
    explicit DialogColorier(QWidget *parent, QStandardItemModel *_model);
    int colors_empty();

    QStandardItemModel *model();

protected:
    void adapt_colors_to_data(int &color_r, int &color_v, int &color_b);
    void colorier_occurences(QString val, QColor color);
    void reinit_occurences(QString val);
    void libererCouleur();
    void updateColor();

protected slots:
    void on_colorChanged();

    void on_appliquerColor();
    void on_reinitColor();
    void on_colorAleatoire();
    //void on_valid_color();

    void on_tout_aleatoire();
    void on_tout_reinitialiser();

    void on_afficher_caseTab(QModelIndex _myIndex);

};

#endif // DIALOGCOLORIER_H
