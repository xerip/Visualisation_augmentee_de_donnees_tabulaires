#ifndef DIALOGTRIER_H
#define DIALOGTRIER_H

#include "ui_dialogtrier.h"

class DialogTrier : public QDialog, private Ui::DialogTrier
{
    Q_OBJECT

private:
    int _ordreTri;
public:
    explicit DialogTrier(QWidget *parent = nullptr);
    int ordre_tri();

protected slots:
    void on_check_button_radio();

};

#endif // DIALOGTRIER_H
