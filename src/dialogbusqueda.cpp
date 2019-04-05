#include "dialogbusqueda.h"
#include "ui_dialogbusqueda.h"

DialogBusqueda::DialogBusqueda(QByteArray dataPatient) :ui(new Ui::DialogBusqueda), data(dataPatient)
{
    ui->setupUi(this);
}

DialogBusqueda::~DialogBusqueda()
{
    delete ui;
}

void DialogBusqueda::update()
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

        //clear text browser
        ui->textBrowser->clear();

        //iterate chain
        for(int i=1;i<chain.size();i++)
        {
            QByteArray blockData=chain["Block #"+QString::number(i)].toObject().value("data").toString().toUtf8();

            //check if block includes "data"
            if(blockData == data)
            {
                QByteArray link=chain["Block #"+QString::number(i)].toObject().value("link").toString().toUtf8();

                QFile dataFile(QDir::currentPath().append("/data/").append(link));
                QFile tempFile(QDir::currentPath().append("/temp/").append(link));

                //check if link file exists locally
                if(dataFile.exists())
                {
                    if(!dataFile.open(QIODevice::ReadOnly))
                      {
                          qDebug() << "Could not open " << dataFile.fileName();
                      }

                    else
                    {
                        QByteArray cipheredRecord=dataFile.readAll();
                        QByteArray linkHash=QCryptographicHash::hash(cipheredRecord,QCryptographicHash::Sha256).toHex();

                        dataFile.close();

                        if(link==linkHash)
                        {
                            ui->textBrowser->append(QByteArray::fromHex(cipheredRecord));
                        }

                        else
                        {
                            QString text="La siguiente historia ha sido manipulada, y no podra ser usada: ";
                            ui->textBrowser->append(text);
                            ui->textBrowser->append(QString(link));
                            ui->textBrowser->append("________________________________________________________________________________");
                            qDebug()<<"data. error con historia clinica";

                            qDebug()<<"link    >>"+QString::fromUtf8(link);
                            qDebug()<<"linkHash>>"+QString::fromUtf8(linkHash);
                        }                        
                    }

                    continue;
                }

                //chech if link file exists
                else
                {
                    if(tempFile.exists())
                    {

                        if(!tempFile.open(QIODevice::ReadOnly))
                          {
                              qDebug() << "Could not open " << tempFile.fileName();
                          }

                        else
                        {
                            QByteArray cipheredRecord=tempFile.readAll();
                            QByteArray linkHash=QCryptographicHash::hash(cipheredRecord,QCryptographicHash::Sha256).toHex();

                            tempFile.close();

                            if(link==linkHash)
                            {
                                ui->textBrowser->append(QByteArray::fromHex(cipheredRecord));
                            }

                            else
                            {
                                QString text="La siguiente historia ha sido manipulada, y no podra ser usada: ";
                                ui->textBrowser->append(text);
                                ui->textBrowser->append(QString(link));
                                ui->textBrowser->append("____________________________________________________________________________");
                                qDebug()<<"temp. error con historia clinica: ";

                                qDebug()<<"link    >>"+QString::fromUtf8(link);
                                qDebug()<<"linkHash>>"+QString::fromUtf8(linkHash);
                            }
                        }
                    }
                }
            }
        }
    }

    ui->textBrowser->append("       NO HAY MAS INFORMACION PARA MOSTRAR");
}
