#include "mainwindow_projet.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_projet w;
    w.show();

    return a.exec();
}
