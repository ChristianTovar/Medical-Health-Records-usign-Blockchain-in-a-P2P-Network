#ifndef BLOCK_H
#define BLOCK_H

#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDir>
#include <QCryptographicHash>

#define DIFFICULTY 2

class Block : public QJsonObject
{

public:
    Block(QByteArray  previousHash, QByteArray  data, QByteArray link);
    Block(QByteArray data, QByteArray hash, QByteArray link, qint64 nonce, QByteArray previousHash, qint64 timeStamp);
    Block();

    QByteArray calculateHash();
    void mineBlock();
    void insertData();

    //getters
    QByteArray  getHash();
    QByteArray  getPreviousHash();
    QByteArray  getData();
    QByteArray  getLink();
    qint64      getTimeStamp();
    qint64      getNonce();

private:
    QByteArray  data_m;
    QByteArray  hash_m;
    QByteArray  link_m;
    qint64      nonce_m;
    QByteArray  previousHash_m;
    qint64      timeStamp_m;


signals:

public slots:
};

#endif // BLOCK_H

    QByteArray getLastHash();
    void insertBlock(Block bloque);
    QByteArray hashFile(QFile *file);


