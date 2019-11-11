#ifndef DIALOGTRIER_H
#define DIALOGTRIER_H

#include "ui_dialogtrier.h"

class DialogTrier : public QDialog, private Ui::DialogTrier
{
    Q_OBJECT

public:
    explicit DialogTrier(QWidget *parent = 0);
};

#endif // DIALOGTRIER_H
