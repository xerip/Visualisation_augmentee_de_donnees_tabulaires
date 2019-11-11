#include "dialogcolorier.h"

#include <QDebug>
#include <QColor>   // Utilisation de la classe QColor
#include <QPalette> // Utilisation de la classe QPalette pour le changement de couleur


DialogColorier::DialogColorier(QWidget *parent, QStandardItemModel *_model) :
    QDialog(parent)
{
    setupUi(this);

    this->_model = _model;

    //this->_model = _model;

    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                couleurUtilises[r][v][b] = 0;
            }
        }
    }

    _myColonneView->setModel(_model);
    //_myColonneView->show();
    _myColonneView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //_myColonneView->setSelectionBehavior(QAbstractItemView::SelectColumns);

    connect(myHorizontalSliderRouge, &QSlider::valueChanged, this, &DialogColorier::on_colorChanged );
    connect( myHorizontalSliderVert, SIGNAL( valueChanged(int)), this, SLOT( on_colorChanged()) );
    connect( myHorizontalSliderBleu, SIGNAL( valueChanged(int)), this, SLOT( on_colorChanged()) );

    connect(myPushButtonReinit, SIGNAL(pressed()), this, SLOT(on_reinitColor()));
    connect(myPushButtonAleatoire, SIGNAL(pressed()), this, SLOT(on_colorAleatoire()));
    connect(myPushButtonAppliquer, SIGNAL(pressed()), this, SLOT(on_valid_color()));

    // TEST
    connect(_myColonneView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_testPaint(QModelIndex)));
}


QStandardItemModel *DialogColorier::model()
{
    return _model;
}

void DialogColorier::on_colorChanged()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    // Définition et construction de la couleur en RVB représentée par les sliders
    QColor color;
    color.setRgb( myHorizontalSliderRouge->value(),
                  myHorizontalSliderVert->value(),
                  myHorizontalSliderBleu->value() );

    qDebug() << "The color is" << color;
    // La couleur est maintenant utilisée pour une couleur de fenêtre
    QPalette pal;
    pal.setColor( QPalette::Window, color );
    myLabelTest->setPalette( pal );
}

void DialogColorier::on_reinitColor()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    // Définition et construction de la couleur en RVB représentée par les sliders
    QColor color;

    int r = myHorizontalSliderRouge->value()/10;
    int v = myHorizontalSliderVert->value()/10;
    int b = myHorizontalSliderBleu->value()/10;
    qDebug() << "r = " << r << "v = " << v << "b = " << b << endl;
    couleurUtilises[r][v][b] = 0;

    color.setRgb( 0, 0, 0 );
    myHorizontalSliderRouge->setValue(0);
    myHorizontalSliderVert->setValue(0);
    myHorizontalSliderBleu->setValue(0);

    QPalette pal;
    // La palette n'est pas initialisée afin de rendre les couleurs d'origine à l'objet où cette fonction s'applique.
    myLabelTest->setPalette( pal );
    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogColorier::on_colorAleatoire()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    if (colors_empty()) {
        // TMP faire un vrai message d'erreur
        qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
        return;
    }

    int r, v, b;
    int i=0;

    do {
        r = rand()%(25-0) +0;
        v = rand()%(25-0) +0;
        b = rand()%(25-0) +0;
        i++;
    }
    while (couleurUtilises[r][v][b]);
    couleurUtilises[r][v][b] = 1;

    qDebug() << "i = " << i << "r = " << r << "v = " << v << "b = " << b << endl;

    myHorizontalSliderRouge->setValue(r*10);
    myHorizontalSliderVert->setValue(v*10);
    myHorizontalSliderBleu->setValue(b*10);

    emit on_colorChanged();

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogColorier::on_valid_color()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    if (colors_empty()) {
        // TMP faire un vrai message d'erreur
        qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
        qDebug() << "</" << __FUNCTION__ << ">" << endl;
        return;
    }

    int r = myHorizontalSliderRouge->value()/10;
    int v = myHorizontalSliderVert->value()/10;
    int b = myHorizontalSliderBleu->value()/10;

    if (couleurUtilises[r][v][b]) {
        // TMP faire un vrai message d'erreur
        qDebug() << "La couleur est déjà utilisée" << endl;
        qDebug() << "</" << __FUNCTION__ << ">" << endl;
        return;
    }

    couleurUtilises[r][v][b] = 1;
    qDebug() << "Ok couleur " << r << v << b << "validée" << endl;

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogColorier::convert_color(int &color_r, int &color_v, int &color_b)
{
    color_r = color_r/10;
    color_v = color_v/10;
    color_b = color_b/10;
}

int DialogColorier::colors_empty()
{
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                if (!couleurUtilises[r][v][b]) return 0;
            }
        }
    }
    return 1;
}


// QTABLEVIEW

void DialogColorier::on_testPaint(QModelIndex _myIndex)
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    QStandardItem *caseTab;
    QColor color;
    color.setRgb( rand()%(250-0) +0,
                  rand()%(250-0) +0,
                  rand()%(250-0) +0 );
    // QBrush brush;
    // brush.setColor( color);

    QString text = QString("coucou");

    QModelIndex modelInd = _model->index(_myIndex.row(),_myIndex.column());

    _model->itemFromIndex(modelInd)->setBackground(QColor (color));
    _model->setData(_myIndex, text);
    /*
    caseTab = _model->takeItem(index.row(), index.column());
    caseTab->setBackground( brush );
    caseTab->setForeground( brush );
    _model->setItem(index.row(), index.column(), caseTab);
    */
}











