#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T11:36:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visualisation_augmentee1.5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow_projet.cpp \
    dialogtrier.cpp \
    dialogcolorier.cpp \
    dialogpixel.cpp \
    dialoghelp.cpp \
    dialoggenerer.cpp

HEADERS += \
        mainwindow_projet.h \
    dialogtrier.h \
    dialogcolorier.h \
    dialogpixel.h \
    dialoghelp.h \
    dialoggenerer.h

FORMS += \
        mainwindow_projet.ui \
    dialogtrier.ui \
    dialogcolorier.ui \
    dialogpixel.ui \
    dialoghelp.ui \
    dialoggenerer.ui
