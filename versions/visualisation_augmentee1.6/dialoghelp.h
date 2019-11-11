#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include "ui_dialoghelp.h"

class DialogHelp : public QDialog, private Ui::DialogHelp
{
    Q_OBJECT

public:
    explicit DialogHelp(QWidget *parent = 0);
};

#endif // DIALOGHELP_H
