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
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    if (sender()->objectName() == "_mySpinBoxCol") {
        _nbCol = value;
        qDebug() << "_nbCol = " << _nbCol;
    }
    else if (sender()->objectName() == "_mySpinBoxRow") {
        _nbRow = value;
        qDebug() << "_nbRow = " << _nbRow;
    }
}
