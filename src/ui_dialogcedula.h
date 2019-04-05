/********************************************************************************
** Form generated from reading UI file 'dialogcedula.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCEDULA_H
#define UI_DIALOGCEDULA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCedula
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *DialogCedula)
    {
        if (DialogCedula->objectName().isEmpty())
            DialogCedula->setObjectName(QStringLiteral("DialogCedula"));
        DialogCedula->resize(462, 130);
        horizontalLayout = new QHBoxLayout(DialogCedula);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(DialogCedula);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, commandLinkButton);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(DialogCedula);

        QMetaObject::connectSlotsByName(DialogCedula);
    } // setupUi

    void retranslateUi(QDialog *DialogCedula)
    {
        DialogCedula->setWindowTitle(QApplication::translate("DialogCedula", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogCedula", "Introducir Documento de Identidad del Paciente ", Q_NULLPTR));
        label->setText(QApplication::translate("DialogCedula", "Cedula", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogCedula", "CONTINUAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCedula: public Ui_DialogCedula {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCEDULA_H
