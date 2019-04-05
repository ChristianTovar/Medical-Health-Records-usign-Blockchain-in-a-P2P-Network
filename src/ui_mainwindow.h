/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSet_Chord;
    QAction *actionChord_Status;
    QAction *actionClose_App;
    QAction *actionAuto_Join;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Ingreso;
    QPushButton *pushButton_Evolucion;
    QPushButton *pushButton_Salida;
    QPushButton *pushButton_Busqueda;
    QPushButton *pushButton_Anadir;
    QPushButton *pushButton_EditarPaciente;
    QPushButton *pushButton_AnadirProfesional;
    QPushButton *pushButton_EditarProfesional;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *logo_label;
    QSpacerItem *verticalSpacer_2;
    QLabel *status_label;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuInfo;
    QMenu *menuExit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        MainWindow->setFont(font);
        actionSet_Chord = new QAction(MainWindow);
        actionSet_Chord->setObjectName(QStringLiteral("actionSet_Chord"));
        actionChord_Status = new QAction(MainWindow);
        actionChord_Status->setObjectName(QStringLiteral("actionChord_Status"));
        actionChord_Status->setEnabled(false);
        actionClose_App = new QAction(MainWindow);
        actionClose_App->setObjectName(QStringLiteral("actionClose_App"));
        actionAuto_Join = new QAction(MainWindow);
        actionAuto_Join->setObjectName(QStringLiteral("actionAuto_Join"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(21);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        dateTimeEdit->setFont(font1);
        dateTimeEdit->setCursor(QCursor(Qt::ArrowCursor));
        dateTimeEdit->setAcceptDrops(false);
        dateTimeEdit->setWrapping(false);
        dateTimeEdit->setFrame(true);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setKeyboardTracking(true);
        dateTimeEdit->setProperty("showGroupSeparator", QVariant(false));
        dateTimeEdit->setTime(QTime(1, 0, 0));
        dateTimeEdit->setCalendarPopup(false);

        verticalLayout->addWidget(dateTimeEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_Ingreso = new QPushButton(centralWidget);
        pushButton_Ingreso->setObjectName(QStringLiteral("pushButton_Ingreso"));
        pushButton_Ingreso->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Ingreso->sizePolicy().hasHeightForWidth());
        pushButton_Ingreso->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        pushButton_Ingreso->setFont(font2);
        pushButton_Ingreso->setFlat(false);

        verticalLayout->addWidget(pushButton_Ingreso);

        pushButton_Evolucion = new QPushButton(centralWidget);
        pushButton_Evolucion->setObjectName(QStringLiteral("pushButton_Evolucion"));
        pushButton_Evolucion->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Evolucion->sizePolicy().hasHeightForWidth());
        pushButton_Evolucion->setSizePolicy(sizePolicy);
        pushButton_Evolucion->setFont(font2);

        verticalLayout->addWidget(pushButton_Evolucion);

        pushButton_Salida = new QPushButton(centralWidget);
        pushButton_Salida->setObjectName(QStringLiteral("pushButton_Salida"));
        pushButton_Salida->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Salida->sizePolicy().hasHeightForWidth());
        pushButton_Salida->setSizePolicy(sizePolicy);
        pushButton_Salida->setFont(font2);

        verticalLayout->addWidget(pushButton_Salida);

        pushButton_Busqueda = new QPushButton(centralWidget);
        pushButton_Busqueda->setObjectName(QStringLiteral("pushButton_Busqueda"));
        pushButton_Busqueda->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Busqueda->sizePolicy().hasHeightForWidth());
        pushButton_Busqueda->setSizePolicy(sizePolicy);
        pushButton_Busqueda->setFont(font2);

        verticalLayout->addWidget(pushButton_Busqueda);

        pushButton_Anadir = new QPushButton(centralWidget);
        pushButton_Anadir->setObjectName(QStringLiteral("pushButton_Anadir"));
        pushButton_Anadir->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_Anadir->sizePolicy().hasHeightForWidth());
        pushButton_Anadir->setSizePolicy(sizePolicy);
        pushButton_Anadir->setSizeIncrement(QSize(0, 0));
        pushButton_Anadir->setFont(font2);
        pushButton_Anadir->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(pushButton_Anadir);

        pushButton_EditarPaciente = new QPushButton(centralWidget);
        pushButton_EditarPaciente->setObjectName(QStringLiteral("pushButton_EditarPaciente"));
        pushButton_EditarPaciente->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_EditarPaciente->sizePolicy().hasHeightForWidth());
        pushButton_EditarPaciente->setSizePolicy(sizePolicy);
        pushButton_EditarPaciente->setFont(font2);

        verticalLayout->addWidget(pushButton_EditarPaciente);

        pushButton_AnadirProfesional = new QPushButton(centralWidget);
        pushButton_AnadirProfesional->setObjectName(QStringLiteral("pushButton_AnadirProfesional"));
        pushButton_AnadirProfesional->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_AnadirProfesional->sizePolicy().hasHeightForWidth());
        pushButton_AnadirProfesional->setSizePolicy(sizePolicy);
        pushButton_AnadirProfesional->setFont(font2);

        verticalLayout->addWidget(pushButton_AnadirProfesional);

        pushButton_EditarProfesional = new QPushButton(centralWidget);
        pushButton_EditarProfesional->setObjectName(QStringLiteral("pushButton_EditarProfesional"));
        pushButton_EditarProfesional->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_EditarProfesional->sizePolicy().hasHeightForWidth());
        pushButton_EditarProfesional->setSizePolicy(sizePolicy);
        pushButton_EditarProfesional->setFont(font2);

        verticalLayout->addWidget(pushButton_EditarProfesional);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 2);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 2);
        verticalLayout->setStretch(8, 2);
        verticalLayout->setStretch(9, 2);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        logo_label = new QLabel(centralWidget);
        logo_label->setObjectName(QStringLiteral("logo_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo_label->sizePolicy().hasHeightForWidth());
        logo_label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(logo_label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));

        verticalLayout_2->addWidget(status_label);

        verticalLayout_2->setStretch(1, 9);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(false);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuSettings->setAutoFillBackground(false);
        menuSettings->setToolTipsVisible(false);
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(pushButton_Ingreso, pushButton_Evolucion);
        QWidget::setTabOrder(pushButton_Evolucion, pushButton_Salida);
        QWidget::setTabOrder(pushButton_Salida, pushButton_Busqueda);
        QWidget::setTabOrder(pushButton_Busqueda, pushButton_Anadir);
        QWidget::setTabOrder(pushButton_Anadir, dateTimeEdit);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuSettings->addSeparator();
        menuSettings->addAction(actionAuto_Join);
        menuSettings->addSeparator();
        menuSettings->addAction(actionSet_Chord);
        menuInfo->addAction(actionChord_Status);
        menuExit->addAction(actionClose_App);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HCD : : BC", Q_NULLPTR));
        actionSet_Chord->setText(QApplication::translate("MainWindow", "Set Chord", Q_NULLPTR));
        actionChord_Status->setText(QApplication::translate("MainWindow", "Chord Status", Q_NULLPTR));
        actionClose_App->setText(QApplication::translate("MainWindow", "Close App", Q_NULLPTR));
        actionAuto_Join->setText(QApplication::translate("MainWindow", "Auto Join", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "d/MM/yy h:mm:ss AP", Q_NULLPTR));
        pushButton_Ingreso->setText(QApplication::translate("MainWindow", "INGRESO", Q_NULLPTR));
        pushButton_Evolucion->setText(QApplication::translate("MainWindow", "EVOLUCION", Q_NULLPTR));
        pushButton_Salida->setText(QApplication::translate("MainWindow", "SALIDA", Q_NULLPTR));
        pushButton_Busqueda->setText(QApplication::translate("MainWindow", "BUSQUEDA", Q_NULLPTR));
        pushButton_Anadir->setText(QApplication::translate("MainWindow", "A\303\221ADIR PACIENTE", Q_NULLPTR));
        pushButton_EditarPaciente->setText(QApplication::translate("MainWindow", "EDITAR PACIENTE", Q_NULLPTR));
        pushButton_AnadirProfesional->setText(QApplication::translate("MainWindow", "A\303\221ADIR PROFESIONAL", Q_NULLPTR));
        pushButton_EditarProfesional->setText(QApplication::translate("MainWindow", "EDITAR PROFESIONAL", Q_NULLPTR));
        logo_label->setText(QApplication::translate("MainWindow", "logo", Q_NULLPTR));
        status_label->setText(QApplication::translate("MainWindow", "status", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
