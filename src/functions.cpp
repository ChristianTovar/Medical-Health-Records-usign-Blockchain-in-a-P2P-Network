#include "functions.h"


QString get_ip_address()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

     for(int i=0; i<list.count(); i++)
     {
        if(!list[i].isLoopback())
        if (list[i].protocol() == QAbstractSocket::IPv4Protocol )
        {
        return list[i].toString();

        }
     }

     //si no encuentra ninguna direccion IP
     return "null";
}

bool between(QUuid n1, QUuid n2, QUuid n3)
{
    if (n1<n3)   return (n1<n2 && n2<n3);
    else         return (n1<n2 || n2<n3);
}

QUuid assignGuid(QUuid local, QUuid successor)
{
    QUuid guid;

    do
    {
        guid=QUuid::createUuid();
    }

    while (!between(local,guid,successor));

    return guid;
}

void cipherFile(QFile *file)
{
    if(!file->open(QIODevice::ReadWrite))
    {
       qDebug() << "Could not open " << file->fileName();
    }

    else
    {
        QByteArray cipher=file->readAll();
        file->resize(file->fileName(),0);
        file->write(cipher.toHex());
    }
}

quint16 get_random_port()
{
    QTcpServer sockete;
    sockete.listen(QHostAddress::Any,0);
    qDebug()<<"Free port: "+QString::number(sockete.serverPort());
    return sockete.serverPort();
}

void appendAddress(QString ip, quint16 port)
{
    QFile file(QDir::currentPath().append("/addr.dat"));
    QByteArray autoJoinAdresses;
    bool add=true;
    QString ip_n;
    quint16 port_n;

    //read all
    file.open(QIODevice::ReadOnly);
    autoJoinAdresses=file.readAll();
    file.close();

    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);

       while (!in.atEnd())
       {
         QString line = in.readLine();

         QStringList dataList=line.split("_");
         qDebug()<<dataList;

         ip_n=dataList[0];
         port_n=dataList[1].toInt();

         if(ip_n==ip && port_n==port)
         {
             qDebug()<<"direccion ya existe en el archivo!";
             add=false;
         }
       }

       if(add)
       {
          qDebug()<<"adding new address to file...";

          //autoJoinAdresses.append(ip).append("_").append(QByteArray::number(port)).append("\n");
          QByteArray data=ip.toUtf8().append("_").append(QByteArray::number(port)).append("\n");
          file.close();
          file.open(QIODevice::Append);
          file.write(data);
          file.close();
       }
    }
}
