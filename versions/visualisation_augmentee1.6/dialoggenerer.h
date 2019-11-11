#ifndef DIALOGGENERER_H
#define DIALOGGENERER_H

#include "ui_dialoggenerer.h"

class DialogGenerer : public QDialog, private Ui::DialogGenerer
{
    Q_OBJECT

private:
    int _nbCol=10;
    int _nbRow=10;

public:
    explicit DialogGenerer(QWidget *parent = 0);

    int nb_col();
    int nb_row();

protected slots:
    void on_choix_dimensions(int value);
};

#endif // DIALOGGENERER_H
