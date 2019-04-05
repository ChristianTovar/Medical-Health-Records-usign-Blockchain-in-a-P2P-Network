#include "dialogeditarpaciente.h"
#include "ui_dialogeditarpaciente.h"

DialogEditarPaciente::DialogEditarPaciente(QString cedula, QString nombres, QString apellidos, QString lugar, QString fecha, QString sexo, QString eps, QString rfid) : ui(new Ui::DialogEditarPaciente)
{
    ui->setupUi(this);

    ui->lineEdit_cedula->setText(cedula);
    ui->lineEdit_nombres->setText(nombres);
    ui->lineEdit_apellidos->setText(apellidos);
    ui->lineEdit_lugar->setText(lugar);
    ui->lineEdit_fecha->setText(fecha);
    ui->lineEdit_sexo->setText(sexo);
    ui->lineEdit_eps->setText(eps);
    ui->lineEdit_rfid->setText(rfid);

    //setup timers
    connect(timer_update_rfid,SIGNAL(timeout()),this,SLOT(updateRFID()));
}

DialogEditarPaciente::~DialogEditarPaciente()
{
    delete ui;
}

void DialogEditarPaciente::updateRFID()
{
    //execute python script
    QProcess *process = new QProcess();
    QStringList arguments {"Read.py"};
    process->execute("python",arguments);
    process->waitForFinished();
    process->close();

    //read uid file
    QFile file(QDir::currentPath().append("/uid"));
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"archivo uid no abrio...";
    }

    else
    {
        QByteArray uid=file.readAll();
        uid=uid.trimmed();
        file.close();

        //check for uid
        if(uid!= ui->lineEdit_rfid->text().toUtf8())
        {
            //end python timer
            timer_update_rfid->stop();

            //close dialog paciente
            dialog->close();

            //clear uid file
            file.remove();

            //update line edit with new rfid device
            ui->lineEdit_rfid->setText(QString::fromStdString(uid.toStdString()));
        }

     }

}

void DialogEditarPaciente::on_commandLinkButton_clicked()
{
    dialog=new DialogPaciente();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();

    //start timer for python script
    timer_update_rfid->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_update_rfid,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog,SLOT(close()));
}

void DialogEditarPaciente::on_commandLinkButton_2_clicked()
{
    //replace patient in table
    QSqlQuery query;
    QString  consulta;

    //time in epoch
    QDateTime time = QDateTime::currentDateTime();
    QString timestamp=QString::number(time.toSecsSinceEpoch());

    consulta.append("UPDATE patient SET eps='"+ui->lineEdit_eps->text()+"',rfid='"+ui->lineEdit_rfid->text()+"',timestamp='"+timestamp+"' WHERE cedula= "+ui->lineEdit_cedula->text());

    if(query.exec(consulta))
    {
       QMessageBox::information(this, "OK :)","Paciente editado/a satisfactoriamente!");
    }

    else
    {
        QMessageBox::information(this, "ERROR :(","Paciente  no pudo ser editado/a...");
    }

    this->close();
}
