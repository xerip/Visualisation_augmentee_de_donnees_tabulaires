/********************************************************************************
** Form generated from reading UI file 'dialogtrier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTRIER_H
#define UI_DIALOGTRIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTrier
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QRadioButton *_myRBCroissant;
    QRadioButton *_myRBDecroissant;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogTrier)
    {
        if (DialogTrier->objectName().isEmpty())
            DialogTrier->setObjectName(QStringLiteral("DialogTrier"));
        DialogTrier->resize(291, 224);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogTrier->sizePolicy().hasHeightForWidth());
        DialogTrier->setSizePolicy(sizePolicy);
        DialogTrier->setMinimumSize(QSize(100, 100));
        verticalLayout_3 = new QVBoxLayout(DialogTrier);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        _myRBCroissant = new QRadioButton(DialogTrier);
        _myRBCroissant->setObjectName(QStringLiteral("_myRBCroissant"));
        _myRBCroissant->setChecked(true);

        verticalLayout->addWidget(_myRBCroissant);

        _myRBDecroissant = new QRadioButton(DialogTrier);
        _myRBDecroissant->setObjectName(QStringLiteral("_myRBDecroissant"));

        verticalLayout->addWidget(_myRBDecroissant);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(DialogTrier);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(DialogTrier);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTrier, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTrier, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTrier);
    } // setupUi

    void retranslateUi(QDialog *DialogTrier)
    {
        DialogTrier->setWindowTitle(QApplication::translate("DialogTrier", "Dialog", Q_NULLPTR));
        _myRBCroissant->setText(QApplication::translate("DialogTrier", "Croissant", Q_NULLPTR));
        _myRBDecroissant->setText(QApplication::translate("DialogTrier", "D\303\251croissant", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTrier: public Ui_DialogTrier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTRIER_H
