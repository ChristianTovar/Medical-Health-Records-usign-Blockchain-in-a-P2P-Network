/********************************************************************************
** Form generated from reading UI file 'dialogpaciente.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPACIENTE_H
#define UI_DIALOGPACIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPaciente
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *DialogPaciente)
    {
        if (DialogPaciente->objectName().isEmpty())
            DialogPaciente->setObjectName(QStringLiteral("DialogPaciente"));
        DialogPaciente->resize(600, 300);
        verticalLayout = new QVBoxLayout(DialogPaciente);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogPaciente);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(DialogPaciente);

        QMetaObject::connectSlotsByName(DialogPaciente);
    } // setupUi

    void retranslateUi(QDialog *DialogPaciente)
    {
        DialogPaciente->setWindowTitle(QApplication::translate("DialogPaciente", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogPaciente", "label", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPaciente: public Ui_DialogPaciente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPACIENTE_H
