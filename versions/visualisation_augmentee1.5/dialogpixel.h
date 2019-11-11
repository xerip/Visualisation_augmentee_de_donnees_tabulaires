#ifndef DIALOGPIXEL_H
#define DIALOGPIXEL_H

#include "ui_dialogpixel.h"

#include <QVector>

class DialogPixel : public QDialog, private Ui::DialogPixel
{
    Q_OBJECT

private:
    int sizeX;
    int sizeY;
    QImage _myImage;
    QVector< QVector<QColor> > _myVecColor;

public:
    explicit DialogPixel(QWidget *parent = 0);
    DialogPixel(QWidget *parent, QVector< QVector<QColor> > vecColor);

protected:
    void create_image(int sizeX, int sizeY);
    void ouvrir_dialogueSave();

protected slots:
    void on_enregistrer();
    void on_Resolution();
};

#endif // DIALOGPIXEL_H

