/********************************************************************************
** Form generated from reading UI file 'dialogtarjeta.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTARJETA_H
#define UI_DIALOGTARJETA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTarjeta
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *DialogTarjeta)
    {
        if (DialogTarjeta->objectName().isEmpty())
            DialogTarjeta->setObjectName(QStringLiteral("DialogTarjeta"));
        DialogTarjeta->resize(380, 130);
        verticalLayout = new QVBoxLayout(DialogTarjeta);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DialogTarjeta);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, commandLinkButton);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout->addWidget(groupBox);


        retranslateUi(DialogTarjeta);

        QMetaObject::connectSlotsByName(DialogTarjeta);
    } // setupUi

    void retranslateUi(QDialog *DialogTarjeta)
    {
        DialogTarjeta->setWindowTitle(QApplication::translate("DialogTarjeta", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogTarjeta", "Introducir Documento de Identidad del Paciente ", Q_NULLPTR));
        label->setText(QApplication::translate("DialogTarjeta", "Tarjeta Profesional", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogTarjeta", "CONTINUAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTarjeta: public Ui_DialogTarjeta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTARJETA_H
