#ifndef DIALOGEVOLUCION_H
#define DIALOGEVOLUCION_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCryptographicHash>
#include <QFile>
#include <QDir>
#include "block.h"
#include "peer.h"


namespace Ui {
class DialogEvolucion;
}

class DialogEvolucion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvolucion(Peer *mainPeer=nullptr, QByteArray uid="",QString nombre="",QString ips="", QString cp="");
    ~DialogEvolucion();

    void createHealthRecord(QFile *file);

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::DialogEvolucion *ui;
    Peer *peer;
};

#endif // DIALOGEVOLUCION_H
