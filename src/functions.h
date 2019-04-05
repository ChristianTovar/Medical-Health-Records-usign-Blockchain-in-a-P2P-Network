#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QtNetwork>
#include <QUuid>
#include <QString>
#include <QtConcurrent>
#include <QTimer>
#include "peer.h"

QString get_ip_address();
quint16 get_random_port();
bool between(int n1, int n2, int n3);
QUuid assignGuid(QUuid local, QUuid successor);
void cipherFile(QFile *file);
void appendAddress(QString ip,quint16 port);

#endif // FUNCTIONS_H
