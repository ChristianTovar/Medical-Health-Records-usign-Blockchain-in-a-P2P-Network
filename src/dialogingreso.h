#ifndef DIALOGINGRESO_H
#define DIALOGINGRESO_H

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
class DialogIngreso;
}

class DialogIngreso : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIngreso(Peer *mainPeer=nullptr,QByteArray uid="",QString nombre="",QString ips="", QString cp="");
    ~DialogIngreso();

    void createHealthRecord(QFile *file);

signals:

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::DialogIngreso *ui;
    Peer *peer;
};

#endif // DIALOGINGRESO_H
