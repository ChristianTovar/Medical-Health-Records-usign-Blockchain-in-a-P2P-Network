#include "dialog.h"
#include "ui_dialog.h"

using namespace QtConcurrent;

 QString successor;
 QString predecessor;
 QString local_ip;
 quint16 local_port;
 quint16 port;
 quint8  state;

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //obtener ip address
    local_ip=get_ip_address();
    ui->lineEdit_Local_IP->setText(local_ip);
    ui->lineEdit_IP->setText(local_ip);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_Next_clicked()
{
    local_port=ui->lineEdit_Local_Port->text().toInt();
    port=ui->lineEdit_Port->text().toInt();

    QFuture<bool> t;

    if(ui->radioButton_Base->isChecked())
    {
        predecessor=ui->lineEdit_IP->text();
        successor=ui->lineEdit_IP->text();

        //initialize operation

        socket=new Peer();

        if(ui->pushButton_Base->text()=="A")
        {
            state=PEER_A;
            t = run(socket, &Peer::listenPing,successor,local_port);
            qDebug()<<"OPTION A";
        }

        else
        {
            state=PEER_B;
            t = run(socket, &Peer::ping,successor,port);
            qDebug()<<"OPTION B";
        }

        t.waitForFinished();

        qDebug() << "Starting Chord DHT!\n";

        if(t.result())
        {
            emit startNetwork();
            this->close();
        }

        else  {QMessageBox::information(this, "Information","Host Unreachable...");}
    }

    if(ui->radioButton_Join->isChecked())
    {
        predecessor=ui->lineEdit_IP->text();
        successor="null";
        state=PEER_C;

        //add address to file if new
        appendAddress(predecessor,port);

        t = run(socket, &Peer::ping,predecessor,port);
        t.waitForFinished();

        if(t.result())
        {
            //join operation
            qDebug()<<"OPTION C";
            qDebug() << "Starting Chord DHT!\n";

            emit startNetwork();
            this->close();
        }

        else  {QMessageBox::information(this, "Information","Host Unreachable...");}
    }
}

void Dialog::on_radioButton_Join_clicked()
{
    ui->groupBox_2->setTitle("Bootstrap Node Info:");
    ui->groupBox_2->setEnabled(true);
    ui->pushButton_Base->setEnabled(false);
    ui->pushButton_Next->setEnabled(false);
}

void Dialog::on_radioButton_Base_clicked()
{
    ui->groupBox_2->setTitle("Base Node Info:");
    ui->groupBox_2->setEnabled(true);
    ui->pushButton_Base->setEnabled(true);
}

void Dialog::on_lineEdit_Port_textChanged()
{
    ui->pushButton_Next->setEnabled(true);
}

void Dialog::on_lineEdit_Local_Port_textChanged()
{
    ui->groupBox->setEnabled(true);
    ui->pushButton_Base->setEnabled(false);
}

void Dialog::on_pushButton_Base_clicked()
{
    if(ui->pushButton_Base->text()=="A")
    {
        ui->pushButton_Base->setText("B");
    }

    else
    {
        ui->pushButton_Base->setText("A");
    }
}

