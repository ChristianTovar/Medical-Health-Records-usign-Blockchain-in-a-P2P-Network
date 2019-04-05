#include "dialogsalida.h"
#include "ui_dialogsalida.h"

DialogSalida::DialogSalida(Peer *mainPeer, QByteArray uid, QString nombre, QString ips, QString cp) : ui(new Ui::DialogSalida), peer(mainPeer)
{
    ui->setupUi(this);

    //professional data
    ui->lineEdit_nombreProfesional->setText(nombre);
    ui->lineEdit_ips->setText(ips);
    ui->lineEdit_tarjeta->setText(cp);

    //add personal data from database
    QSqlQuery query;
    query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

    if(!query.exec())
    {
        QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
        exit(EXIT_FAILURE);
    }

    if(query.first())
    {
        qint64 unixTime=QDateTime::currentSecsSinceEpoch();
        QDateTime dateTime;
        dateTime.setTime_t(unixTime);

        ui->lineEdit_Hora->setText(dateTime.toString());
        ui->lineEdit_Cedula->setText(query.value(0).toString());
        ui->lineEdit_Nombres->setText(query.value(1).toString());
        ui->lineEdit_Apellidos->setText(query.value(2).toString());
        ui->lineEdit_Lugar->setText(query.value(3).toString());
        ui->lineEdit_Fecha->setText(query.value(4).toString());
        ui->lineEdit_Sexo->setText(query.value(5).toString());
        ui->lineEdit_EPS->setText(query.value(6).toString());
        ui->lineEdit_RFID->setText(uid);
    }

    else
    {
        ui->groupBox->setEnabled(true);
    }
}

DialogSalida::~DialogSalida()
{
    delete ui;
}

void DialogSalida::createHealthRecord(QFile *file)
{
    if(!file->open(QIODevice::WriteOnly))
    {
       qDebug() << "Could not open " << file->fileName();
    }

    else
    {
        QTextStream out(file);
        out <<"\tSALIDA PACIENTE\n\n";

        out<<"FECHA/HORA : ";
        out<< ui->lineEdit_Hora->text()+"\n";

        out<<"CEDULA : ";
        out<<ui->lineEdit_Cedula->text()+"\n";

        out<<"NOMBRES : ";
        out<<ui->lineEdit_Nombres->text()+"\n";

        out<<"APELLIDOS : ";
        out<<ui->lineEdit_Apellidos->text()+"\n";

        out<<"RFID : ";
        out<<ui->lineEdit_RFID->text()+"\n";

        out<<"LUGAR DE NACIMIENTO : ";
        out<<ui->lineEdit_Lugar->text()+"\n";

        out<<"FECHA DE NACIMIENTO : ";
        out<<ui->lineEdit_Fecha->text()+"\n";

        out<<"SEXO : ";
        out<<ui->lineEdit_Sexo->text()+"\n";

        out<<"EPS : ";
        out<<ui->lineEdit_EPS->text()+"\n\n";

        out <<"DATOS PROFESIONAL A CARGO\n\n";

        out<<"NOMBRE : ";
        out<<ui->lineEdit_nombreProfesional->text()+"\n";

        out<<"IPS : ";
        out<<ui->lineEdit_ips->text()+"\n";

        out<<"TARJETA PROFESIONAL : ";
        out<<ui->lineEdit_tarjeta->text()+"\n";

        out <<"SALIDA\n\n";

        out<<"RESULTADOS CLINICOS : ";
        out<<ui->plainTextEdit_Resultados->toPlainText()+"\n";

        out<<"FORMULA MEDICA : ";
        out<<ui->plainTextEdit_Formula->toPlainText()+"\n";

        out<<"INCAPACIDADES : ";
        out<<ui->plainTextEdit_Incapacidades->toPlainText()+"\n";

        for(int i=0;i<96;i++)
        {
            out<<"_";
        }

        out<<"\n";

        file->close();
    }

}

void DialogSalida::on_commandLinkButton_clicked()
{
    QString localPath=QDir::currentPath();
    QFile file(QDir::currentPath().append("/data/file.dat"));

    //create patient's medical record
    createHealthRecord(&file);

    //cipher file
    cipherFile(&file);
    file.close();

    //hash the file
    QByteArray fHash;
    fHash=hashFile(&file);
    file.close();

    //rename file with hash
    QDir::setCurrent(QDir::currentPath().append("/data"));
    file.rename(fHash);
    file.close();

    //create Block object  (inputs: (1) previous hash   (2)hash cedula   (3) file hash
    QDir::setCurrent(localPath);
    Block bloque(getLastHash(), QCryptographicHash::hash(ui->lineEdit_Cedula->text().toUtf8(),QCryptographicHash::Sha256).toHex(), fHash);

    //mine the data
    //bloque.mineBlock();
    QtConcurrent::run(&bloque,&Block::mineBlock);

    //insert the data (key & value)
    bloque.insertData();

    //write block into file
    insertBlock(bloque);

    //broadcast block
    peer->broadcastBlock(bloque,peer->getGuid().toByteArray());

    //backup block
    //peer->backupBlock("SUCCESSOR",bloque.getLink());
    //peer->backupBlock("AUX_SUCCESSOR",bloque.getLink());

    //close dialog
    QMessageBox::information(this, "OK :)","Salida añadida satisfactoriamente!");
    this->close();
}
