/********************************************************************************
** Form generated from reading UI file 'dialogcolorier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCOLORIER_H
#define UI_DIALOGCOLORIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogColorier
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *_myPBAllHasard;
    QTableView *_myColonneView;
    QPushButton *_myPBAllReinit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *_myLabelError;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLabel *_myLOldColor;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *_myLNewColor;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *myPushButtonAppliquer;
    QPushButton *myPushButtonAleatoire;
    QSpacerItem *verticalSpacer_4;
    QPushButton *myPushButtonReinit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QSlider *myHorizontalSliderBleu;
    QSlider *myHorizontalSliderRouge;
    QLabel *label;
    QLabel *label_3;
    QSlider *myHorizontalSliderVert;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogColorier)
    {
        if (DialogColorier->objectName().isEmpty())
            DialogColorier->setObjectName(QStringLiteral("DialogColorier"));
        DialogColorier->resize(917, 477);
        verticalLayout_8 = new QVBoxLayout(DialogColorier);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        _myPBAllHasard = new QPushButton(DialogColorier);
        _myPBAllHasard->setObjectName(QStringLiteral("_myPBAllHasard"));
        _myPBAllHasard->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(_myPBAllHasard);

        _myColonneView = new QTableView(DialogColorier);
        _myColonneView->setObjectName(QStringLiteral("_myColonneView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_myColonneView->sizePolicy().hasHeightForWidth());
        _myColonneView->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(_myColonneView);

        _myPBAllReinit = new QPushButton(DialogColorier);
        _myPBAllReinit->setObjectName(QStringLiteral("_myPBAllReinit"));
        _myPBAllReinit->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(_myPBAllReinit);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        _myLabelError = new QLabel(DialogColorier);
        _myLabelError->setObjectName(QStringLiteral("_myLabelError"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_myLabelError->sizePolicy().hasHeightForWidth());
        _myLabelError->setSizePolicy(sizePolicy1);
        _myLabelError->setMinimumSize(QSize(0, 40));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 51, 51, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 179, 179, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 115, 115, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 25, 25, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 34, 34, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(164, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        QBrush brush9(QColor(255, 153, 153, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        _myLabelError->setPalette(palette);
        _myLabelError->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(_myLabelError);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(DialogColorier);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        _myLOldColor = new QLabel(DialogColorier);
        _myLOldColor->setObjectName(QStringLiteral("_myLOldColor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_myLOldColor->sizePolicy().hasHeightForWidth());
        _myLOldColor->setSizePolicy(sizePolicy2);
        _myLOldColor->setMinimumSize(QSize(50, 50));
        _myLOldColor->setLayoutDirection(Qt::LeftToRight);
        _myLOldColor->setAutoFillBackground(true);
        _myLOldColor->setTextFormat(Qt::AutoText);
        _myLOldColor->setScaledContents(false);
        _myLOldColor->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(_myLOldColor);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(DialogColorier);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        _myLNewColor = new QLabel(DialogColorier);
        _myLNewColor->setObjectName(QStringLiteral("_myLNewColor"));
        sizePolicy2.setHeightForWidth(_myLNewColor->sizePolicy().hasHeightForWidth());
        _myLNewColor->setSizePolicy(sizePolicy2);
        _myLNewColor->setMinimumSize(QSize(50, 50));
        _myLNewColor->setAutoFillBackground(true);
        _myLNewColor->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(_myLNewColor);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        myPushButtonAppliquer = new QPushButton(DialogColorier);
        myPushButtonAppliquer->setObjectName(QStringLiteral("myPushButtonAppliquer"));
        myPushButtonAppliquer->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(myPushButtonAppliquer);

        myPushButtonAleatoire = new QPushButton(DialogColorier);
        myPushButtonAleatoire->setObjectName(QStringLiteral("myPushButtonAleatoire"));
        myPushButtonAleatoire->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(myPushButtonAleatoire);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        myPushButtonReinit = new QPushButton(DialogColorier);
        myPushButtonReinit->setObjectName(QStringLiteral("myPushButtonReinit"));
        myPushButtonReinit->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(myPushButtonReinit);


        verticalLayout_7->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(DialogColorier);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        myHorizontalSliderBleu = new QSlider(DialogColorier);
        myHorizontalSliderBleu->setObjectName(QStringLiteral("myHorizontalSliderBleu"));
        myHorizontalSliderBleu->setMinimumSize(QSize(50, 0));
        myHorizontalSliderBleu->setCursor(QCursor(Qt::PointingHandCursor));
        myHorizontalSliderBleu->setMaximum(255);
        myHorizontalSliderBleu->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(myHorizontalSliderBleu, 2, 1, 1, 1);

        myHorizontalSliderRouge = new QSlider(DialogColorier);
        myHorizontalSliderRouge->setObjectName(QStringLiteral("myHorizontalSliderRouge"));
        myHorizontalSliderRouge->setMinimumSize(QSize(50, 0));
        myHorizontalSliderRouge->setCursor(QCursor(Qt::PointingHandCursor));
        myHorizontalSliderRouge->setMaximum(255);
        myHorizontalSliderRouge->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(myHorizontalSliderRouge, 0, 1, 1, 1);

        label = new QLabel(DialogColorier);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DialogColorier);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        myHorizontalSliderVert = new QSlider(DialogColorier);
        myHorizontalSliderVert->setObjectName(QStringLiteral("myHorizontalSliderVert"));
        myHorizontalSliderVert->setMinimumSize(QSize(50, 0));
        myHorizontalSliderVert->setCursor(QCursor(Qt::PointingHandCursor));
        myHorizontalSliderVert->setMaximum(255);
        myHorizontalSliderVert->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(myHorizontalSliderVert, 1, 1, 1, 1);

        label_6 = new QLabel(DialogColorier);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_4 = new QLabel(DialogColorier);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(DialogColorier);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(DialogColorier);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_8->addWidget(buttonBox);


        retranslateUi(DialogColorier);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogColorier, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogColorier, SLOT(reject()));
        QObject::connect(myHorizontalSliderRouge, SIGNAL(valueChanged(int)), label_4, SLOT(setNum(int)));
        QObject::connect(myHorizontalSliderVert, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));
        QObject::connect(myHorizontalSliderBleu, SIGNAL(valueChanged(int)), label_6, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(DialogColorier);
    } // setupUi

    void retranslateUi(QDialog *DialogColorier)
    {
        DialogColorier->setWindowTitle(QApplication::translate("DialogColorier", "Colorier", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        _myPBAllHasard->setToolTip(QApplication::translate("DialogColorier", "<html><head/><body><p>Remplit al\303\251atoirement tout e la colonne</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        _myPBAllHasard->setText(QApplication::translate("DialogColorier", "Remplir Colonne", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        _myPBAllReinit->setToolTip(QApplication::translate("DialogColorier", "<html><head/><body><p>R\303\251initialise toue la colonne</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        _myPBAllReinit->setText(QApplication::translate("DialogColorier", "R\303\251initialiser Colonne", Q_NULLPTR));
        _myLabelError->setText(QString());
        label_7->setText(QApplication::translate("DialogColorier", "Actuelle", Q_NULLPTR));
        _myLOldColor->setText(QString());
        label_8->setText(QApplication::translate("DialogColorier", "Nouvelle", Q_NULLPTR));
        _myLNewColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        myPushButtonAppliquer->setToolTip(QApplication::translate("DialogColorier", "<html><head/><body><p>Appliquer la nouvelle couleur dans la case</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        myPushButtonAppliquer->setText(QApplication::translate("DialogColorier", "Appliquer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        myPushButtonAleatoire->setToolTip(QApplication::translate("DialogColorier", "<html><head/><body><p>Propose une couleur al\303\251atoire</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        myPushButtonAleatoire->setText(QApplication::translate("DialogColorier", "Al\303\251atoire", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        myPushButtonReinit->setToolTip(QApplication::translate("DialogColorier", "<html><head/><body><p>R\303\251initialise la couleur de la case</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        myPushButtonReinit->setText(QApplication::translate("DialogColorier", "R\303\251initialiser case", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogColorier", "0", Q_NULLPTR));
        label->setText(QApplication::translate("DialogColorier", "Rouge", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogColorier", "Bleu", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogColorier", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogColorier", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogColorier", "Vert", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogColorier: public Ui_DialogColorier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCOLORIER_H
