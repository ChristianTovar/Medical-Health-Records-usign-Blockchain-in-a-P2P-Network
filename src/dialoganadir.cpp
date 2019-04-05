#include "dialoganadir.h"
#include "ui_dialoganadir.h"
#include <QDebug>

DialogAnadir::DialogAnadir(Peer *mainPeer,QByteArray uid): ui(new Ui::DialogAnadir),peer(mainPeer), uid_m(uid)
{
    ui->setupUi(this);
    ui->lineEditRFID->setText(uid_m);
}

DialogAnadir::~DialogAnadir()
{
    delete ui;
}

void DialogAnadir::on_lineEditCedula_textChanged()
{
   ui->lineEditNombres->setEnabled(true);
}

void DialogAnadir::on_lineEditNombres_textChanged()
{
    ui->lineEditApellidos->setEnabled(true);
}

void DialogAnadir::on_lineEditApellidos_textChanged()
{
    ui->lineEditLugarNacimiento->setEnabled(true);
}

void DialogAnadir::on_lineEditLugarNacimiento_textChanged()
{
    ui->dateTimeEdit->setEnabled(true);
}

void DialogAnadir::on_dateTimeEdit_dateChanged()
{
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
}

void DialogAnadir::on_radioButton_2_clicked()
{
    ui->lineEditEPS->setEnabled(true);
}

void DialogAnadir::on_radioButton_clicked()
{
    ui->lineEditEPS->setEnabled(true);
}

void DialogAnadir::on_lineEditEPS_textChanged()
{
    ui->commandLinkButton->setEnabled(true);
}

void DialogAnadir::on_commandLinkButton_clicked()
{
    QSqlQuery query;
    QString  consulta;
    QString sexo;

    //time in epoch
    QDateTime time = QDateTime::currentDateTime();
    QString timestamp=QString::number(time.toSecsSinceEpoch());

    if(ui->radioButton->isChecked())
    {
        sexo="MASCULINO";

        consulta.append("INSERT INTO patient"
                        "(cedula, nombres, apellidos, lugar, fecha, sexo, eps, rfid, timestamp)"
                        "VALUES("
                        "'"+ui->lineEditCedula->text()+"',"
                        "'"+ui->lineEditNombres->text()+"',"
                        "'"+ui->lineEditApellidos->text()+"',"
                        "'"+ui->lineEditLugarNacimiento->text()+"',"
                        "'"+ui->dateTimeEdit->date().toString()+"',"
                        "'MASCULINO',"
                        "'"+ui->lineEditEPS->text()+"',"
                        "'"+ui->lineEditRFID->text()+"',"
                        "'"+timestamp+"')");
    }

    if(ui->radioButton_2->isChecked())
    {
        sexo="FEMENINO";

        consulta.append("INSERT INTO patient"
                        "(cedula, nombres, apellidos, lugar, fecha, sexo, eps, rfid, timestamp)"
                        "VALUES("
                        ""+ui->lineEditCedula->text()+"',"
                        "'"+ui->lineEditNombres->text()+"',"
                        "'"+ui->lineEditApellidos->text()+"',"
                        "'"+ui->lineEditLugarNacimiento->text()+"',"
                        "'"+ui->dateTimeEdit->date().toString()+"',"
                        "'FEMENINO',"
                        "'"+ui->lineEditEPS->text()+"',"
                        "'"+ui->lineEditRFID->text()+"',"
                        "'"+timestamp+"')");
    }

    if(query.exec(consulta))
    {
       QMessageBox::information(this, "OK :)","Paciente añadido/a satisfactoriamente!");
    }

    else
    {
        QMessageBox::information(this, "ERROR :(","Paciente  no pudo ser añadido/a...");
        //QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
    }

    //backup patient
    QByteArray patientInfo;

    patientInfo.append(""+ui->lineEditCedula->text()+":"
                       ""+ui->lineEditNombres->text()+":"
                       ""+ui->lineEditApellidos->text()+":"
                       ""+ui->lineEditLugarNacimiento->text()+":"
                       ""+ui->dateTimeEdit->date().toString()+":"
                       ""+sexo+":"
                       ""+ui->lineEditEPS->text()+":"
                       ""+ui->lineEditRFID->text()+":"
                       ""+timestamp+"");

    peer->backupPatient("SUCCESSOR",patientInfo);

    this->close();
}
