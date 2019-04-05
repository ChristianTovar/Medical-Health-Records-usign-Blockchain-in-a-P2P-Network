#include "dialogeditarprofesional.h"
#include "ui_dialogeditarprofesional.h"

DialogEditarProfesional::DialogEditarProfesional(QString id,QString nombres, QString ips, QString tarjeta) :ui(new Ui::DialogEditarProfesional), id_m(id)
{
    ui->setupUi(this);

    ui->lineEdit_nombre->setText(nombres);
    ui->lineEdit_ips->setText(ips);
    ui->lineEdit_tarjeta->setText(tarjeta);

    //setup timers
    connect(timer_update_rfid,SIGNAL(timeout()),this,SLOT(updateRFID()));
}

DialogEditarProfesional::~DialogEditarProfesional()
{
    delete ui;
}

void DialogEditarProfesional::on_commandLinkButton_clicked()
{
    dialog=new DialogProfesional();
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

void DialogEditarProfesional::updateRFID()
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
        if(uid!= ui->lineEdit_tarjeta->text().toUtf8())
        {
            //end python timer
            timer_update_rfid->stop();

            //close dialog paciente
            dialog->close();

            //clear uid file
            file.remove();

            //update line edit with new rfid device
            ui->lineEdit_tarjeta->setText(QString::fromStdString(uid.toStdString()));
        }

     }
}

void DialogEditarProfesional::on_commandLinkButton_2_clicked()
{
    //replace patient in table
    QSqlQuery query;
    QString  consulta;

    //time in epoch
    QDateTime time = QDateTime::currentDateTime();
    QString timestamp=QString::number(time.toSecsSinceEpoch());

    consulta.append("UPDATE professional SET ips='"+ui->lineEdit_ips->text()+"',tarjeta='"+ui->lineEdit_tarjeta->text()+"',timestamp='"+timestamp+"' WHERE id= "+id_m);

    if(query.exec(consulta))
    {
       QMessageBox::information(this, "OK :)","Profesional editado/a satisfactoriamente!");
    }

    else
    {
        QMessageBox::information(this, "ERROR :(","Profesional no pudo ser editado/a...");
    }

    this->close();
}
