#include "dialogpixel.h"

#include <QDebug>

#include <QImage>
#include <QGraphicsScene>
#include <QPixmap>
#include <QBuffer>
#include <QFileDialog>
#include <QMessageBox>

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

    create_image(sizeX, sizeY);

    connect(_myBBSave, SIGNAL(accepted()), this, SLOT(on_enregistrer()));

}

void DialogPixel::create_image(int sizeX, int sizeY)
{
    int imX = 3;
    int imY = 10;
    _myImage = QImage(imX, imY, QImage::Format_RGB32);

    for (int line=0; line<imX; line++) {
        //int colorColR = rand()%(255-0) +0;
        //int colorColV = rand()%(255-0) +0;
        //int colorColB = rand()%(255-0) +0;
        for (int col=0; col<imY; col++) {
            //_myImage.setPixel( line, col, qRgb(colorColR, colorColV, colorColB) );
            _myImage.setPixel( line, col, qRgb(rand()%(255-0) +0, rand()%(255-0) +0, rand()%(255-0) +0) );
        }
    }

    _myImage = _myImage.scaled(sizeX, sizeY);

    QGraphicsScene *graphic = new QGraphicsScene( this );
    graphic->addPixmap( QPixmap::fromImage( _myImage ) );

    _myGV->setScene(graphic);
}

void DialogPixel::ouvrir_dialogueSave()
{
    qDebug() << __FUNCTION__ << endl;

}

void DialogPixel::on_enregistrer()
{
    qDebug() << "<" << __FUNCTION__ << ">";
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    //ouvrir_dialogueSave();

    QFileDialog myFileDialog(this);

    myFileDialog.setAcceptMode(QFileDialog::AcceptSave);
    //myFileDialog.open(this, "");
    QString cheminFichier = myFileDialog.getSaveFileName(this,
                                                         "Enregistrer Image",
                                                         //QString(),
                                                         tr("../image.png"),
                                                         "Image (*.jpg *.jpeg *.png *.gif)");

    //nomFichier.
    QString nomFichier = QFileInfo(cheminFichier).fileName();
    qDebug() << "nom_fichier = " << nomFichier;
    /*
    if (QString::compare(nomFichier, "") != 0) {

    }
    */
    if (_myImage.save(cheminFichier, "PNG")) { // writes image into ba in PNG format
        QMessageBox::information(this, "Fichier", nomFichier + " enregistrée\n");
    }


    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}









