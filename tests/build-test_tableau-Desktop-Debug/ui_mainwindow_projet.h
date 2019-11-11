/********************************************************************************
** Form generated from reading UI file 'mainwindow_projet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_PROJET_H
#define UI_MAINWINDOW_PROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_projet
{
public:
    QAction *action_importer;
    QAction *action_generer;
    QAction *actionFermer;
    QAction *actionImporter;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableView *_myTableView;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *myMenuBar;
    QMenu *menuFichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow_projet)
    {
        if (MainWindow_projet->objectName().isEmpty())
            MainWindow_projet->setObjectName(QStringLiteral("MainWindow_projet"));
        MainWindow_projet->resize(593, 340);
        action_importer = new QAction(MainWindow_projet);
        action_importer->setObjectName(QStringLiteral("action_importer"));
        action_importer->setCheckable(false);
        action_generer = new QAction(MainWindow_projet);
        action_generer->setObjectName(QStringLiteral("action_generer"));
        actionFermer = new QAction(MainWindow_projet);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionImporter = new QAction(MainWindow_projet);
        actionImporter->setObjectName(QStringLiteral("actionImporter"));
        actionQuitter = new QAction(MainWindow_projet);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow_projet);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _myTableView = new QTableView(centralWidget);
        _myTableView->setObjectName(QStringLiteral("_myTableView"));

        horizontalLayout->addWidget(_myTableView);

        horizontalSpacer_2 = new QSpacerItem(149, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow_projet->setCentralWidget(centralWidget);
        myMenuBar = new QMenuBar(MainWindow_projet);
        myMenuBar->setObjectName(QStringLiteral("myMenuBar"));
        myMenuBar->setGeometry(QRect(0, 0, 593, 19));
        menuFichier = new QMenu(myMenuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow_projet->setMenuBar(myMenuBar);
        mainToolBar = new QToolBar(MainWindow_projet);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow_projet->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow_projet);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow_projet->setStatusBar(statusBar);

        myMenuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionImporter);
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow_projet);

        QMetaObject::connectSlotsByName(MainWindow_projet);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_projet)
    {
        MainWindow_projet->setWindowTitle(QApplication::translate("MainWindow_projet", "MainWindow_projet", 0));
        action_importer->setText(QApplication::translate("MainWindow_projet", "Importer", 0));
        action_generer->setText(QApplication::translate("MainWindow_projet", "G\303\251n\303\251rer", 0));
        actionFermer->setText(QApplication::translate("MainWindow_projet", "Fermer", 0));
        actionImporter->setText(QApplication::translate("MainWindow_projet", "Importer", 0));
        actionQuitter->setText(QApplication::translate("MainWindow_projet", "Quitter", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow_projet", "<html><head/><body><p>tooltip ningennnn</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("MainWindow_projet", "<html><head/><body><p>ch\303\251 pa moi !</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("MainWindow_projet", "PushButton", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow_projet", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_projet: public Ui_MainWindow_projet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PROJET_H
