/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QFormLayout *formLayout_3;
    QRadioButton *radioButton_Base;
    QRadioButton *radioButton_Join;
    QPushButton *pushButton_Base;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_Port;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_Next;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QLineEdit *lineEdit_Local_IP;
    QLineEdit *lineEdit_Local_Port;
    QLabel *label_5;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(339, 410);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        groupBox->setGeometry(QRect(40, 140, 261, 96));
        formLayout_3 = new QFormLayout(groupBox);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        radioButton_Base = new QRadioButton(groupBox);
        radioButton_Base->setObjectName(QStringLiteral("radioButton_Base"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, radioButton_Base);

        radioButton_Join = new QRadioButton(groupBox);
        radioButton_Join->setObjectName(QStringLiteral("radioButton_Join"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, radioButton_Join);

        pushButton_Base = new QPushButton(groupBox);
        pushButton_Base->setObjectName(QStringLiteral("pushButton_Base"));
        pushButton_Base->setCheckable(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, pushButton_Base);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(false);
        groupBox_2->setGeometry(QRect(40, 240, 261, 101));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lineEdit_IP = new QLineEdit(groupBox_2);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit_IP);

        lineEdit_Port = new QLineEdit(groupBox_2);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_Port);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_3);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);

        pushButton_Next = new QPushButton(Dialog);
        pushButton_Next->setObjectName(QStringLiteral("pushButton_Next"));
        pushButton_Next->setEnabled(false);
        pushButton_Next->setGeometry(QRect(60, 350, 231, 41));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 20, 261, 100));
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lineEdit_Local_IP = new QLineEdit(groupBox_3);
        lineEdit_Local_IP->setObjectName(QStringLiteral("lineEdit_Local_IP"));
        lineEdit_Local_IP->setReadOnly(false);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEdit_Local_IP);

        lineEdit_Local_Port = new QLineEdit(groupBox_3);
        lineEdit_Local_Port->setObjectName(QStringLiteral("lineEdit_Local_Port"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lineEdit_Local_Port);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_5);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_4);

        QWidget::setTabOrder(lineEdit_Local_IP, lineEdit_Local_Port);
        QWidget::setTabOrder(lineEdit_Local_Port, radioButton_Base);
        QWidget::setTabOrder(radioButton_Base, pushButton_Base);
        QWidget::setTabOrder(pushButton_Base, radioButton_Join);
        QWidget::setTabOrder(radioButton_Join, lineEdit_IP);
        QWidget::setTabOrder(lineEdit_IP, lineEdit_Port);
        QWidget::setTabOrder(lineEdit_Port, pushButton_Next);

        retranslateUi(Dialog);

        pushButton_Base->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Network Settings", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "Is this node base or joining?", Q_NULLPTR));
        radioButton_Base->setText(QApplication::translate("Dialog", "Base", Q_NULLPTR));
        radioButton_Join->setText(QApplication::translate("Dialog", "Join", Q_NULLPTR));
        pushButton_Base->setText(QApplication::translate("Dialog", "A", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("Dialog", "IP Address", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Port", Q_NULLPTR));
        pushButton_Next->setText(QApplication::translate("Dialog", "Next", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Local Host", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "IP Address", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Local Port", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
