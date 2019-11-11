#include "dialogtrier.h"
#include <QDebug>

DialogTrier::DialogTrier(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    // Tri croissant activé par défaut
    _ordreTri = 0;  // Croissant

    connect(_myRBCroissant, SIGNAL(clicked()), this, SLOT(on_check_button_radio()));
    connect(_myRBDecroissant, SIGNAL(clicked()), this, SLOT(on_check_button_radio()));
}

int DialogTrier::ordre_tri()
{
    return _ordreTri;
}

void DialogTrier::on_check_button_radio()
{
    if (_myRBDecroissant->isChecked())
        _ordreTri=1;
    else
        _ordreTri=0;
}
