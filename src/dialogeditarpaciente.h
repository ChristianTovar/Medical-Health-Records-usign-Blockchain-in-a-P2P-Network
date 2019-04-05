#ifndef DIALOGEDITARPACIENTE_H
#define DIALOGEDITARPACIENTE_H

#include <QDialog>
#include <QTimer>
#include "dialogpaciente.h"
#include <QDebug>
#include <QProcess>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class DialogEditarPaciente;
}

class DialogEditarPaciente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditarPaciente(QString cedula,QString nombres, QString apellidos, QString lugar, QString fecha, QString sexo, QString eps,QString rfid);
    ~DialogEditarPaciente();


private slots:
    void on_commandLinkButton_clicked();
    void updateRFID();

    void on_commandLinkButton_2_clicked();

private:
    Ui::DialogEditarPaciente *ui;
    QTimer *timer_update_rfid=new QTimer();
    DialogPaciente *dialog;
};

#endif // DIALOGEDITARPACIENTE_H
