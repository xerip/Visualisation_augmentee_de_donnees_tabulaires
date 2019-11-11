#include "dialogtrier.h"
#include <QDebug>

DialogTrier::DialogTrier(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    qDebug () << __FUNCTION__ << " fenetre créée " << endl;
}
