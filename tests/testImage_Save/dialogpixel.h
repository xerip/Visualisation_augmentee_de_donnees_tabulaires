#ifndef DIALOGPIXEL_H
#define DIALOGPIXEL_H

#include "ui_dialogpixel.h"

class DialogPixel : public QDialog, private Ui::DialogPixel
{
    Q_OBJECT

private:
    QImage _myImage;

public:
    explicit DialogPixel(QWidget *parent = 0);

protected:
    void create_image(int sizeX, int sizeY);
    void ouvrir_dialogueSave();

protected slots:
    void on_enregistrer();
};

#endif // DIALOGPIXEL_H

