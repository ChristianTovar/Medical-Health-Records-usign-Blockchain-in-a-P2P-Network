#include "dialogingreso.h"
#include "ui_dialogingreso.h"
#include <QDebug>


DialogIngreso::DialogIngreso(Peer *mainPeer, QByteArray uid, QString nombre, QString ips, QString cp) : ui(new Ui::DialogIngreso), peer(mainPeer)
{
    ui->setupUi(this);

    //set bools
    ui->cardio_no->setChecked(true);
    ui->pulmon_no->setChecked(true);
    ui->digestivo_no->setChecked(true);
    ui->alergia_no->setChecked(true);
    ui->quirurgico_no->setChecked(true);
    ui->renales_no->setChecked(true);
    ui->diabetes_no->setChecked(true);

    //set professional data
    ui->LineEdit_nombreProfesional->setText(nombre);
    ui->lineEdit_IPS->setText(ips);
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

DialogIngreso::~DialogIngreso()
{
    delete ui;
}

void DialogIngreso::createHealthRecord(QFile *file)
{
    if(!file->open(QIODevice::WriteOnly))
    {
       qDebug() << "Could not open " << file->fileName();
    }

    else
    {
        QTextStream out(file);
        out <<"\tINGRESO PACIENTE\n\n";

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
        out<<ui->LineEdit_nombreProfesional->text()+"\n";

        out<<"IPS : ";
        out<<ui->lineEdit_IPS->text()+"\n";

        out<<"TARJETA PROFESIONAL : ";
        out<<ui->lineEdit_tarjeta->text()+"\n";

        out <<"MOTIVOS DE CONSULTA\n\n";

        out<<"MOTIVOS : ";
        out<<ui->plainTextEdit_Motivos->toPlainText()+"\n";

        out<<"ENFERMEDAD ACTUAL : ";
        out<<ui->plainTextEdit_EnfermedadActual->toPlainText()+"\n\n";

        out <<"ANTECEDENTES PERSONALES Y FAMILIARES\n";
        out<<"\n";

        out<<"CARDIOVASCULARES : ";
        if(ui->cardio_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"PULMONARES : ";
        if(ui->pulmon_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"DIGESTIVOS : ";
        if(ui->digestivo_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"QUIRURGICOS : ";
        if(ui->quirurgico_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"ALERGIAS : ";
        if(ui->alergia_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"RENALES : ";
        if(ui->renales_no->isChecked()){out<<"NO\n";}
        else {out<<"SI\n";}

        out<<"DIABETES : ";
        if(ui->diabetes_no->isChecked()){out<<"NO\n\n";}
        else {out<<"SI\n\n";}

        out <<"EXAMEN FISICO\n";
        out<<"\n";

        out<<"TA : ";
        out<<ui->lineEdit_TA->text()+"\n";

        out<<"FC : ";
        out<<ui->lineEdit_FC->text()+"\n";

        out<<"FR : ";
        out<<ui->lineEdit_FR->text()+"\n";

        out<<"TEMP : ";
        out<<ui->lineEdit_TEMP->text()+"\n";

        out<<"SA02 : ";
        out<<ui->lineEdit_SAO2->text()+"\n";

        out<<"IMPRESION GENERAL : ";
        out<<ui->plainTextEdit_Impresion->toPlainText()+"\n";

        out<<"PLAN DE TRATAMIENTO : ";
        out<<ui->plainTextEdit_Plan->toPlainText()+"\n";

        for(int i=0;i<96;i++)
        {
            out<<"_";
        }

        out<<"\n";

        file->close();
    }

}

void DialogIngreso::on_commandLinkButton_clicked()
{
    QString localPath=QDir::currentPath();
    QFile file(QDir::currentPath().append("/data/file.dat"));

    //create patient's medical record
    createHealthRecord(&file);

    //cipher file
    cipherFile(&file);
    file.close();

    //hash the file
    QByteArray linkHash;
    linkHash=hashFile(&file);
    file.close();

    //rename file with hash
    QDir::setCurrent(QDir::currentPath().append("/data"));
    file.rename(linkHash);
    file.close();

    //create Block object  (inputs: (1) previous hash   (2)hash cedula   (3) file hash
    QDir::setCurrent(localPath);
    Block bloque(getLastHash(), QCryptographicHash::hash(ui->lineEdit_Cedula->text().toUtf8(),QCryptographicHash::Sha256).toHex(), linkHash);

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
    QMessageBox::information(this, "OK :)","Ingreso añadido satisfactoriamente!");
    this->close();
}
