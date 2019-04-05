/********************************************************************************
** Form generated from reading UI file 'dialogingreso.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINGRESO_H
#define UI_DIALOGINGRESO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogIngreso
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_4;
    QLabel *label_33;
    QPlainTextEdit *plainTextEdit_Motivos;
    QLabel *label_34;
    QPlainTextEdit *plainTextEdit_EnfermedadActual;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *cardio_si;
    QRadioButton *cardio_no;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *pulmon_si;
    QRadioButton *pulmon_no;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *digestivo_si;
    QRadioButton *digestivo_no;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *quirurgico_si;
    QRadioButton *quirurgico_no;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *alergia_si;
    QRadioButton *alergia_no;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_14;
    QRadioButton *renales_si;
    QRadioButton *renales_no;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_15;
    QRadioButton *diabetes_si;
    QRadioButton *diabetes_no;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_Hora;
    QLineEdit *lineEdit_Cedula;
    QLineEdit *lineEdit_Nombres;
    QLineEdit *lineEdit_Apellidos;
    QLineEdit *lineEdit_RFID;
    QLineEdit *lineEdit_Lugar;
    QLineEdit *lineEdit_Fecha;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_Sexo;
    QLineEdit *lineEdit_EPS;
    QCommandLinkButton *commandLinkButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *label_31;
    QLabel *label_23;
    QLineEdit *lineEdit_TA;
    QLabel *label_24;
    QLineEdit *lineEdit_FC;
    QLabel *label_25;
    QLineEdit *lineEdit_FR;
    QLabel *label_26;
    QLineEdit *lineEdit_TEMP;
    QLabel *label_27;
    QLineEdit *lineEdit_SAO2;
    QLabel *label_28;
    QPlainTextEdit *plainTextEdit_Impresion;
    QLabel *label_29;
    QPlainTextEdit *plainTextEdit_Plan;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_5;
    QLabel *nombreLabel;
    QLineEdit *LineEdit_nombreProfesional;
    QLabel *label_12;
    QLineEdit *lineEdit_IPS;
    QLineEdit *lineEdit_tarjeta;
    QLabel *label_13;

    void setupUi(QDialog *DialogIngreso)
    {
        if (DialogIngreso->objectName().isEmpty())
            DialogIngreso->setObjectName(QStringLiteral("DialogIngreso"));
        DialogIngreso->setEnabled(true);
        DialogIngreso->resize(792, 632);
        verticalLayout = new QVBoxLayout(DialogIngreso);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        scrollArea = new QScrollArea(DialogIngreso);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -30, 756, 2148));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_33);

        plainTextEdit_Motivos = new QPlainTextEdit(groupBox_2);
        plainTextEdit_Motivos->setObjectName(QStringLiteral("plainTextEdit_Motivos"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, plainTextEdit_Motivos);

        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_34);

        plainTextEdit_EnfermedadActual = new QPlainTextEdit(groupBox_2);
        plainTextEdit_EnfermedadActual->setObjectName(QStringLiteral("plainTextEdit_EnfermedadActual"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, plainTextEdit_EnfermedadActual);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, label_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_4);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        cardio_si = new QRadioButton(groupBox_4);
        cardio_si->setObjectName(QStringLiteral("cardio_si"));

        horizontalLayout_9->addWidget(cardio_si);

        cardio_no = new QRadioButton(groupBox_4);
        cardio_no->setObjectName(QStringLiteral("cardio_no"));

        horizontalLayout_9->addWidget(cardio_no);


        horizontalLayout->addWidget(groupBox_4);


        formLayout_4->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_5);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pulmon_si = new QRadioButton(groupBox_5);
        pulmon_si->setObjectName(QStringLiteral("pulmon_si"));

        horizontalLayout_10->addWidget(pulmon_si);

        pulmon_no = new QRadioButton(groupBox_5);
        pulmon_no->setObjectName(QStringLiteral("pulmon_no"));

        horizontalLayout_10->addWidget(pulmon_no);


        horizontalLayout_2->addWidget(groupBox_5);


        formLayout_4->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        digestivo_si = new QRadioButton(groupBox_6);
        digestivo_si->setObjectName(QStringLiteral("digestivo_si"));

        horizontalLayout_11->addWidget(digestivo_si);

        digestivo_no = new QRadioButton(groupBox_6);
        digestivo_no->setObjectName(QStringLiteral("digestivo_no"));

        horizontalLayout_11->addWidget(digestivo_no);


        horizontalLayout_3->addWidget(groupBox_6);


        formLayout_4->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_7);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        quirurgico_si = new QRadioButton(groupBox_7);
        quirurgico_si->setObjectName(QStringLiteral("quirurgico_si"));

        horizontalLayout_12->addWidget(quirurgico_si);

        quirurgico_no = new QRadioButton(groupBox_7);
        quirurgico_no->setObjectName(QStringLiteral("quirurgico_no"));

        horizontalLayout_12->addWidget(quirurgico_no);


        horizontalLayout_4->addWidget(groupBox_7);


        formLayout_4->setLayout(7, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_8);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        alergia_si = new QRadioButton(groupBox_8);
        alergia_si->setObjectName(QStringLiteral("alergia_si"));

        horizontalLayout_13->addWidget(alergia_si);

        alergia_no = new QRadioButton(groupBox_8);
        alergia_no->setObjectName(QStringLiteral("alergia_no"));

        horizontalLayout_13->addWidget(alergia_no);


        horizontalLayout_5->addWidget(groupBox_8);


        formLayout_4->setLayout(8, QFormLayout::FieldRole, horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_9 = new QGroupBox(groupBox_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_9);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        renales_si = new QRadioButton(groupBox_9);
        renales_si->setObjectName(QStringLiteral("renales_si"));

        horizontalLayout_14->addWidget(renales_si);

        renales_no = new QRadioButton(groupBox_9);
        renales_no->setObjectName(QStringLiteral("renales_no"));

        horizontalLayout_14->addWidget(renales_no);


        horizontalLayout_6->addWidget(groupBox_9);


        formLayout_4->setLayout(9, QFormLayout::FieldRole, horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox_10 = new QGroupBox(groupBox_2);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_10);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        diabetes_si = new QRadioButton(groupBox_10);
        diabetes_si->setObjectName(QStringLiteral("diabetes_si"));

        horizontalLayout_15->addWidget(diabetes_si);

        diabetes_no = new QRadioButton(groupBox_10);
        diabetes_no->setObjectName(QStringLiteral("diabetes_no"));

        horizontalLayout_15->addWidget(diabetes_no);


        horizontalLayout_7->addWidget(groupBox_10);


        formLayout_4->setLayout(10, QFormLayout::FieldRole, horizontalLayout_7);


        verticalLayout_5->addLayout(formLayout_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_2, 4, 0, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        lineEdit_Hora = new QLineEdit(groupBox);
        lineEdit_Hora->setObjectName(QStringLiteral("lineEdit_Hora"));
        lineEdit_Hora->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Hora);

        lineEdit_Cedula = new QLineEdit(groupBox);
        lineEdit_Cedula->setObjectName(QStringLiteral("lineEdit_Cedula"));
        lineEdit_Cedula->setReadOnly(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Cedula);

        lineEdit_Nombres = new QLineEdit(groupBox);
        lineEdit_Nombres->setObjectName(QStringLiteral("lineEdit_Nombres"));
        lineEdit_Nombres->setReadOnly(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Nombres);

        lineEdit_Apellidos = new QLineEdit(groupBox);
        lineEdit_Apellidos->setObjectName(QStringLiteral("lineEdit_Apellidos"));
        lineEdit_Apellidos->setReadOnly(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_Apellidos);

        lineEdit_RFID = new QLineEdit(groupBox);
        lineEdit_RFID->setObjectName(QStringLiteral("lineEdit_RFID"));
        lineEdit_RFID->setReadOnly(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_RFID);

        lineEdit_Lugar = new QLineEdit(groupBox);
        lineEdit_Lugar->setObjectName(QStringLiteral("lineEdit_Lugar"));
        lineEdit_Lugar->setReadOnly(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_Lugar);

        lineEdit_Fecha = new QLineEdit(groupBox);
        lineEdit_Fecha->setObjectName(QStringLiteral("lineEdit_Fecha"));
        lineEdit_Fecha->setReadOnly(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_Fecha);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        lineEdit_Sexo = new QLineEdit(groupBox);
        lineEdit_Sexo->setObjectName(QStringLiteral("lineEdit_Sexo"));
        lineEdit_Sexo->setReadOnly(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_Sexo);

        lineEdit_EPS = new QLineEdit(groupBox);
        lineEdit_EPS->setObjectName(QStringLiteral("lineEdit_EPS"));
        lineEdit_EPS->setReadOnly(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_EPS);


        verticalLayout_2->addLayout(formLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        commandLinkButton = new QCommandLinkButton(scrollAreaWidgetContents);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        gridLayout->addWidget(commandLinkButton, 6, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_31);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_23);

        lineEdit_TA = new QLineEdit(groupBox_3);
        lineEdit_TA->setObjectName(QStringLiteral("lineEdit_TA"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEdit_TA);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_24);

        lineEdit_FC = new QLineEdit(groupBox_3);
        lineEdit_FC->setObjectName(QStringLiteral("lineEdit_FC"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEdit_FC);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_25);

        lineEdit_FR = new QLineEdit(groupBox_3);
        lineEdit_FR->setObjectName(QStringLiteral("lineEdit_FR"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_FR);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_26);

        lineEdit_TEMP = new QLineEdit(groupBox_3);
        lineEdit_TEMP->setObjectName(QStringLiteral("lineEdit_TEMP"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lineEdit_TEMP);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_27);

        lineEdit_SAO2 = new QLineEdit(groupBox_3);
        lineEdit_SAO2->setObjectName(QStringLiteral("lineEdit_SAO2"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, lineEdit_SAO2);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_28);

        plainTextEdit_Impresion = new QPlainTextEdit(groupBox_3);
        plainTextEdit_Impresion->setObjectName(QStringLiteral("plainTextEdit_Impresion"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, plainTextEdit_Impresion);

        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_29);

        plainTextEdit_Plan = new QPlainTextEdit(groupBox_3);
        plainTextEdit_Plan->setObjectName(QStringLiteral("plainTextEdit_Plan"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, plainTextEdit_Plan);


        verticalLayout_3->addLayout(formLayout_3);


        gridLayout->addWidget(groupBox_3, 5, 0, 1, 1);

        groupBox_11 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        verticalLayout_6 = new QVBoxLayout(groupBox_11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        nombreLabel = new QLabel(groupBox_11);
        nombreLabel->setObjectName(QStringLiteral("nombreLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, nombreLabel);

        LineEdit_nombreProfesional = new QLineEdit(groupBox_11);
        LineEdit_nombreProfesional->setObjectName(QStringLiteral("LineEdit_nombreProfesional"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, LineEdit_nombreProfesional);

        label_12 = new QLabel(groupBox_11);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_12);

        lineEdit_IPS = new QLineEdit(groupBox_11);
        lineEdit_IPS->setObjectName(QStringLiteral("lineEdit_IPS"));
        lineEdit_IPS->setReadOnly(false);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineEdit_IPS);

        lineEdit_tarjeta = new QLineEdit(groupBox_11);
        lineEdit_tarjeta->setObjectName(QStringLiteral("lineEdit_tarjeta"));
        lineEdit_tarjeta->setReadOnly(false);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEdit_tarjeta);

        label_13 = new QLabel(groupBox_11);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_13);


        verticalLayout_6->addLayout(formLayout_5);


        gridLayout->addWidget(groupBox_11, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(DialogIngreso);

        QMetaObject::connectSlotsByName(DialogIngreso);
    } // setupUi

    void retranslateUi(QDialog *DialogIngreso)
    {
        DialogIngreso->setWindowTitle(QApplication::translate("DialogIngreso", "Ingreso Paciente", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DialogIngreso", "Motivos de Consulta", Q_NULLPTR));
        label_33->setText(QApplication::translate("DialogIngreso", "Motivos", Q_NULLPTR));
        label_34->setText(QApplication::translate("DialogIngreso", "Enfermedad Actual", Q_NULLPTR));
        label_10->setText(QApplication::translate("DialogIngreso", "Antecedentes Personales y Familiares", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("DialogIngreso", "Cardiovasculares", Q_NULLPTR));
        cardio_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        cardio_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("DialogIngreso", "Pulmonares", Q_NULLPTR));
        pulmon_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        pulmon_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("DialogIngreso", "Digestivos", Q_NULLPTR));
        digestivo_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        digestivo_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("DialogIngreso", "Quirurgicos", Q_NULLPTR));
        quirurgico_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        quirurgico_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("DialogIngreso", "Alergias", Q_NULLPTR));
        alergia_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        alergia_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("DialogIngreso", "Renales", Q_NULLPTR));
        renales_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        renales_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("DialogIngreso", "Diabetes", Q_NULLPTR));
        diabetes_si->setText(QApplication::translate("DialogIngreso", "SI", Q_NULLPTR));
        diabetes_no->setText(QApplication::translate("DialogIngreso", "NO", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogIngreso", "Datos Personales Paciente", Q_NULLPTR));
        label->setText(QApplication::translate("DialogIngreso", "Fecha/Hora", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogIngreso", "Cedula", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogIngreso", "Nombres", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogIngreso", "Apellidos", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogIngreso", "RFID", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogIngreso", "Lugar de Nacimiento", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogIngreso", "Fecha de Nacimiento", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogIngreso", "Sexo", Q_NULLPTR));
        label_9->setText(QApplication::translate("DialogIngreso", "EPS", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("DialogIngreso", "CONTINUAR", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("DialogIngreso", "Examen Fisico", Q_NULLPTR));
        label_31->setText(QApplication::translate("DialogIngreso", "Signos Vitales", Q_NULLPTR));
        label_23->setText(QApplication::translate("DialogIngreso", "Tension Arterial", Q_NULLPTR));
        label_24->setText(QApplication::translate("DialogIngreso", "Frecuencia Cardiaca", Q_NULLPTR));
        label_25->setText(QApplication::translate("DialogIngreso", "Frecuencia Respiratoria", Q_NULLPTR));
        label_26->setText(QApplication::translate("DialogIngreso", "Temperatura", Q_NULLPTR));
        label_27->setText(QApplication::translate("DialogIngreso", "Sa02", Q_NULLPTR));
        label_28->setText(QApplication::translate("DialogIngreso", "Impresion General", Q_NULLPTR));
        label_29->setText(QApplication::translate("DialogIngreso", "Plan de Tratamiento", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("DialogIngreso", "Datos Profesional a Cargo", Q_NULLPTR));
        nombreLabel->setText(QApplication::translate("DialogIngreso", "Nombre", Q_NULLPTR));
        label_12->setText(QApplication::translate("DialogIngreso", "IPS", Q_NULLPTR));
        label_13->setText(QApplication::translate("DialogIngreso", "Tarjeta Profesional", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogIngreso: public Ui_DialogIngreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINGRESO_H
