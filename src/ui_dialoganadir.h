/********************************************************************************
** Form generated from reading UI file 'dialoganadir.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGANADIR_H
#define UI_DIALOGANADIR_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogAnadir
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEditNombres;
    QLineEdit *lineEditApellidos;
    QLineEdit *lineEditLugarNacimiento;
    QLineEdit *lineEditEPS;
    QLabel *label_6;
    QLineEdit *lineEditCedula;
    QLabel *label_8;
    QLineEdit *lineEditRFID;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *DialogAnadir)
    {
        if (DialogAnadir->objectName().isEmpty())
            DialogAnadir->setObjectName(QStringLiteral("DialogAnadir"));
        DialogAnadir->resize(563, 309);
        horizontalLayout_2 = new QHBoxLayout(DialogAnadir);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DialogAnadir);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(DialogAnadir);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(DialogAnadir);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_3 = new QLabel(DialogAnadir);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_5 = new QLabel(DialogAnadir);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_7 = new QLabel(DialogAnadir);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_2 = new QRadioButton(DialogAnadir);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(false);

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(DialogAnadir);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(false);

        horizontalLayout->addWidget(radioButton);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout);

        dateTimeEdit = new QDateTimeEdit(DialogAnadir);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setDate(QDate(1996, 2, 21));
        dateTimeEdit->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, dateTimeEdit);

        lineEditNombres = new QLineEdit(DialogAnadir);
        lineEditNombres->setObjectName(QStringLiteral("lineEditNombres"));
        lineEditNombres->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditNombres);

        lineEditApellidos = new QLineEdit(DialogAnadir);
        lineEditApellidos->setObjectName(QStringLiteral("lineEditApellidos"));
        lineEditApellidos->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditApellidos);

        lineEditLugarNacimiento = new QLineEdit(DialogAnadir);
        lineEditLugarNacimiento->setObjectName(QStringLiteral("lineEditLugarNacimiento"));
        lineEditLugarNacimiento->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditLugarNacimiento);

        lineEditEPS = new QLineEdit(DialogAnadir);
        lineEditEPS->setObjectName(QStringLiteral("lineEditEPS"));
        lineEditEPS->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditEPS);

        label_6 = new QLabel(DialogAnadir);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEditCedula = new QLineEdit(DialogAnadir);
        lineEditCedula->setObjectName(QStringLiteral("lineEditCedula"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditCedula);

        label_8 = new QLabel(DialogAnadir);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        lineEditRFID = new QLineEdit(DialogAnadir);
        lineEditRFID->setObjectName(QStringLiteral("lineEditRFID"));
        lineEditRFID->setEnabled(true);
        lineEditRFID->setReadOnly(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditRFID);

        commandLinkButton = new QCommandLinkButton(DialogAnadir);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setEnabled(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, commandLinkButton);


        horizontalLayout_2->addLayout(formLayout);

        QWidget::setTabOrder(lineEditCedula, lineEditNombres);
        QWidget::setTabOrder(lineEditNombres, lineEditApellidos);
        QWidget::setTabOrder(lineEditApellidos, lineEditLugarNacimiento);
        QWidget::setTabOrder(lineEditLugarNacimiento, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, radioButton);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, lineEditEPS);
        QWidget::setTabOrder(lineEditEPS, lineEditRFID);
        QWidget::setTabOrder(lineEditRFID, commandLinkButton);

        retranslateUi(DialogAnadir);

        QMetaObject::connectSlotsByName(DialogAnadir);
    } // setupUi

    void retranslateUi(QDialog *DialogAnadir)
    {
        DialogAnadir->setWindowTitle(QApplication::translate("DialogAnadir", "Datos Personales Paciente", Q_NULLPTR));
        label->setText(QApplication::translate("DialogAnadir", "Nombres", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogAnadir", "Apellidos", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogAnadir", "Fecha de Nacimiento", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogAnadir", "Lugar de Nacimiento", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogAnadir", "Sexo", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogAnadir", "EPS", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("DialogAnadir", "Femenino", Q_NULLPTR));
        radioButton->setText(QApplication::translate("DialogAnadir", "Masculino", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("DialogAnadir", "d/MM/yy", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogAnadir", "Cedula", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogAnadir", "RFID", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogAnadir", "Continuar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogAnadir: public Ui_DialogAnadir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGANADIR_H
