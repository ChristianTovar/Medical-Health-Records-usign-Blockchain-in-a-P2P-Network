/********************************************************************************
** Form generated from reading UI file 'dialogespera.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGESPERA_H
#define UI_DIALOGESPERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEspera
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *DialogEspera)
    {
        if (DialogEspera->objectName().isEmpty())
            DialogEspera->setObjectName(QStringLiteral("DialogEspera"));
        DialogEspera->resize(600, 300);
        verticalLayout = new QVBoxLayout(DialogEspera);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogEspera);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(DialogEspera);

        QMetaObject::connectSlotsByName(DialogEspera);
    } // setupUi

    void retranslateUi(QDialog *DialogEspera)
    {
        DialogEspera->setWindowTitle(QApplication::translate("DialogEspera", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogEspera", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEspera: public Ui_DialogEspera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGESPERA_H
