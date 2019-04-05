#ifndef DIALOGANADIRPROFESIONAL_H
#define DIALOGANADIRPROFESIONAL_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "peer.h"

namespace Ui {
class DialogAnadirProfesional;
}

class DialogAnadirProfesional : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAnadirProfesional(Peer *mainPeer,QByteArray uid="uid");
    ~DialogAnadirProfesional();

private slots:
    void on_lineEdit_Nombre_textChanged();
    void on_lineEdit_IPS_textChanged();

    void on_commandLinkButton_clicked();

private:
    Ui::DialogAnadirProfesional *ui;
    Peer *peer;
    QString uid_m;
};

#endif // DIALOGANADIRPROFESIONAL_H
