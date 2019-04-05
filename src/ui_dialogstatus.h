/********************************************************************************
** Form generated from reading UI file 'dialogstatus.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTATUS_H
#define UI_DIALOGSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogStatus
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditLocal;
    QLineEdit *lineEditPredecessor;
    QLineEdit *lineEditSuccessor;
    QLineEdit *lineEditAuxiliary;

    void setupUi(QDialog *DialogStatus)
    {
        if (DialogStatus->objectName().isEmpty())
            DialogStatus->setObjectName(QStringLiteral("DialogStatus"));
        DialogStatus->resize(781, 156);
        horizontalLayout = new QHBoxLayout(DialogStatus);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DialogStatus);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(DialogStatus);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(DialogStatus);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(DialogStatus);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEditLocal = new QLineEdit(DialogStatus);
        lineEditLocal->setObjectName(QStringLiteral("lineEditLocal"));
        lineEditLocal->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditLocal);

        lineEditPredecessor = new QLineEdit(DialogStatus);
        lineEditPredecessor->setObjectName(QStringLiteral("lineEditPredecessor"));
        lineEditPredecessor->setReadOnly(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPredecessor);

        lineEditSuccessor = new QLineEdit(DialogStatus);
        lineEditSuccessor->setObjectName(QStringLiteral("lineEditSuccessor"));
        lineEditSuccessor->setReadOnly(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditSuccessor);

        lineEditAuxiliary = new QLineEdit(DialogStatus);
        lineEditAuxiliary->setObjectName(QStringLiteral("lineEditAuxiliary"));
        lineEditAuxiliary->setReadOnly(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditAuxiliary);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(DialogStatus);

        QMetaObject::connectSlotsByName(DialogStatus);
    } // setupUi

    void retranslateUi(QDialog *DialogStatus)
    {
        DialogStatus->setWindowTitle(QApplication::translate("DialogStatus", "Chord Status", Q_NULLPTR));
        label->setText(QApplication::translate("DialogStatus", "Local", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogStatus", "Pred", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogStatus", "Succ", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogStatus", "Aux", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogStatus: public Ui_DialogStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTATUS_H
