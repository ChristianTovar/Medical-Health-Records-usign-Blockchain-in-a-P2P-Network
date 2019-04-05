/********************************************************************************
** Form generated from reading UI file 'dialogeditarprofesional.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITARPROFESIONAL_H
#define UI_DIALOGEDITARPROFESIONAL_H

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

class Ui_DialogEditarProfesional
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_nombre;
    QLineEdit *lineEdit_ips;
    QLineEdit *lineEdit_tarjeta;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;

    void setupUi(QDialog *DialogEditarProfesional)
    {
        if (DialogEditarProfesional->objectName().isEmpty())
            DialogEditarProfesional->setObjectName(QStringLiteral("DialogEditarProfesional"));
        DialogEditarProfesional->resize(559, 233);
        verticalLayout = new QVBoxLayout(DialogEditarProfesional);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DialogEditarProfesional);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_nombre = new QLineEdit(groupBox);
        lineEdit_nombre->setObjectName(QStringLiteral("lineEdit_nombre"));
        lineEdit_nombre->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_nombre);

        lineEdit_ips = new QLineEdit(groupBox);
        lineEdit_ips->setObjectName(QStringLiteral("lineEdit_ips"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_ips);

        lineEdit_tarjeta = new QLineEdit(groupBox);
        lineEdit_tarjeta->setObjectName(QStringLiteral("lineEdit_tarjeta"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_tarjeta);


        verticalLayout_2->addLayout(formLayout);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        verticalLayout_2->addWidget(commandLinkButton);

        commandLinkButton_2 = new QCommandLinkButton(groupBox);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));

        verticalLayout_2->addWidget(commandLinkButton_2);


        verticalLayout->addWidget(groupBox);


        retranslateUi(DialogEditarProfesional);

        QMetaObject::connectSlotsByName(DialogEditarProfesional);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarProfesional)
    {
        DialogEditarProfesional->setWindowTitle(QApplication::translate("DialogEditarProfesional", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogEditarProfesional", "Informacion Profesional", Q_NULLPTR));
        label->setText(QApplication::translate("DialogEditarProfesional", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogEditarProfesional", "IPS", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogEditarProfesional", "Tarjeta  Profesional", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogEditarProfesional", "Editar Dispositivo RFID", Q_NULLPTR));
        commandLinkButton_2->setText(QApplication::translate("DialogEditarProfesional", "Continuar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarProfesional: public Ui_DialogEditarProfesional {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARPROFESIONAL_H
