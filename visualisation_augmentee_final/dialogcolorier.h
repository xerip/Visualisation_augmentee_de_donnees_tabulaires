#ifndef DIALOGCOLORIER_H
#define DIALOGCOLORIER_H

#include "ui_dialogcolorier.h"

#include <cstdlib>
#include <ctime>

#include <QStandardItemModel>
#include <QProgressDialog>
#include <QMouseEvent>

class DialogColorier : public QDialog, private Ui::DialogColorier
{
    Q_OBJECT

private:
    int couleurUtilises[26][26][26];
    QStandardItemModel *_model;
    int _currentRow=0;
    QProgressDialog *_progress;

    void initialiser_couleurs_disponibles();

public:
    explicit DialogColorier(QWidget *parent, QStandardItemModel *_model);
    int colors_empty();
    void trouverPremiereCouleurLibre(int &r, int &g, int &b);

    QStandardItemModel *model();

protected:
    void adapt_colors_to_data(int &color_r, int &color_v, int &color_b);
    void colorier_occurences(QString val, QColor color);
    void reinit_occurences(QString val);
    void libererCouleur();
    void updateColor();
    void reinit_couleurs_occupees();
    void mousePressEvent(QMouseEvent *event);

signals:
    // Auto implémenté
    void change_text(QString value);

protected slots:
    void on_colorChanged();

    void on_appliquerColor();
    void on_message_erreur(QString value);
    void on_reinitColor();
    void on_colorAleatoire();

    void on_tout_aleatoire();
    void on_tout_reinitialiser();

    void on_afficher_caseTab(QModelIndex _myIndex);

};

#endif // DIALOGCOLORIER_H
