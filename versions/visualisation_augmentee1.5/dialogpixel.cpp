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

DialogPixel::DialogPixel(QWidget *parent, QVector<QVector<QColor> > vecColor) :
    QDialog(parent)
{
    setupUi(this);

    _myVecColor = vecColor;

    /*
    QSize sizeWindow = this->size();
    int sizeX = sizeWindow.width();
    int sizeY = sizeWindow.height();

    int sizeX = _myGV->width();
    int sizeY = _myGV->height();
    */

    sizeX = 360;
    sizeY = 240;

    qDebug() << "sizeX = " << sizeX;
    qDebug() << "sizeY = " << sizeY;

    create_image(sizeX, sizeY);

    connect(_myRB360, SIGNAL(clicked()), this, SLOT(on_Resolution()));
    connect(_myRB480, SIGNAL(clicked()), this, SLOT(on_Resolution()));
    connect(_myRB720, SIGNAL(clicked()), this, SLOT(on_Resolution()));
    connect(_myRB1080, SIGNAL(clicked()), this, SLOT(on_Resolution()));


    connect(_myBBSave, SIGNAL(accepted()), this, SLOT(on_enregistrer()));
}

void DialogPixel::create_image(int sizeX, int sizeY)
{
    qDebug() << "<" << __FUNCTION__ << ">";
    /*
    int imX = 3;
    int imY = 10;
    */
    int imX = _myVecColor.size();
    int imY = _myVecColor[0].size();
    qDebug() << "imX = " << imX << "imY = " << imY;
    _myImage = QImage(imX, imY, QImage::Format_RGB32);


    for (int line=0; line<imX; line++)
    {
        for (int col=0; col<imY; col++)
        {
            _myImage.setPixel( line, col, _myVecColor[line][col].rgb() );
        }
    }

    /*
    for (int line=0; line<imX; line++) {
        //int colorColR = rand()%(255-0) +0;
        //int colorColV = rand()%(255-0) +0;
        //int colorColB = rand()%(255-0) +0;
        for (int col=0; col<imY; col++) {
            //_myImage.setPixel( line, col, qRgb(colorColR, colorColV, colorColB) );
            _myImage.setPixel( line, col, qRgb(rand()%(255-0) +0, rand()%(255-0) +0, rand()%(255-0) +0) );
        }
    }
    */

    _myImage = _myImage.scaled(sizeX, sizeY);

    QGraphicsScene *graphic = new QGraphicsScene( this );
    graphic->addPixmap( QPixmap::fromImage( _myImage ) );

    _myGV->setScene(graphic);

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogPixel::ouvrir_dialogueSave()
{
    qDebug() << __FUNCTION__ << endl;

}

/*************************  SIGNAUX *******************************************/


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

    QStringList liste = nomFichier.split(".");
    QString extFichier = liste[liste.size()-1];
    qDebug() << "extFichier = " << extFichier;
    char *validFormat;

    if (QString::compare(extFichier, "jpeg") == 0) {
        validFormat = strdup("JPEG");
    }
    else if (QString::compare(extFichier, "jpg") == 0 ) {
        validFormat = strdup("JPG");
    }
    else if (QString::compare(extFichier, "bmp") == 0 ) {
        validFormat = strdup("BMP");
    }
    else {
        validFormat = strdup("PNG");
    }


    if (_myImage.save(cheminFichier, validFormat)) { // writes image into ba in PNG format
        QMessageBox::information(this, "Fichier", nomFichier + " enregistrée\n");
    }
    else {
        QMessageBox::information(this, "Fichier", "Erreur à l'enregistrement\n");
    }


    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


void DialogPixel::on_Resolution()
{
    if (_myRB360->isChecked()) {
        sizeX = 360;    sizeY = 240;
    }
    else if (_myRB480->isChecked()) {
        sizeX = 480;    sizeY = 300;
    }
    else if (_myRB720->isChecked()) {
        sizeX = 720;    sizeY = 480;
    }
    else if (_myRB1080->isChecked()) {
        sizeX = 1080;    sizeY = 720;
    }
    create_image(sizeX, sizeY);
}
























