#include "block.h"


Block::Block(QByteArray previousHash, QByteArray data, QByteArray link): previousHash_m(previousHash), data_m(data), link_m(link)
{
    QDateTime time = QDateTime::currentDateTime();
    timeStamp_m=time.toSecsSinceEpoch();
    hash_m=calculateHash();
}

Block::Block(QByteArray data, QByteArray hash, QByteArray link, qint64 nonce, QByteArray previousHash, qint64 timeStamp): data_m(data), hash_m(hash),link_m(link), nonce_m(nonce), previousHash_m(previousHash), timeStamp_m(timeStamp)
{
}

Block::Block()
{
    hash_m="0000000000000000000000000000000000000000000000000000000000000000";
    data_m="null";
    link_m="null";
    nonce_m=00000000;
    previousHash_m="null";
    timeStamp_m=00000000;
}

QByteArray Block::calculateHash()
{
    return QCryptographicHash::hash(getLastHash().append(QByteArray::number(timeStamp_m)).append(QByteArray::number(nonce_m)).append(data_m).append(link_m),QCryptographicHash::Sha256).toHex();
}

void Block::mineBlock()
{
    QString zeros;

    //padding zeros for difficulty
    for(int i=0;i<DIFFICULTY;i++)
    {
        zeros.append("0");
    }

    while(QString::fromUtf8(hash_m).left(DIFFICULTY) != zeros)
    {
      nonce_m++;
      hash_m=calculateHash();
    }
}

void Block::insertData()
{
    insert("hash",QString::fromUtf8(hash_m));
    insert("previous_hash",QString::fromUtf8(previousHash_m));
    insert("time_stamp",timeStamp_m);
    insert("data",QString::fromUtf8(data_m));
    insert("link", QString::fromUtf8(link_m));
    insert("nonce",nonce_m);
}

QByteArray Block::getHash()
{
    return hash_m;
}

QByteArray Block::getPreviousHash()
{
    return previousHash_m;
}

QByteArray Block::getData()
{
    return data_m;
}

QByteArray Block::getLink()
{
    return link_m;
}

qint64 Block::getTimeStamp()
{
    return timeStamp_m;
}

qint64 Block::getNonce()
{
    return nonce_m;
}

QByteArray getLastHash()
{
    QFile file(QDir::currentPath().append("/bc.json"));
    QByteArray data;

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open error";
        return "error";
    }

    else
    {
        //read entire blockchain;
        data=file.readAll();

        //parse blockchain into document
        QJsonDocument doc=QJsonDocument::fromJson(data);

        //parse document into QJsonObject
        QJsonObject obj=doc.object();

        //return the value of hash from the last block
        return obj["Block #"+QString::number(obj.size()-1)].toObject().value("hash").toString().toUtf8();
    }
}

void insertBlock(Block bloque)
{
    QFile blockchain(QDir::currentPath().append("/bc.json"));

    if(!blockchain.open(QIODevice::ReadOnly))
    {
       qDebug() << "Could not open " << blockchain.fileName();
    }

    else
    {
        //read entire blockchain;
        QByteArray data=blockchain.readAll();

        //close file
        blockchain.close();

        if(!blockchain.open(QIODevice::WriteOnly))
        {
           qDebug() << "Could not open " << blockchain.fileName();
        }

        else
        {
            //parse blockchain into document
            QJsonDocument doc=QJsonDocument::fromJson(data);

            //parse document into QJsonObject
            QJsonObject chain=doc.object();

            //insert block index number
            chain.insert("Block #"+QString::number(chain.size()),bloque);

            //parse QJsonObject into document
            QJsonDocument updatedDoc(chain);

            //write entire blockchain + new block
            blockchain.write(updatedDoc.toJson(QJsonDocument::Indented));
            blockchain.close();
        }
    }
}

QByteArray hashFile(QFile *file)
{
    if(!file->open(QIODevice::ReadOnly))
    {
       qDebug() << "Could not open " << file->fileName();
       return 0;
    }

    else
    {
        QByteArray fileHash=file->readAll();
        return QCryptographicHash::hash(fileHash,QCryptographicHash::Sha256).toHex();
    }
}
