#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "MyTcpSockets.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void listenNodes(const quint16 port);

signals:

public slots:

protected:
void incomingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
