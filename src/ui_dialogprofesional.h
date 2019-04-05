/********************************************************************************
** Form generated from reading UI file 'dialogprofesional.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPROFESIONAL_H
#define UI_DIALOGPROFESIONAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogProfesional
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *DialogProfesional)
    {
        if (DialogProfesional->objectName().isEmpty())
            DialogProfesional->setObjectName(QStringLiteral("DialogProfesional"));
        DialogProfesional->resize(600, 300);
        verticalLayout = new QVBoxLayout(DialogProfesional);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogProfesional);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(DialogProfesional);

        QMetaObject::connectSlotsByName(DialogProfesional);
    } // setupUi

    void retranslateUi(QDialog *DialogProfesional)
    {
        DialogProfesional->setWindowTitle(QApplication::translate("DialogProfesional", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogProfesional", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogProfesional: public Ui_DialogProfesional {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPROFESIONAL_H
