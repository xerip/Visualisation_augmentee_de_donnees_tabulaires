#ifndef DIALOGCOLORIER_H
#define DIALOGCOLORIER_H

#include "ui_dialogcolorier.h"

#include <cstdlib>
#include <ctime>

class DialogColorier : public QDialog, private Ui::DialogColorier
{
    Q_OBJECT

private:
    int couleurUtilises[26][26][26]; // PROBLEME TAILLE TROP GRANDE

public:
    explicit DialogColorier(QWidget *parent = 0);
    int colors_empty();

protected:
    void convert_color(int &color_r, int &color_v, int &color_b);

protected slots:
    void on_colorChanged();
    void on_reinitColor();
    void on_colorAleatoire();
    void on_valid_color();

};

#endif // DIALOGCOLORIER_H
