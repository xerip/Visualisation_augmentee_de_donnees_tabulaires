/********************************************************************************
** Form generated from reading UI file 'dialoggenerer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGENERER_H
#define UI_DIALOGGENERER_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogGenerer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *_mySpinBoxRow;
    QLabel *label;
    QSpinBox *_mySpinBoxCol;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogGenerer)
    {
        if (DialogGenerer->objectName().isEmpty())
            DialogGenerer->setObjectName(QStringLiteral("DialogGenerer"));
        DialogGenerer->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogGenerer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(DialogGenerer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        _mySpinBoxRow = new QSpinBox(DialogGenerer);
        _mySpinBoxRow->setObjectName(QStringLiteral("_mySpinBoxRow"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_mySpinBoxRow->sizePolicy().hasHeightForWidth());
        _mySpinBoxRow->setSizePolicy(sizePolicy);
        _mySpinBoxRow->setAlignment(Qt::AlignCenter);
        _mySpinBoxRow->setMinimum(1);
        _mySpinBoxRow->setMaximum(15624);
        _mySpinBoxRow->setValue(10);

        gridLayout->addWidget(_mySpinBoxRow, 0, 1, 1, 1);

        label = new QLabel(DialogGenerer);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        _mySpinBoxCol = new QSpinBox(DialogGenerer);
        _mySpinBoxCol->setObjectName(QStringLiteral("_mySpinBoxCol"));
        sizePolicy.setHeightForWidth(_mySpinBoxCol->sizePolicy().hasHeightForWidth());
        _mySpinBoxCol->setSizePolicy(sizePolicy);
        _mySpinBoxCol->setAlignment(Qt::AlignCenter);
        _mySpinBoxCol->setMinimum(1);
        _mySpinBoxCol->setMaximum(15624);
        _mySpinBoxCol->setValue(10);

        gridLayout->addWidget(_mySpinBoxCol, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DialogGenerer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogGenerer);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogGenerer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogGenerer, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogGenerer);
    } // setupUi

    void retranslateUi(QDialog *DialogGenerer)
    {
        DialogGenerer->setWindowTitle(QApplication::translate("DialogGenerer", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogGenerer", "<html><head/><body><p><span style=\" font-size:14pt;\">Nombre lignes</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("DialogGenerer", "<html><head/><body><p><span style=\" font-size:14pt;\">Nombre colonnes</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogGenerer: public Ui_DialogGenerer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGENERER_H
