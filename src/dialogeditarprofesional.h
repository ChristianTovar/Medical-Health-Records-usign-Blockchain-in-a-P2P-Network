#ifndef DIALOGEDITARPROFESIONAL_H
#define DIALOGEDITARPROFESIONAL_H

#include <QDialog>
#include <QDialog>
#include <QTimer>
#include "dialogprofesional.h"
#include <QDebug>
#include <QProcess>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class DialogEditarProfesional;
}

class DialogEditarProfesional : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditarProfesional(QString id,QString nombres, QString ips, QString tarjeta);
    ~DialogEditarProfesional();

private slots:
    void on_commandLinkButton_clicked();
    void updateRFID();
    void on_commandLinkButton_2_clicked();

private:
    Ui::DialogEditarProfesional *ui;
    QTimer *timer_update_rfid=new QTimer();
    DialogProfesional *dialog;
    QString id_m;
};

#endif // DIALOGEDITARPROFESIONAL_H
