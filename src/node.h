#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QHostAddress>
#include <QUuid>
#include <QTcpSocket>
#include <QThread>


class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = 0);
    Node(QObject *parent, QUuid guid, QHostAddress local_ip, qint16 local_port, QHostAddress known,  QHostAddress predecessor_ip, qint16 predecessor_port, QHostAddress successor_ip, qint16 successor_port);

    void show();
    void getSuccessor(QString *ip, qint16 *port, QUuid *guid);
    void getGuid(QUuid *guid);
    QHostAddress getLocalIp();
    qint16 getLocalPort();
    void getPredecessorGuid(QUuid *guid);
    void setPredecessor(QByteArray ip,QByteArray port, QByteArray guid);
    void setSuccessor(QByteArray ip,QByteArray port, QByteArray guid);
    void newBaseGuid(QUuid *guid,QUuid *bguid);
    //void getSuccessorGuid(QString *ip, qint16 *port,QUuid *guid);
    void setGuid(QByteArray guid);
    void setSuccessorGuid(QByteArray guid);
    void setPredecessorGuid(QByteArray guid);
    void joinSetup(QByteArray successor_ip, QByteArray successor_port, QByteArray new_guid, QByteArray successor_guid, QByteArray predecessor_guid, const QString predecessor_ip, const qint16 predecessor_port);
    void stabilize();
    void rectify();



private:

    //local items
    QUuid        guid_m;
    QHostAddress local_ip_m;
    qint16       local_port_m;
    QHostAddress known_m;

    //predecessor items
    QUuid        predecessor_guid_m;
    QHostAddress predecessor_ip_m;
    qint16       predecessor_port_m;

    //successor items
    QUuid        successor_guid_m;
    QHostAddress successor_ip_m;
    qint16       successor_port_m;


    QTcpSocket *socket;
signals:
public slots:

};

#endif // NODE_H
