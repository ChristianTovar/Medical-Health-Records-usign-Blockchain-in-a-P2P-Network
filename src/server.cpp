#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

void Server::listenNodes(const quint16 port)
{
    this->listen(QHostAddress::Any, port);


        qDebug() << "Listening to port " << port << "...";

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    // At the incoming connection, make a client
    // and set the socket
    //MyClient *client = new MyClient(this);

   // client->setSocket(socketDescriptor);

        qDebug() << "Could not start server";
}
