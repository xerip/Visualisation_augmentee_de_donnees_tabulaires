/********************************************************************************
** Form generated from reading UI file 'mainwindow_projet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
    QAction *actionGenererAl;
    QAction *actionTrier;
    QAction *actionColorier;
    QAction *actionValider;
    QAction *actionA_propos;
    QWidget *myCentralWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QTableView *_myTableView;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *myPBTrier;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *myPBColorier;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *_myPBValider;
    QMenuBar *myMenuBar;
    QMenu *myMenuFichier;
    QMenu *menuEdition;
    QMenu *menuAide;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow_projet)
    {
        if (MainWindow_projet->objectName().isEmpty())
            MainWindow_projet->setObjectName(QStringLiteral("MainWindow_projet"));
        MainWindow_projet->resize(1101, 632);
        MainWindow_projet->setMinimumSize(QSize(400, 300));
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
        actionGenererAl = new QAction(MainWindow_projet);
        actionGenererAl->setObjectName(QStringLiteral("actionGenererAl"));
        actionTrier = new QAction(MainWindow_projet);
        actionTrier->setObjectName(QStringLiteral("actionTrier"));
        actionTrier->setEnabled(false);
        actionColorier = new QAction(MainWindow_projet);
        actionColorier->setObjectName(QStringLiteral("actionColorier"));
        actionColorier->setEnabled(false);
        actionValider = new QAction(MainWindow_projet);
        actionValider->setObjectName(QStringLiteral("actionValider"));
        actionValider->setEnabled(false);
        actionA_propos = new QAction(MainWindow_projet);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        myCentralWidget = new QWidget(MainWindow_projet);
        myCentralWidget->setObjectName(QStringLiteral("myCentralWidget"));
        verticalLayout_2 = new QVBoxLayout(myCentralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout_2->addLayout(verticalLayout);

        _myTableView = new QTableView(myCentralWidget);
        _myTableView->setObjectName(QStringLiteral("_myTableView"));
        _myTableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        _myTableView->setMouseTracking(true);
        _myTableView->setAcceptDrops(true);
        _myTableView->setToolTipDuration(5);
        _myTableView->setAutoFillBackground(true);
        _myTableView->setDragEnabled(false);
        _myTableView->setDragDropMode(QAbstractItemView::DragDrop);
        _myTableView->setDefaultDropAction(Qt::LinkAction);
        _myTableView->setSortingEnabled(false);

        horizontalLayout_2->addWidget(_myTableView);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        myPBTrier = new QPushButton(myCentralWidget);
        myPBTrier->setObjectName(QStringLiteral("myPBTrier"));
        myPBTrier->setEnabled(false);
        myPBTrier->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(myPBTrier);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        myPBColorier = new QPushButton(myCentralWidget);
        myPBColorier->setObjectName(QStringLiteral("myPBColorier"));
        myPBColorier->setEnabled(false);
        myPBColorier->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(myPBColorier);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        _myPBValider = new QPushButton(myCentralWidget);
        _myPBValider->setObjectName(QStringLiteral("_myPBValider"));
        _myPBValider->setEnabled(false);
        _myPBValider->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(_myPBValider);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow_projet->setCentralWidget(myCentralWidget);
        myMenuBar = new QMenuBar(MainWindow_projet);
        myMenuBar->setObjectName(QStringLiteral("myMenuBar"));
        myMenuBar->setGeometry(QRect(0, 0, 1101, 22));
        myMenuFichier = new QMenu(myMenuBar);
        myMenuFichier->setObjectName(QStringLiteral("myMenuFichier"));
        menuEdition = new QMenu(myMenuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        menuAide = new QMenu(myMenuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow_projet->setMenuBar(myMenuBar);
        mainToolBar = new QToolBar(MainWindow_projet);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow_projet->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow_projet);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow_projet->setStatusBar(statusBar);

        myMenuBar->addAction(myMenuFichier->menuAction());
        myMenuBar->addAction(menuEdition->menuAction());
        myMenuBar->addAction(menuAide->menuAction());
        myMenuFichier->addAction(actionImporter);
        myMenuFichier->addAction(actionGenererAl);
        myMenuFichier->addSeparator();
        myMenuFichier->addAction(actionQuitter);
        menuEdition->addSeparator();
        menuEdition->addAction(actionTrier);
        menuEdition->addAction(actionColorier);
        menuEdition->addAction(actionValider);
        menuAide->addAction(actionA_propos);

        retranslateUi(MainWindow_projet);
        QObject::connect(myPBTrier, SIGNAL(pressed()), MainWindow_projet, SLOT(show()));

        QMetaObject::connectSlotsByName(MainWindow_projet);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_projet)
    {
        MainWindow_projet->setWindowTitle(QApplication::translate("MainWindow_projet", "Visualizator", Q_NULLPTR));
        action_importer->setText(QApplication::translate("MainWindow_projet", "Importer", Q_NULLPTR));
        action_generer->setText(QApplication::translate("MainWindow_projet", "G\303\251n\303\251rer", Q_NULLPTR));
        actionFermer->setText(QApplication::translate("MainWindow_projet", "Fermer", Q_NULLPTR));
        actionImporter->setText(QApplication::translate("MainWindow_projet", "Importer...", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow_projet", "Quitter", Q_NULLPTR));
        actionGenererAl->setText(QApplication::translate("MainWindow_projet", "G\303\251n\303\251rer al\303\251atoirement", Q_NULLPTR));
        actionTrier->setText(QApplication::translate("MainWindow_projet", "Trier...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionTrier->setToolTip(QApplication::translate("MainWindow_projet", "Trier la colonne courante", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionTrier->setWhatsThis(QApplication::translate("MainWindow_projet", "Trier la colonne courante", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        actionColorier->setText(QApplication::translate("MainWindow_projet", "Colorier...", Q_NULLPTR));
        actionValider->setText(QApplication::translate("MainWindow_projet", "Valider...", Q_NULLPTR));
        actionA_propos->setText(QApplication::translate("MainWindow_projet", "A propos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        _myTableView->setToolTip(QApplication::translate("MainWindow_projet", "Helloooooo!", "fdfdfd"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        _myTableView->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        _myTableView->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        _myTableView->setAccessibleName(QApplication::translate("MainWindow_projet", "koko", "kaka"));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        _myTableView->setAccessibleDescription(QApplication::translate("MainWindow_projet", "lop", "poooop"));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        myPBTrier->setToolTip(QApplication::translate("MainWindow_projet", "<html><head/><body><p>Trier la colonne courante</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        myPBTrier->setText(QApplication::translate("MainWindow_projet", "Trier", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        myPBColorier->setToolTip(QApplication::translate("MainWindow_projet", "<html><head/><body><p>Colorier la colonne courante</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        myPBColorier->setText(QApplication::translate("MainWindow_projet", "Colorier", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        _myPBValider->setToolTip(QApplication::translate("MainWindow_projet", "<html><head/><body><p>Transforme le tabmeau en image</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        _myPBValider->setText(QApplication::translate("MainWindow_projet", "Transformer", Q_NULLPTR));
        myMenuFichier->setTitle(QApplication::translate("MainWindow_projet", "Fichier", Q_NULLPTR));
        menuEdition->setTitle(QApplication::translate("MainWindow_projet", "\303\211dition", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow_projet", "Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_projet: public Ui_MainWindow_projet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_PROJET_H
