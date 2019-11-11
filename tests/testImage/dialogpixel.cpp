#include "dialogpixel.h"

#include <QDebug>

#include <QImage>
#include <QGraphicsScene>
#include <QPixmap>

#include <cstdlib>
#include <ctime>

DialogPixel::DialogPixel(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    // int sizeX = 100;
    // int sizeY = 100;

    QSize sizeWindow = this->size();
    int sizeX = sizeWindow.width();
    int sizeY = sizeWindow.height();

    qDebug() << "sizeX = " << sizeX;
    qDebug() << "sizeY = " << sizeY;

    int imX = 3;
    int imY = 10;
    QImage image = QImage(imX, imY, QImage::Format_RGB32);

    for (int line=0; line<imX; line++) {
        //int colorColR = rand()%(255-0) +0;
        //int colorColV = rand()%(255-0) +0;
        //int colorColB = rand()%(255-0) +0;
        for (int col=0; col<imY; col++) {
            //image.setPixel( line, col, qRgb(colorColR, colorColV, colorColB) );
            image.setPixel( line, col, qRgb(rand()%(255-0) +0, rand()%(255-0) +0, rand()%(255-0) +0) );
        }
    }

    image = image.scaled(sizeX, sizeY);

    QGraphicsScene *graphic = new QGraphicsScene( this );
    graphic->addPixmap( QPixmap::fromImage( image) );

    _myGV->setScene(graphic);


    // METHODES UTILES ?

    //qreal QImage::devicePixelRatio() const

    // QImage QImage::scaled(int width, int height, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio,
        //Qt::TransformationMode transformMode = Qt::FastTransformation) const


}

