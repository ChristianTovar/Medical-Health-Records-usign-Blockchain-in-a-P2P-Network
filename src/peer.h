#ifndef PEER_H
#define PEER_H

#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QUuid>
#include <QThread>
#include <QtConcurrent>
#include <QEventLoop>
#include <QMetaEnum>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "functions.h"
#include "block.h"

class Peer : public QTcpServer
{
    Q_OBJECT
    Q_ENUMS(Request)

public:
    explicit Peer(QObject *parent = 0);

    Peer(QUuid guid, QHostAddress local_ip, quint16 local_port,QHostAddress predecessor_ip, quint16 predecessor_port, QHostAddress successor_ip, quint16 successor_port);

    void show();
    bool ping(const QString ip, const quint16 port);
    bool listenPing(const QString ip, const quint16 port);
    void manageConnection(qintptr socketDescriptor);
    void requestBaseGuid(const QString ip, const quint16 port);
    QUuid newBaseGuid(QUuid nodeGuid);
    void leaveSuccessor();
    void leavePredecessor();
    QByteArray loadDatabase();
    void setDatabase(QByteArray database);
    void broadcastBlock(Block bloque, QByteArray guid);
    QByteArray loadBlockchain();
    void setBlockchain(QByteArray blockchain);
    void blocksFromChain(QByteArray data);
    void requestFile(QByteArray link,QByteArray guid);
    void sendHealthRecord(QHostAddress ip, quint16 port, QByteArray link);
    void obtainPatient(QUuid guid,QHostAddress ip, quint16 port, QByteArray uid);
    void sendPatient(QHostAddress ip, quint16 port, QByteArray uid);
    void backupBlock(QByteArray receiver, QByteArray link);
    void backupPatient(QByteArray receiver, QByteArray patientInfo);
    void backupProfessional(QByteArray receiver, QByteArray professionalInfo);
    void switchSuccessor();
    void purgeBlocks(QByteArray guid);
    void purgeUsers(QByteArray guid);
    void backupLinks(QByteArray receiver);
    void backupUsers();

    //chord operations
    void join();
    void stabilize();
    void rectify();
    void auxilium();

    //getters
    QUuid         getGuid();
    QHostAddress  getLocalIP();
    quint16       getLocalPort();

    QUuid         getPredecessorGuid();
    QHostAddress  getPredecessorIP();
    quint16       getPredecessorPort();

    QUuid         getSuccessorGuid();
    QHostAddress  getSuccessorIP();
    quint16       getSuccessorPort();

    QUuid         getAuxiliaryGuid();
    QHostAddress  getAuxiliaryIP();
    quint16       getAuxiliaryPort();

    //setters
    void setSuccessorGuid(QUuid guid);
    void setPredecessorGuid(QUuid guid);
    void setGuid(QUuid guid);
    void setSuccessor(QUuid guid, QHostAddress ip, quint16 port);
    void setPredecessor(QUuid guid, QHostAddress ip, quint16 port);
    void setAuxiliarySuccessor(QUuid guid, QHostAddress ip, quint16 port);

    enum Request
    {
        BGUID,
        JOIN,
        STBL,
        RECT,
        SLV,
        PLV,
        AUX,
        BBLCK,
        REQF,
        FILE,
        OBP,
        APT,
        BCKPB,
        BCKPP,
        BCKPPR,
        PURGE,
        PURGEU
    };

private:

    //local
    QUuid        guid_m;
    QHostAddress local_ip_m;
    quint16       local_port_m;
    QHostAddress known_m;

    //predecessor
    QUuid        predecessor_guid_m;
    QHostAddress predecessor_ip_m;
    quint16       predecessor_port_m;

    //successor
    QUuid        successor_guid_m;
    QHostAddress successor_ip_m;
    quint16       successor_port_m;

    //auxiliary successor
    QUuid        aux_successor_guid_m;
    QHostAddress aux_successor_ip_m;
    quint16       aux_successor_port_m;

    //QTcpSocket *socket;
    Peer *peer;

signals:
    void setWidget(Peer *peer);
    void displayRecord();
    void newPatient();

protected:
   void incomingConnection(qintptr socketDescriptor);
};


#endif // PEER_H
