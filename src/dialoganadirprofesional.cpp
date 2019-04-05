#include "dialoganadirprofesional.h"
#include "ui_dialoganadirprofesional.h"

DialogAnadirProfesional::DialogAnadirProfesional(Peer *mainPeer, QByteArray uid): ui(new Ui::DialogAnadirProfesional),peer(mainPeer) ,uid_m(uid)
{
    ui->setupUi(this);
    ui->lineEdit_Tarjeta->setText(uid_m);
}

DialogAnadirProfesional::~DialogAnadirProfesional()
{
    delete ui;
}

void DialogAnadirProfesional::on_lineEdit_Nombre_textChanged()
{
    ui->lineEdit_IPS->setEnabled(true);
}

void DialogAnadirProfesional::on_lineEdit_IPS_textChanged()
{
    ui->commandLinkButton->setEnabled(true);
}

void DialogAnadirProfesional::on_commandLinkButton_clicked()
{
    QSqlQuery query;
    QString  consulta;

    //time in epoch
    QDateTime time = QDateTime::currentDateTime();
    QString timestamp=QString::number(time.toSecsSinceEpoch());

    consulta.append("INSERT INTO professional"
                    "(nombre, IPS, tarjeta, timestamp)"
                    "VALUES("
                    "'"+ui->lineEdit_Nombre->text()+"',"
                    "'"+ui->lineEdit_IPS->text()+"',"
                    "'"+ui->lineEdit_Tarjeta->text()+"',"
                    "'"+timestamp+"')");

    if(query.exec(consulta))
    {
       QMessageBox::information(this, "OK :)","Profesional añadido/a satisfactoriamente!");
    }

    else
    {
        QMessageBox::information(this, "ERROR :(","Profesional no pudo ser añadido/a...");
    }

    //backup professional
    QByteArray professionalInfo;

    professionalInfo.append(""+ui->lineEdit_Nombre->text()+":"
                            ""+ui->lineEdit_IPS->text()+":"
                            ""+ui->lineEdit_Tarjeta->text()+":"
                            ""+timestamp+"");

    peer->backupProfessional("SUCCESSOR",professionalInfo);

    this->close();
}
