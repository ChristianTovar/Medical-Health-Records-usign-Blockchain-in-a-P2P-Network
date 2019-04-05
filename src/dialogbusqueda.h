#ifndef DIALOGBUSQUEDA_H
#define DIALOGBUSQUEDA_H

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
class DialogBusqueda;
}

class DialogBusqueda : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBusqueda(QByteArray dataPatient="");
    ~DialogBusqueda();

    void update();

private:
    Ui::DialogBusqueda *ui;
    QByteArray data;
};

#endif // DIALOGBUSQUEDA_H
