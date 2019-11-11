#ifndef DIALOGPIXEL_H
#define DIALOGPIXEL_H

#include "ui_dialogpixel.h"

class DialogPixel : public QDialog, private Ui::DialogPixel
{
    Q_OBJECT

public:
    explicit DialogPixel(QWidget *parent = 0);
};

#endif // DIALOGPIXEL_H
