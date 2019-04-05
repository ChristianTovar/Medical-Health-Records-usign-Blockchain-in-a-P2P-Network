/********************************************************************************
** Form generated from reading UI file 'dialoganadirprofesional.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGANADIRPROFESIONAL_H
#define UI_DIALOGANADIRPROFESIONAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAnadirProfesional
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_Nombre;
    QLabel *label_2;
    QLineEdit *lineEdit_IPS;
    QLabel *label_3;
    QLineEdit *lineEdit_Tarjeta;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *DialogAnadirProfesional)
    {
        if (DialogAnadirProfesional->objectName().isEmpty())
            DialogAnadirProfesional->setObjectName(QStringLiteral("DialogAnadirProfesional"));
        DialogAnadirProfesional->resize(830, 169);
        horizontalLayout = new QHBoxLayout(DialogAnadirProfesional);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DialogAnadirProfesional);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_Nombre = new QLineEdit(DialogAnadirProfesional);
        lineEdit_Nombre->setObjectName(QStringLiteral("lineEdit_Nombre"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Nombre);

        label_2 = new QLabel(DialogAnadirProfesional);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_IPS = new QLineEdit(DialogAnadirProfesional);
        lineEdit_IPS->setObjectName(QStringLiteral("lineEdit_IPS"));
        lineEdit_IPS->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_IPS);

        label_3 = new QLabel(DialogAnadirProfesional);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_Tarjeta = new QLineEdit(DialogAnadirProfesional);
        lineEdit_Tarjeta->setObjectName(QStringLiteral("lineEdit_Tarjeta"));
        lineEdit_Tarjeta->setReadOnly(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Tarjeta);

        commandLinkButton = new QCommandLinkButton(DialogAnadirProfesional);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, commandLinkButton);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(DialogAnadirProfesional);

        QMetaObject::connectSlotsByName(DialogAnadirProfesional);
    } // setupUi

    void retranslateUi(QDialog *DialogAnadirProfesional)
    {
        DialogAnadirProfesional->setWindowTitle(QApplication::translate("DialogAnadirProfesional", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogAnadirProfesional", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogAnadirProfesional", "IPS", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogAnadirProfesional", "Tarjeta Profesional", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogAnadirProfesional", "Continuar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogAnadirProfesional: public Ui_DialogAnadirProfesional {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGANADIRPROFESIONAL_H
