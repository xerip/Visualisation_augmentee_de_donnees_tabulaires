#include "dialoggenerer.h"

#include <QDebug>

DialogGenerer::DialogGenerer(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect ( _mySpinBoxCol, SIGNAL(valueChanged(int)), this, SLOT(on_choix_dimensions(int)) );
    connect ( _mySpinBoxRow, SIGNAL(valueChanged(int)), this, SLOT(on_choix_dimensions(int)) );
}

int DialogGenerer::nb_col()
{
    return _nbCol;
}

int DialogGenerer::nb_row()
{
    return _nbRow;
}

void DialogGenerer::on_choix_dimensions(int value)
{
    if (sender()->objectName() == "_mySpinBoxCol") {
        _nbCol = value;
    }
    else if (sender()->objectName() == "_mySpinBoxRow") {
        _nbRow = value;
    }
}
