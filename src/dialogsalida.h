#ifndef DIALOGSALIDA_H
#define DIALOGSALIDA_H

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
class DialogSalida;
}

class DialogSalida : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSalida(Peer *mainPeer=nullptr, QByteArray uid="", QString nombre="",QString ips="",QString cp="");
    ~DialogSalida();

    void createHealthRecord(QFile *file);

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::DialogSalida *ui;
    Peer *peer;
};

#endif // DIALOGSALIDA_H
