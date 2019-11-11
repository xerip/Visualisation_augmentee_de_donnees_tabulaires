/********************************************************************************
** Form generated from reading UI file 'dialogpixel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPIXEL_H
#define UI_DIALOGPIXEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPixel
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *_myRB360;
    QRadioButton *_myRB480;
    QRadioButton *_myRB720;
    QRadioButton *_myRB1080;
    QSpacerItem *verticalSpacer_2;
    QGraphicsView *_myGV;
    QDialogButtonBox *_myBBSave;

    void setupUi(QDialog *DialogPixel)
    {
        if (DialogPixel->objectName().isEmpty())
            DialogPixel->setObjectName(QStringLiteral("DialogPixel"));
        DialogPixel->resize(726, 545);
        verticalLayout_2 = new QVBoxLayout(DialogPixel);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogPixel);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(50, 50));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        _myRB360 = new QRadioButton(DialogPixel);
        _myRB360->setObjectName(QStringLiteral("_myRB360"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_myRB360->sizePolicy().hasHeightForWidth());
        _myRB360->setSizePolicy(sizePolicy1);
        _myRB360->setChecked(true);

        verticalLayout->addWidget(_myRB360);

        _myRB480 = new QRadioButton(DialogPixel);
        _myRB480->setObjectName(QStringLiteral("_myRB480"));
        sizePolicy1.setHeightForWidth(_myRB480->sizePolicy().hasHeightForWidth());
        _myRB480->setSizePolicy(sizePolicy1);
        _myRB480->setChecked(false);

        verticalLayout->addWidget(_myRB480);

        _myRB720 = new QRadioButton(DialogPixel);
        _myRB720->setObjectName(QStringLiteral("_myRB720"));
        sizePolicy1.setHeightForWidth(_myRB720->sizePolicy().hasHeightForWidth());
        _myRB720->setSizePolicy(sizePolicy1);
        _myRB720->setChecked(false);

        verticalLayout->addWidget(_myRB720);

        _myRB1080 = new QRadioButton(DialogPixel);
        _myRB1080->setObjectName(QStringLiteral("_myRB1080"));
        sizePolicy1.setHeightForWidth(_myRB1080->sizePolicy().hasHeightForWidth());
        _myRB1080->setSizePolicy(sizePolicy1);
        _myRB1080->setChecked(false);

        verticalLayout->addWidget(_myRB1080);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        _myGV = new QGraphicsView(DialogPixel);
        _myGV->setObjectName(QStringLiteral("_myGV"));
        _myGV->setMinimumSize(QSize(400, 400));
        _myGV->setMaximumSize(QSize(1280, 720));

        horizontalLayout->addWidget(_myGV);


        verticalLayout_2->addLayout(horizontalLayout);

        _myBBSave = new QDialogButtonBox(DialogPixel);
        _myBBSave->setObjectName(QStringLiteral("_myBBSave"));
        _myBBSave->setOrientation(Qt::Horizontal);
        _myBBSave->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(_myBBSave);


        retranslateUi(DialogPixel);
        QObject::connect(_myBBSave, SIGNAL(accepted()), DialogPixel, SLOT(accept()));
        QObject::connect(_myBBSave, SIGNAL(rejected()), DialogPixel, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPixel);
    } // setupUi

    void retranslateUi(QDialog *DialogPixel)
    {
        DialogPixel->setWindowTitle(QApplication::translate("DialogPixel", "Visualisation augment\303\251e", Q_NULLPTR));
        label->setText(QApplication::translate("DialogPixel", "R\303\251solution", Q_NULLPTR));
        _myRB360->setText(QApplication::translate("DialogPixel", "360 \303\227 240 ", Q_NULLPTR));
        _myRB480->setText(QApplication::translate("DialogPixel", "480 \303\227 300", Q_NULLPTR));
        _myRB720->setText(QApplication::translate("DialogPixel", "720 \303\227 480", Q_NULLPTR));
        _myRB1080->setText(QApplication::translate("DialogPixel", "1 080 \303\227 720", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPixel: public Ui_DialogPixel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPIXEL_H
