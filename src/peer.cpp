#include "peer.h"

Peer::Peer(QObject *parent) : QTcpServer(parent){}

Peer::Peer(QUuid guid, QHostAddress local_ip, quint16 local_port, QHostAddress predecessor_ip, quint16 predecessor_port, QHostAddress successor_ip, quint16 successor_port): guid_m(guid),local_ip_m(local_ip), local_port_m(local_port), predecessor_ip_m(predecessor_ip), predecessor_port_m(predecessor_port), successor_ip_m(successor_ip), successor_port_m(successor_port)
{
    successor_guid_m   = QUuid();
    predecessor_guid_m = QUuid();

    //aux data
    aux_successor_guid_m = QUuid();
    aux_successor_ip_m   = QHostAddress();
    aux_successor_port_m = 0000;
}

void Peer::show()
{
    qDebug()<< "\n    § PEER INFO";
    qDebug()<< "    guid: "<< guid_m.toString();
    qDebug()<< "    ip:   "<<local_ip_m.toString()<<" : "<<local_port_m;
    qDebug()<< "    predecessor: "<<predecessor_ip_m.toString()<<" : "<<predecessor_port_m<<" >> "<<predecessor_guid_m.toString();
    qDebug()<< "    successor:   "<<successor_ip_m.toString()<<" : "<<successor_port_m<<" >> "<<successor_guid_m.toString()<<"\n";
    qDebug()<< " auxsuccessor:   "<<aux_successor_ip_m.toString()<<" : "<<aux_successor_port_m<<" >> "<<aux_successor_guid_m.toString()<<"\n";

}

bool Peer::ping(const QString ip, const quint16 port)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(QHostAddress(ip), port);

    qDebug() << "ping to: "+ip+" : "<<port;

    if(!socket->waitForConnected(9000))
    {
        qDebug() << "Error: " << socket->errorString();
        return false;
    }

    else
    {
        qDebug() << "Ping to: "+ip+" OK";
        return true;
        socket->disconnectFromHost();
    }
}

bool Peer::listenPing(const QString ip, const quint16 port)
{
    QTcpServer server;
    server.listen(QHostAddress::AnyIPv4,port);

    qDebug() << "listening on port: "<<port;

    if(!server.waitForNewConnection(9000))
    {
        qDebug() << "Error: " << server.errorString();
        return false;
    }

    else
    {
        qDebug() << "Listening to: "+ip+" OK";
        server.disconnect();
        return true;
    }
}

void Peer::join()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(predecessor_ip_m, predecessor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug() << "joining to:"<<predecessor_ip_m<<" : "<<predecessor_port_m;

        socket->write("JOIN");
        socket->waitForBytesWritten();

        /*             [0]           [1]             [2]              [3]           [4] */
        //reading successorGuid : successorIP : successorPort : predecessorGuid : newGuid
        socket->waitForReadyRead();
        QByteArray data=socket->readAll();

        //parse data
        QString data_st=QString::fromStdString(data.toStdString());
        QStringList dataList=data_st.split(":");

        //setting successor
        setSuccessor(QUuid(dataList[0]),QHostAddress(dataList[1]),dataList[2].toInt());

        //setting predecessor
        setPredecessor(dataList[3], predecessor_ip_m, predecessor_port_m);

        //setting node Guid
        setGuid(dataList[4]);

        /*          [0]       [1] */
        //sending nodeIP : nodePort
        QByteArray QBport;
        socket->write(local_ip_m.toString().toUtf8().append(":").append(QBport.setNum(local_port_m)));
        socket->waitForBytesWritten();

        //add blockchain
        socket->waitForReadyRead();
        QByteArray bc=socket->readAll();
        setBlockchain(bc);
    }

    socket->disconnectFromHost();

    auxilium();
}

void Peer::stabilize()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //use auxiliary successor
        setSuccessor(aux_successor_guid_m,aux_successor_ip_m,aux_successor_port_m);
        socket->disconnectFromHost();
        stabilize();
    }

    else
    {
        socket->write("STBL");
        socket->waitForBytesWritten();

        /*                 [0]           [1]     */
        //reading     suc_pre guid   suc_suc guid
        socket->waitForReadyRead();
        QByteArray data = socket->readAll();

        //parse data
        QString data_st=QString::fromStdString(data.toStdString());
        QStringList dataList=data_st.split(":");

        QUuid suc_pre=QUuid(dataList[0]);
        QUuid suc_suc=QUuid(dataList[1]);

        if(suc_pre != guid_m)
        {
            qDebug()<<"Different guids.. notify";

            socket->disconnectFromHost();
            rectify();
        }

        else
        {
            //qDebug()<<"same guids :)";
            //do nothing...
            //socket->disconnectFromHost();

            if(suc_suc != aux_successor_guid_m)
            {
                socket->disconnectFromHost();
                auxilium();
            }

            else
            {
                //qDebug()<<"same aux guids :)";
                //do nothing...
                socket->disconnectFromHost();
            }
        }  

       emit setWidget(this);
    }
}

void Peer::rectify()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug()<<"sending rectify...";

        socket->write("RECT");
        socket->waitForBytesWritten();

        //espera para escribir...
        socket->waitForReadyRead();

        /*              [0]     [1]   [2]*/
        //sending    nodeGuid   ip   port
        QByteArray QBport;
        socket->write(getGuid().toByteArray().append(":").append(local_ip_m.toString()).append(":").append(QBport.setNum(local_port_m)) );
    }

    socket->disconnectFromHost();
}

void Peer::auxilium()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug()<<"auxilium...";

        socket->write("AUX");
        socket->waitForBytesWritten();

        /*                 [0]           [1]          [2]*/
        //reading     aux_suc guid   aux_suc ip   aux_suc port
        socket->waitForReadyRead();
        QByteArray data = socket->readAll();

        //parse data
        QString data_st=QString::fromStdString(data.toStdString());
        QStringList dataList=data_st.split(":");

        setAuxiliarySuccessor(QUuid(dataList[0]), QHostAddress(dataList[1]), dataList[2].toInt());
    }

    socket->disconnectFromHost();
}

 void Peer::broadcastBlock(Block bloque,QByteArray guid)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //retry operation with new successor
        switchSuccessor();
        broadcastBlock(bloque,guid);
    }

    else
    {
        socket->write("BBLCK");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send peer guid
        socket->write(guid);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //write block data  0:data 1:hash 2:link 3:nonce 4:previousHash 5: timeStamp
        socket->write(bloque.getData().append(":").append(bloque.getHash()).append(":").append(bloque.getLink()).append(":").append(QByteArray::number(bloque.getNonce())).append(":").append(bloque.getPreviousHash()).append(":").append(QByteArray::number(bloque.getTimeStamp())));
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

QByteArray Peer::loadBlockchain()
{
    //read file to send
    QFile file(QDir::currentPath().append("/bc.json"));

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open " << file.fileName();
        return 0;
    }

    else
    {
        QByteArray data=file.readAll();
        return data;
    }
}

void Peer::setBlockchain(QByteArray blockchain)
{
    QFile file(QDir::currentPath().append("/bc.json"));

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Can't open file for written";
    }

    else
    {
        file.write(blockchain);
        file.close();
    }

    qDebug() << "blockchain size: " << file.size()<<"\n";
}

void Peer::blocksFromChain(QByteArray data)
{
    QFile file(QDir::currentPath().append("/bc.json"));

    if(!file.open(QIODevice::ReadOnly))
    {
       qDebug() << "Could not open " << file.fileName();
    }

    else
    {
        //read entire blockchain;
        QByteArray blockchain=file.readAll();

        //parse blockchain into document
        QJsonDocument doc=QJsonDocument::fromJson(blockchain);

        //parse document into QJsonObject
        QJsonObject chain=doc.object();

        file.close();

        //iterate chain
        for(int i=1;i<chain.size();i++)
        {
            QByteArray blockData=chain["Block #"+QString::number(i)].toObject().value("data").toString().toUtf8();

            //check if block includes "data"
            if(blockData == data)
            {
                QByteArray link=chain["Block #"+QString::number(i)].toObject().value("link").toString().toUtf8();

                //broadcast a request for file (link)
                requestFile(link,getGuid().toByteArray());
            }
        }
    }
}

void Peer::requestFile(QByteArray link, QByteArray guid)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //retry operation with new successor
        switchSuccessor();
        requestFile(link,guid);
    }

    else
    {
        socket->write("REQF");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send peer info  [0] guid [1] ip   [2] port
        socket->write(guid.append(":").append(getLocalIP().toString().toUtf8()).append(":").append(QString::number(getLocalPort()).toUtf8()));
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send link
        socket->write(link);
        socket->waitForBytesWritten();

        //sync
        //socket->waitForReadyRead();
    }

    socket->disconnectFromHost();
}

void Peer::sendHealthRecord(QHostAddress ip, quint16 port, QByteArray link)
{
    //read file to send
    QFile file(QDir::currentPath().append("/data/").append(link));

    if(!file.open(QIODevice::ReadOnly))
      {
          qDebug() << "Could not open " << file.fileName();
      }

    else
    {
        QByteArray healthRecord=file.readAll();
        file.close();

        QTcpSocket *socket = new QTcpSocket();
        socket->connectToHost(ip, port);

        if(!socket->waitForConnected())
        {
            qDebug() << "Error: " << socket->errorString();
        }

        else
        {
            socket->write("FILE");
            socket->waitForBytesWritten();

            //sync
            socket->waitForReadyRead();

            //sending link (file name)
            socket->write(link);
            socket->waitForBytesWritten();

            //sync
            socket->waitForReadyRead();

            //sending file size
            socket->write(QByteArray::number(healthRecord.size()));
            socket->waitForBytesWritten();

            //sync
            socket->waitForReadyRead();

            //sending file
            socket->write(healthRecord,healthRecord.size());
            socket->waitForBytesWritten();
        }

        socket->disconnectFromHost();
    }
}

void Peer::obtainPatient(QUuid guid, QHostAddress ip, quint16 port, QByteArray uid)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //retry operation with new successor
        switchSuccessor();
        obtainPatient(guid, ip, port, uid);
    }

    else
    {
        socket->write("OBP");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send [0]guid  [1] ip  [2] port  [3] uid
        socket->write(guid.toByteArray().append(":").append(ip.toString().toUtf8()).append(":").append(QString::number(port).toUtf8()).append(":").append(uid));
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

void Peer::sendPatient(QHostAddress ip, quint16 port, QByteArray uid)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(ip, port);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug() << "Sending patient!";

        socket->write("APT");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send patient info
        QSqlQuery query;
        query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

        if(!query.exec())
        {
            QMessageBox *box=new QMessageBox();
            QMessageBox::warning(box, "QUERY ERROR",query.lastError().text());
        }

        if(query.first())
        {
            //patient's personal information
            QByteArray cedula=query.value(0).toByteArray();
            QByteArray nombres=query.value(1).toByteArray();
            QByteArray apellidos=query.value(2).toByteArray();
            QByteArray lugar=query.value(3).toByteArray();
            QByteArray fecha=query.value(4).toByteArray();
            QByteArray sexo=query.value(5).toByteArray();
            QByteArray eps=query.value(6).toByteArray();
            QByteArray rfid=query.value(7).toByteArray();

            QByteArray patient=cedula.append(":").append(nombres).append(":").append(apellidos).append(":").append(lugar).append(":").append(fecha).append(":").append(sexo).append(":").append(eps).append(":").append(rfid);

            socket->write(patient);
            socket->waitForBytesWritten();
        }
    }

    socket->disconnectFromHost();
}

void Peer::backupBlock(QByteArray receiver, QByteArray link)
{
    QTcpSocket *socket = new QTcpSocket();

    if(receiver=="SUCCESSOR")
    {
        socket->connectToHost(successor_ip_m, successor_port_m);

    }

    else     /*AUX_SUCCESSOR*/
    {
        socket->connectToHost(aux_successor_ip_m, aux_successor_port_m);

    }

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        socket->write("BCKPB");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //read health record
        QFile file(QDir::currentPath().append("/data/").append(link));
        QByteArray healthRecord;

        if (!file.open(QIODevice::ReadOnly))
        {
           qDebug() << "Can't open file for read";
        }

        else
        {
            healthRecord=file.readAll();
            file.close();
        }

        //send filename (link)
        socket->write(link);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send health record
        socket->write(healthRecord);
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

void Peer::backupPatient(QByteArray receiver, QByteArray patientInfo)
{
    QTcpSocket *socket = new QTcpSocket();

    if(receiver=="SUCCESSOR")
    {
        socket->connectToHost(successor_ip_m, successor_port_m);

    }

    else //AUX_SUCCESSOR
    {
        socket->connectToHost(aux_successor_ip_m, aux_successor_port_m);

    }

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        socket->write("BCKPP");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send patient info
        socket->write(patientInfo);
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

void Peer::backupProfessional(QByteArray receiver, QByteArray professionalInfo)
{
    QTcpSocket *socket = new QTcpSocket();

    if(receiver=="SUCCESSOR")
    {
        socket->connectToHost(successor_ip_m, successor_port_m);

    }

    else //AUX_SUCCESSOR
    {
        socket->connectToHost(aux_successor_ip_m, aux_successor_port_m);

    }

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        socket->write("BCKPPR");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send professional info
        socket->write(professionalInfo);
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

void Peer::switchSuccessor()
{
    //update successor
    setSuccessor(aux_successor_guid_m, aux_successor_ip_m, aux_successor_port_m);

    //request new auxiliary successor
    auxilium();
}

void Peer::purgeBlocks(QByteArray guid)
{
    //send link (file name) that this node has
    QFile file(QDir::currentPath().append("/bc.json"));

    //useful data
    QByteArray links="zero";
    quint8 linkCounter=0;

    if(!file.open(QIODevice::ReadOnly))
    {
       qDebug() << "Could not open " << file.fileName();
    }

    else
    {
        //read entire blockchain;
        QByteArray blockchain=file.readAll();

        //parse blockchain into document
        QJsonDocument doc=QJsonDocument::fromJson(blockchain);

        //parse document into QJsonObject
        QJsonObject chain=doc.object();

        file.close();

        //iterate chain
        for(int i=1;i<chain.size();i++)
        {
            QByteArray link=chain["Block #"+QString::number(i)].toObject().value("link").toString().toUtf8();

            QFile dataFile(QDir::currentPath().append("/data/").append(link));

            //check if link file exists locally
            if(dataFile.exists())
            {
                //append link to be send
                links.append(":");
                links.append(link);
                linkCounter++;
            }
         }
      }

    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //retry operation with new successor
        switchSuccessor();
        purgeBlocks(guid);
    }

    else
    {
        socket->write("PURGE");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send number of links
        socket->write(QByteArray::number(linkCounter));
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send links (link:link:link ....)
        socket->write(links);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send guid
        socket->write(guid);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        socket->disconnectFromHost();
    }
}

void Peer::purgeUsers(QByteArray guid)
{
    QSqlQuery query;
    quint8 sizePatient, sizeProfessional,counterPatient=0,counterProfessional=0;
    QByteArray cedula="zero";
    QByteArray tarjeta="zero";

    //number of rows from patient table
    query.exec("SELECT count(*) FROM patient");
    query.first();
    sizePatient=query.value(0).toInt();

    //number of rows from patient table
    query.exec("SELECT count(*) FROM professional");
    query.first();
    sizeProfessional=query.value(0).toInt();

    //get cedulas from table
    for(int i=0;i<sizePatient;i++)
    {
        query.exec("SELECT cedula FROM patient WHERE id = "+QString::number(i)+" ");

        //if row exists in table
        if(query.first())
        {
            cedula.append(":").append(query.value(0).toByteArray());
            counterPatient++;
        }
    }

    //get tarjetas from table
    for(int i=0;i<sizeProfessional;i++)
    {
        query.exec("SELECT tarjeta FROM professional WHERE id = "+QString::number(i)+" ");

        //if row exists in table
        if(query.first())
        {
            tarjeta.append(":").append(query.value(0).toByteArray());
            counterProfessional++;
        }
    }

    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();

        //retry operation with new successor
        switchSuccessor();
        purgeBlocks(guid);
    }

    else
    {
        socket->write("PURGEU");
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send number of cedulas
        socket->write(QByteArray::number(counterPatient));
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send number of tarjetas
        socket->write(QByteArray::number(counterProfessional));
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send cedulas
        socket->write(cedula);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send tarjetas
        socket->write(tarjeta);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        //send guid
        socket->write(guid);
        socket->waitForBytesWritten();

        //sync
        socket->waitForReadyRead();

        socket->disconnectFromHost();
    }
}

void Peer::backupLinks(QByteArray receiver)
{
    //send link files that this node has
    QFile file(QDir::currentPath().append("/bc.json"));

    if(!file.open(QIODevice::ReadOnly))
    {
       qDebug() << "Could not open " << file.fileName();
    }

    else
    {
        //read entire blockchain;
        QByteArray blockchain=file.readAll();

        //parse blockchain into document
        QJsonDocument doc=QJsonDocument::fromJson(blockchain);

        //parse document into QJsonObject
        QJsonObject chain=doc.object();

        file.close();

        QByteArray healthRecord;

        //iterate chain
        for(int i=1;i<chain.size();i++)
        {
            QByteArray link=chain["Block #"+QString::number(i)].toObject().value("link").toString().toUtf8();

            QFile dataFile(QDir::currentPath().append("/data/").append(link));

            //check if link file exists locally
            if(dataFile.exists())
            {
                //send block
                backupBlock(receiver,link);
            }
         }
    }
}

void Peer::backupUsers()
{
    QSqlQuery query;
    quint8 sizePatient, sizeProfessional;

    //number of rows from patient table
    query.exec("SELECT count(*) FROM patient");
    query.first();
    sizePatient=query.value(0).toInt();

    //number of rows from patient table
    query.exec("SELECT count(*) FROM professional");
    query.first();
    sizeProfessional=query.value(0).toInt();

    //backup patient
    for(int i=0;i<sizePatient;i++)
    {
        query.exec("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps,rfid,timestamp FROM patient WHERE id = "+QString::number(i)+" ");

        //if row exists in table
        if(query.first())
        {
            //patient's personal information
            QByteArray cedula=query.value(0).toByteArray();
            QByteArray nombres=query.value(1).toByteArray();
            QByteArray apellidos=query.value(2).toByteArray();
            QByteArray lugar=query.value(3).toByteArray();
            QByteArray fecha=query.value(4).toByteArray();
            QByteArray sexo=query.value(5).toByteArray();
            QByteArray eps=query.value(6).toByteArray();
            QByteArray rfid=query.value(7).toByteArray();
            QByteArray timestamp=query.value(8).toByteArray();

            QByteArray patientInfo=cedula.append(":").append(nombres).append(":").append(apellidos).append(":").append(lugar).append(":").append(fecha).append(":").append(sexo).append(":").append(eps).append(":").append(rfid).append(":").append(timestamp);

            backupPatient("SUCCESSOR",patientInfo);
            backupPatient("PREDECESSOR",patientInfo);
        }
    }

    //backup professional
    for(int i=0;i<sizeProfessional;i++)
    {
        query.exec("SELECT nombre,ips,tarjeta,timestamp FROM professional WHERE id = "+QString::number(i)+" ");

        //if row exists in table
        if(query.first())
        {
            //patient's personal information
            QByteArray nombre=query.value(0).toByteArray();
            QByteArray ips=query.value(1).toByteArray();
            QByteArray tarjeta=query.value(2).toByteArray();
            QByteArray timestamp=query.value(3).toByteArray();

            QByteArray professionalInfo=nombre.append(":").append(ips).append(":").append(tarjeta).append(":").append(timestamp);

            backupProfessional("SUCCESSOR",professionalInfo);
            backupProfessional("PREDECESSOR",professionalInfo);
        }
    }
}

void Peer::requestBaseGuid(const QString ip, const quint16 port)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(QHostAddress(ip), port);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug() << "Requesting Base Guid to:"<<ip<<" : "<<port<<" OK";

        socket->write("BGUID");
        socket->waitForBytesWritten();

        //reading baseGuid : nodeGuid
        socket->waitForReadyRead();
        QByteArray request=socket->readAll();

        //parse data
        QString request_st=QString::fromStdString(request.toStdString());
        QStringList data=request_st.split(":");

        //setting node base guid
        setGuid(QUuid(data.at(0)));

        //setting successor & predecessor
        setSuccessorGuid(QUuid(data.at(1)));
        setPredecessorGuid(QUuid(data.at(1)));

        //sync
        socket->write("OK");
        socket->waitForBytesWritten();

        //get blockchain
        socket->waitForReadyRead();
        QByteArray blockchain=socket->readAll();
        setBlockchain(blockchain);
    }

    socket->disconnectFromHost();

}

QUuid Peer::newBaseGuid(QUuid nodeGuid)
{
    QUuid baseGuid;

    do
    {
        baseGuid=QUuid::createUuid();
    }

    while(!(baseGuid > nodeGuid) );

    return baseGuid;
}

void Peer::leaveSuccessor()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(successor_ip_m, successor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug() << "leaving successor";

        socket->write("SLV");
        socket->waitForBytesWritten();

        //espera para escribir...
        socket->waitForReadyRead();

        /*              [0]            [1]   [2]*/
        //sending    PredecessorGuid   ip   port
        QByteArray QBport;
        socket->write(predecessor_guid_m.toByteArray().append(":").append(predecessor_ip_m.toString()).append(":").append(QString::number(predecessor_port_m).toUtf8()) );
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

void Peer::leavePredecessor()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost(predecessor_ip_m, predecessor_port_m);

    if(!socket->waitForConnected())
    {
        qDebug() << "Error: " << socket->errorString();
    }

    else
    {
        qDebug() << "leaving predecessor";

        socket->write("PLV");
        socket->waitForBytesWritten();

        //espera para escribir...
        socket->waitForReadyRead();

        /*              [0]            [1]   [2]*/
        //sending    SuccessorGuid     ip   port
        QByteArray QBport;
        socket->write(successor_guid_m.toByteArray().append(":").append(successor_ip_m.toString()).append(":").append(QBport.setNum(successor_port_m)) );
        socket->waitForBytesWritten();
    }

    socket->disconnectFromHost();
}

QByteArray Peer::loadDatabase()
{
    //read file to send
    QFile file(QDir::currentPath().append("/patient.db"));
       
    if(!file.open(QIODevice::ReadOnly))
      {
          qDebug() << "Could not open " << file.fileName();
          return "error";
      }

    else
    {
        QByteArray data=file.readAll();
        return data;
    }
}

void Peer::setDatabase(QByteArray database)
{
    QFile file(QDir::currentPath().append("/patient.db"));

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Can't open file for written";
    }

    else
    {
        file.write(database);
        file.close();
    }

    qDebug() << "database size: " << file.size()<<"\n";
}

void Peer::incomingConnection(qintptr socketDescriptor)
{
    QtConcurrent::run(this,&Peer::manageConnection,socketDescriptor);
}

void Peer::manageConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(socketDescriptor))
    {
        qDebug()<< socket->errorString();
    }

    //code for reading and using macros operations
    socket->waitForReadyRead();
    QByteArray request = socket->readAll();

    QString request_st=QString::fromStdString(request.toStdString());
    QMetaObject MetaObject = this->staticMetaObject;
    QMetaEnum MetaEnum = MetaObject.enumerator(MetaObject.indexOfEnumerator("Request"));

    switch(MetaEnum.keysToValue(request_st.toLatin1()))
    {

        case BGUID:
        {
            qDebug()<< "sending base guid!";

            QUuid baseGuid=newBaseGuid(getGuid());

            /*              [0]       [1]   */
            //writing    baseGuid : nodeGuid
            socket->write(baseGuid.toByteArray().append(":").append(getGuid().toByteArray()));
            socket->waitForBytesWritten();

            //setting succesor & predecessor guid
            setSuccessorGuid(baseGuid);
            setPredecessorGuid(baseGuid);

            //sync
            socket->waitForReadyRead();

            //sending blockchain
            socket->write(loadBlockchain());
            socket->waitForBytesWritten();

            break;
        }

        case JOIN:
        {
            qDebug()<< "joining node!";

            /*               [0]           [1]             [2]            [3]             [4]  */
            //sending    successorGuid : successorIP : successorPort : predecessorGuid : newGuid
            socket->write(successor_guid_m.toByteArray().append(":").append(successor_ip_m.toString().toUtf8()).append(":").append(QString::number(successor_port_m).toUtf8() ).append(":").append(predecessor_guid_m.toByteArray()).append(":").append(assignGuid(getGuid(),successor_guid_m).toByteArray()));
            socket->waitForBytesWritten();           

            /*               [0]            [1]    */
            //reading    successorIP : successorPort
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();

            //parse data
            QString data_st=QString::fromStdString(data.toStdString());
            QStringList dataList=data_st.split(":");

            //setting new successor
            setSuccessor(assignGuid(getGuid(),successor_guid_m),QHostAddress(dataList[0]),dataList[1].toInt());

            //sending blockchain
            socket->write(loadBlockchain());
            socket->waitForBytesWritten();

            break;
        }

        case STBL:
        {
            //                [0]               [1]
            //sending   predecessor guid   successor guid
            socket->write(predecessor_guid_m.toByteArray().append(":").append(successor_guid_m.toByteArray()));
            socket->waitForBytesWritten();

            break;
         }

        case RECT:
        {
            qDebug()<<"rectifying!";

            socket->write("OK");
            socket->waitForBytesWritten();

            /*              [0]     [1]     [2]*/
            //reading     nodeGuid   ip    port
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();

            //parse data
            QString data_st=QString::fromStdString(data.toStdString());
            QStringList dataList=data_st.split(":");

            //setting rectified predecessor
            setPredecessor(QUuid(dataList[0]),QHostAddress(dataList[1]),dataList[2].toInt());

            socket->disconnectFromHost();

            //backup blocks because predecessor changed
            backupLinks("SUCCESSOR");
            backupLinks("PREDECESSOR");

            //backup users
            QtConcurrent::run(this,&Peer::backupUsers);

            break;
        }

        case SLV:
            {
                qDebug()<<"setting new predecessor!";

                socket->write("OK");
                socket->waitForBytesWritten();

                /*              [0]     [1]     [2]*/
                //reading     nodeGuid   ip    port
                socket->waitForReadyRead();
                QByteArray data = socket->readAll();

                //parse data
                QString data_st=QString::fromStdString(data.toStdString());
                QStringList dataList=data_st.split(":");

                //setting rectified predecessor
                setPredecessor(QUuid(dataList[0]),QHostAddress(dataList[1]),dataList[2].toInt());

                break;
            }

        case PLV:
            {
                qDebug()<<"setting new successor!";

                socket->write("OK");
                socket->waitForBytesWritten();

                /*              [0]     [1]     [2]*/
                //reading     nodeGuid   ip    port
                socket->waitForReadyRead();
                QByteArray data = socket->readAll();

                //parse data
                QString data_st=QString::fromStdString(data.toStdString());
                QStringList dataList=data_st.split(":");

                //setting rectified predecessor
                setSuccessor(QUuid(dataList[0]),QHostAddress(dataList[1]),dataList[2].toInt());

                break;
            }

        case AUX:
            {
                qDebug()<<"sending auxiliary successor!";

                /*               [0]           [1]             [2]      */
                //sending    successorGuid  successorIP   successorPort
                socket->write(successor_guid_m.toByteArray().append(":").append(successor_ip_m.toString().toUtf8()).append(":").append(QString::number(successor_port_m).toUtf8() ) );
                socket->waitForBytesWritten();

                break;
            }

        case BBLCK:
        {
            qDebug()<<"reading block!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading broadcast Guid
            socket->waitForReadyRead();
            QByteArray broadcastGuid = socket->readAll();
            //qDebug()<<broadcastGuid;

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading new block
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();
            //qDebug()<<data;

            //parse data
            QString data_st=QString::fromStdString(data.toStdString());
            QStringList dataList=data_st.split(":");

            //qDebug()<<"bcastGuid  "+QString::fromStdString(broadcastGuid.toStdString())+"<>"+" guid "+guid_m.toString();

            if(QUuid(broadcastGuid) != guid_m)
            {
                socket->disconnectFromHost();

                //insert block into chain
                Block bloque(dataList[0].toLocal8Bit(),dataList[1].toLocal8Bit(), dataList[2].toLocal8Bit(), dataList[3].toInt(), dataList[4].toLocal8Bit(), dataList[5].toInt());
                bloque.insertData();
                insertBlock(bloque);

                //qDebug()<<"agregando bloque>>\n";
                //keep broadcasting
                broadcastBlock(bloque,broadcastGuid);
            }

            else
            {
                //do nothing...
               // qDebug()<<"yo lo mande!";
            }

            break;
        }

        case REQF:
        {
            qDebug()<<"file requested!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading node info  [0] guid  [1]ip   [2]port
            socket->waitForReadyRead();
            QByteArray node = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading link
            socket->waitForReadyRead();
            QByteArray link = socket->readAll();

            //parse data
            QString info_st=QString::fromStdString(node.toStdString());
            QStringList dataList=info_st.split(":");

            //requesting guid
            QUuid guid=QUuid(dataList[0]);

            //node info
            QHostAddress ip=QHostAddress(dataList[1]);
            quint16 port=dataList[2].toInt();

            if(guid_m!=guid)
            {
                //chech if link file exists
                QFile file(QDir::currentPath().append("/data/").append(link));

                if(file.exists())
                {
                    qDebug()<<"existe";
                    //send file to the requesting peer
                    socket->disconnectFromHost();
                    sendHealthRecord(ip,port,link);
                }

                else
                {
                    qDebug()<<"no existe";
                    //keep bradcasting the file request
                    socket->disconnectFromHost();
                    requestFile(link,guid.toByteArray());
                }
            }

            else
            {
                //emit display signal beacuse this node broadcasted
                emit displayRecord();
            }

            break;
        }

        case FILE:
        {
            qDebug()<<"fetching file!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading link (fileName)
            socket->waitForReadyRead();
            QByteArray link = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading health record size
            socket->waitForReadyRead();
            QByteArray size = socket->readAll();
            qDebug()<<size;

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();


            //reading data by chunks
            QByteArray healthRecord;
            qint64 totalBytesRead = 0;
            while(totalBytesRead < size.toInt())
            {
                if (socket->waitForReadyRead())
                {
                    qint64 bytesAvailable = socket->bytesAvailable();
                    totalBytesRead += bytesAvailable;

                    healthRecord.append(socket->read(bytesAvailable));
                }
             }

            qDebug()<<"Bytes Sent    >>"+size;
            qDebug()<<"Bytes Received>>"+totalBytesRead;

            //save file in temp folder
            QFile file(QDir::currentPath().append("/temp/").append(link));

            if (!file.open(QIODevice::WriteOnly))
            {
               qDebug() << "Can't open file for written";
            }

            else
            {
                file.write(healthRecord);
                file.close();
                emit displayRecord();
            }

            break;
        }

        case OBP:
        {
            qDebug()<<"patient request!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading [0]guid  [1] ip  [2] port  [3] uid
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();

            //parse data
            QString data_st=QString::fromStdString(data.toStdString());
            QStringList dataList=data_st.split(":");

            //assign data
            QUuid guid=QUuid(dataList[0]);
            QHostAddress ip=QHostAddress(dataList[1]);
            quint16 port=dataList[2].toInt();
            QByteArray uid=dataList[3].toUtf8();

            if(guid != guid_m)
            {
                //look for patient in database
                QSqlQuery query;
                query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

                if(!query.exec())
                {
                    QMessageBox *box=new QMessageBox();
                    QMessageBox::warning(box, "QUERY ERROR",query.lastError().text());
                }

                //if patient exists
                if(query.first())
                {
                    socket->disconnectFromHost();

                    //send patient to requestee
                    sendPatient(ip,port,uid);
                }

                else
                {
                    socket->disconnectFromHost();

                    //keep broadcasting
                    obtainPatient(guid,ip,port,uid);
                }
            }

            else
            {
                //do nothing...
                //qDebug()<<"yo lo mande!";
            }

            break;
        }

        case APT:
        {
            qDebug()<<"Adding new patient!";

            socket->write("OK");
            socket->waitForBytesWritten();

            //reading patient info
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();

            //parse data
            QString data_st=QString::fromStdString(data.toStdString());
            QStringList dataList=data_st.split(":");


            //patient's personal information
            QString cedula=dataList[0];
            QString nombres=dataList[1];
            QString apellidos=dataList[2];
            QString lugar=dataList[3];
            QString fecha=dataList[4];
            QString sexo=dataList[5];
            QString eps=dataList[6];
            QString rfid=dataList[7];

            //add patient using query
            QSqlQuery query;
            QString  consulta;

            consulta.append("INSERT INTO patient"
                            "(cedula, nombres, apellidos, lugar, fecha, sexo, eps,rfid)"
                            "VALUES("
                            "'"+cedula+"',"
                            "'"+nombres+"',"
                            "'"+apellidos+"',"
                            "'"+lugar+"',"
                            "'"+fecha+"',"
                            "'"+sexo+"',"
                            "'"+eps+"',"
                            "'"+rfid+"')");

            if(query.exec(consulta))
            {
                qDebug()<<"El paciente con cedula: "+cedula+".Ha sido añadido satisfactoriamente!";

            }

            else
            {
                qDebug()<<"El paciente con cedula: "+cedula+".No ha sido añadido...";
            }

            break;
        }

        case BCKPB:
        {
            qDebug()<<"backup file!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading link (fileName)
            socket->waitForReadyRead();
            QByteArray link = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading single health record
            socket->waitForReadyRead();
            QByteArray healthRecord = socket->readAll();

            //save file in data folder
            QFile file(QDir::currentPath().append("/data/").append(link));

            if (!file.open(QIODevice::WriteOnly))
            {
               qDebug() << "Can't open file for written";
            }

            else
            {
                file.write(healthRecord);
                file.close();
            }

            break;
        }

        case BCKPP:
        {
            qDebug()<<"backup patient!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading patient info
            socket->waitForReadyRead();
            QByteArray patientInfo = socket->readAll();

            //parse data
            QString data=QString::fromUtf8(patientInfo);
            QStringList dataList=data.split(":");

            //patient's personal information
            QString cedula=dataList[0];
            QString nombres=dataList[1];
            QString apellidos=dataList[2];
            QString lugar=dataList[3];
            QString fecha=dataList[4];
            QString sexo=dataList[5];
            QString eps=dataList[6];
            QString rfid=dataList[7];
            QString timestamp=dataList[8];

            //add patient using query
            QSqlQuery query;
            QString consulta;

            consulta.append("REPLACE INTO patient"
                            "(cedula, nombres, apellidos, lugar, fecha, sexo, eps, rfid, timestamp)"
                            "VALUES("
                            "'"+cedula+"',"
                            "'"+nombres+"',"
                            "'"+apellidos+"',"
                            "'"+lugar+"',"
                            "'"+fecha+"',"
                            "'"+sexo+"',"
                            "'"+eps+"',"
                            "'"+rfid+"',"
                            "'"+timestamp+"')");

            if(query.exec(consulta))
            {
                qDebug()<<"El paciente con cedula: "+cedula+".Ha sido añadido satisfactoriamente!";

            }

            else
            {
                qDebug()<<"El paciente con cedula: "+cedula+".No ha sido añadido...";
            }

            break;
        }

        case BCKPPR:
        {
            qDebug()<<"backup professional!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading professional info
            socket->waitForReadyRead();
            QByteArray professionalInfo = socket->readAll();

            //parse data
            QString data_st=QString::fromStdString(professionalInfo.toStdString());
            QStringList dataList=data_st.split(":");

            //patient's personal information
            QString nombre=dataList[0];
            QString ips=dataList[1];
            QString tarjeta=dataList[2];
            QString timestamp=dataList[3];


            //add patient using query
            QSqlQuery query;
            QString  consulta;

            consulta.append("REPLACE INTO professional"
                            "(nombre, ips, tarjeta, timestamp)"
                            "VALUES("
                            "'"+nombre+"',"
                            "'"+ips+"',"
                            "'"+tarjeta+"',"
                            "'"+timestamp+"')");

            if(query.exec(consulta))
            {
                qDebug()<<"El profesional con nombre: "+nombre+".Ha sido añadido satisfactoriamente!";

            }

            else
            {
                qDebug()<<"El profesional con nombre: "+nombre+".No ha sido añadido...";
            }

            break;
        }

        case PURGE:
        {
            qDebug()<<"Purging BLOCKS!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading number of links
            socket->waitForReadyRead();
            QByteArray linkCounter = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading links
            socket->waitForReadyRead();
            QByteArray links = socket->readAll();

            //parse data
            QStringList dataList=QString::fromUtf8(links).split(":");

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading broadcaster guid
            socket->waitForReadyRead();
            QByteArray guid = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            if(guid != guid_m.toByteArray())
            {
                //erase files
                for(int i=1;i<=linkCounter.toInt();i++)
                {
                    QFile dataFile(QDir::currentPath().append("/data/").append(dataList[i]));

                    if(dataFile.exists())
                    {
                        dataFile.remove();
                    }
                }

                //keep broadcasting
                socket->disconnectFromHost();
                purgeBlocks(guid);
            }

            else
            {
                //stop broadcasting...
            }

            break;
        }

        case PURGEU:
        {
            qDebug()<<"Purging USERS!";

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading number of patients
            socket->waitForReadyRead();
            QByteArray patientCounter = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading number of professionals
            socket->waitForReadyRead();
            QByteArray professionalCounter = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading  cedula:cedula:cedula...
            socket->waitForReadyRead();
            QByteArray data = socket->readAll();

            //parse data
            QStringList cedula=QString::fromUtf8(data).split(":");

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading  tarjeta:tarjeta:tarjeta...
            socket->waitForReadyRead();
            QByteArray data2 = socket->readAll();

            //parse data
            QStringList tarjeta=QString::fromUtf8(data2).split(":");

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            //reading broadcaster guid
            socket->waitForReadyRead();
            QByteArray guid = socket->readAll();

            //sync
            socket->write("OK");
            socket->waitForBytesWritten();

            QSqlQuery query;

            if(guid != guid_m.toByteArray())
            {
                //remove patients from table
                for(int i=1;i<=patientCounter.toInt();i++)
                {
                    if(query.exec("DELETE FROM patient WHERE cedula='"+cedula[i]+"'"))
                    {
                        qDebug()<<"cc: "+cedula[i]+" deleted.";
                    }

                    else
                    {
                       qDebug()<<"cc: "+cedula[i]+" not deleted...";
                    }
                }

                //remove patients from table
                for(int i=1;i<=professionalCounter.toInt();i++)
                {
                    if(query.exec("DELETE FROM professional WHERE tarjeta='"+tarjeta[i]+"'"))
                    {
                        qDebug()<<"tp: "+tarjeta[i]+" deleted.";
                    }

                    else
                    {
                       qDebug()<<"tp: "+tarjeta[i]+" not deleted...";
                    }
                }

                //keep broadcasting
                socket->disconnectFromHost();
                purgeUsers(guid);
            }

            else
            {
                //stop broadcasting...
            }

            break;
        }

        default: {break;}
    }

    socket->disconnectFromHost();
}




//******************************  getters &setters  ***********************************************************




QUuid Peer::getGuid()
{
    return guid_m;
}

QHostAddress Peer::getLocalIP()
{
    return local_ip_m;
}

quint16 Peer::getLocalPort()
{
    return local_port_m;
}

QUuid Peer::getPredecessorGuid()
{
    return predecessor_guid_m;
}

QHostAddress Peer::getPredecessorIP()
{
    return predecessor_ip_m;
}

quint16 Peer::getPredecessorPort()
{
    return predecessor_port_m;
}

QUuid Peer::getSuccessorGuid()
{
    return successor_guid_m;
}

QHostAddress Peer::getSuccessorIP()
{
    return successor_ip_m;
}

quint16 Peer::getSuccessorPort()
{
    return successor_port_m;
}

QUuid Peer::getAuxiliaryGuid()
{
    return aux_successor_guid_m;
}

QHostAddress Peer::getAuxiliaryIP()
{
    return aux_successor_ip_m;
}

quint16 Peer::getAuxiliaryPort()
{
    return aux_successor_port_m;
}

void Peer::setSuccessorGuid(QUuid guid)
{
    successor_guid_m=guid;
}

void Peer::setPredecessorGuid(QUuid guid)
{
    predecessor_guid_m=guid;
}

void Peer::setGuid(QUuid guid)
{
    guid_m=guid;
}

void Peer::setSuccessor(QUuid guid, QHostAddress ip, quint16 port)
{
    successor_guid_m=guid;
    successor_ip_m=ip;
    successor_port_m=port;
}

void Peer::setPredecessor(QUuid guid, QHostAddress ip, quint16 port)
{
    predecessor_guid_m=guid;
    predecessor_ip_m=ip;
    predecessor_port_m=port;
}

void Peer::setAuxiliarySuccessor(QUuid guid, QHostAddress ip, quint16 port)
{
    aux_successor_guid_m=guid;
    aux_successor_ip_m=ip;
    aux_successor_port_m=port;
}
