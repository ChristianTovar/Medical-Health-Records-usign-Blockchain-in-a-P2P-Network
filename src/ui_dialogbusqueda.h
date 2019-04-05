/********************************************************************************
** Form generated from reading UI file 'dialogbusqueda.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUSQUEDA_H
#define UI_DIALOGBUSQUEDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogBusqueda
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *DialogBusqueda)
    {
        if (DialogBusqueda->objectName().isEmpty())
            DialogBusqueda->setObjectName(QStringLiteral("DialogBusqueda"));
        DialogBusqueda->resize(780, 661);
        verticalLayout = new QVBoxLayout(DialogBusqueda);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(DialogBusqueda);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setReadOnly(false);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(DialogBusqueda);

        QMetaObject::connectSlotsByName(DialogBusqueda);
    } // setupUi

    void retranslateUi(QDialog *DialogBusqueda)
    {
        DialogBusqueda->setWindowTitle(QApplication::translate("DialogBusqueda", "Historia Clinica ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogBusqueda: public Ui_DialogBusqueda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUSQUEDA_H
