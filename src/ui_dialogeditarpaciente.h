/********************************************************************************
** Form generated from reading UI file 'dialogeditarpaciente.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITARPACIENTE_H
#define UI_DIALOGEDITARPACIENTE_H

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

class Ui_DialogEditarPaciente
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_cedula;
    QLabel *label_2;
    QLineEdit *lineEdit_nombres;
    QLabel *label_3;
    QLineEdit *lineEdit_apellidos;
    QLabel *label_4;
    QLineEdit *lineEdit_lugar;
    QLabel *label_5;
    QLineEdit *lineEdit_fecha;
    QLabel *label_6;
    QLineEdit *lineEdit_sexo;
    QLabel *label_7;
    QLineEdit *lineEdit_eps;
    QLabel *label_8;
    QLineEdit *lineEdit_rfid;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;

    void setupUi(QDialog *DialogEditarPaciente)
    {
        if (DialogEditarPaciente->objectName().isEmpty())
            DialogEditarPaciente->setObjectName(QStringLiteral("DialogEditarPaciente"));
        DialogEditarPaciente->resize(594, 388);
        horizontalLayout = new QHBoxLayout(DialogEditarPaciente);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(DialogEditarPaciente);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_cedula = new QLineEdit(groupBox);
        lineEdit_cedula->setObjectName(QStringLiteral("lineEdit_cedula"));
        lineEdit_cedula->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_cedula);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_nombres = new QLineEdit(groupBox);
        lineEdit_nombres->setObjectName(QStringLiteral("lineEdit_nombres"));
        lineEdit_nombres->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_nombres);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_apellidos = new QLineEdit(groupBox);
        lineEdit_apellidos->setObjectName(QStringLiteral("lineEdit_apellidos"));
        lineEdit_apellidos->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_apellidos);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_lugar = new QLineEdit(groupBox);
        lineEdit_lugar->setObjectName(QStringLiteral("lineEdit_lugar"));
        lineEdit_lugar->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_lugar);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_fecha = new QLineEdit(groupBox);
        lineEdit_fecha->setObjectName(QStringLiteral("lineEdit_fecha"));
        lineEdit_fecha->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_fecha);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEdit_sexo = new QLineEdit(groupBox);
        lineEdit_sexo->setObjectName(QStringLiteral("lineEdit_sexo"));
        lineEdit_sexo->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_sexo);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        lineEdit_eps = new QLineEdit(groupBox);
        lineEdit_eps->setObjectName(QStringLiteral("lineEdit_eps"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_eps);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        lineEdit_rfid = new QLineEdit(groupBox);
        lineEdit_rfid->setObjectName(QStringLiteral("lineEdit_rfid"));
        lineEdit_rfid->setReadOnly(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_rfid);


        verticalLayout->addLayout(formLayout);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        verticalLayout->addWidget(commandLinkButton);

        commandLinkButton_2 = new QCommandLinkButton(groupBox);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));

        verticalLayout->addWidget(commandLinkButton_2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(DialogEditarPaciente);

        QMetaObject::connectSlotsByName(DialogEditarPaciente);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarPaciente)
    {
        DialogEditarPaciente->setWindowTitle(QApplication::translate("DialogEditarPaciente", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogEditarPaciente", "Informacion Personal Paciente", Q_NULLPTR));
        label->setText(QApplication::translate("DialogEditarPaciente", "Cedula", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogEditarPaciente", "Nombres", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogEditarPaciente", "Apellidos", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogEditarPaciente", "Lugar de Nacimiento", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogEditarPaciente", "Fecha de Nacimiento", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogEditarPaciente", "Sexo", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogEditarPaciente", "EPS", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogEditarPaciente", "RFID", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogEditarPaciente", "Actualizar Dispositivo", Q_NULLPTR));
        commandLinkButton_2->setText(QApplication::translate("DialogEditarPaciente", "Continuar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarPaciente: public Ui_DialogEditarPaciente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARPACIENTE_H
