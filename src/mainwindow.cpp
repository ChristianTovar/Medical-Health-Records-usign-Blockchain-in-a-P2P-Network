#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup logo
    QPixmap logo(QDir::currentPath().append("/logo.png"));
    ui->logo_label->setPixmap(logo);

    //setup network status image
    QPixmap status(QDir::currentPath().append("/offline.png"));
    ui->status_label->setPixmap(status);

    //setup background
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    //setup time & date
    ui->dateTimeEdit->setDateTime( QDateTime::currentDateTime());
    connect(timer_edit,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer_edit->start(1000);

    //setup timer for python script
    connect(timer_anadir_paciente,SIGNAL(timeout()),this,SLOT(anadirPaciente()));
    connect(timer_ingreso_paciente,SIGNAL(timeout()),this,SLOT(ingresoPaciente()));
    connect(timer_ingreso_profesional,SIGNAL(timeout()),this,SLOT(ingresoProfesional()));
    connect(timer_evolucion_paciente,SIGNAL(timeout()),this,SLOT(evolucionPaciente()));
    connect(timer_evolucion_profesional,SIGNAL(timeout()),this,SLOT(evolucionProfesional()));
    connect(timer_salida_paciente,SIGNAL(timeout()),this,SLOT(salidaPaciente()));
    connect(timer_salida_profesional,SIGNAL(timeout()),this,SLOT(salidaProfesional()));
    connect(timer_busqueda_paciente,SIGNAL(timeout()),this,SLOT(busquedaPaciente()));
    connect(timer_anadir_profesional,SIGNAL(timeout()),this,SLOT(anadirProfesional()));

    //check SQLITE driver
    if(!QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        QMessageBox::warning(this, "Error","QSQLITE drive is not avaliable.");
        exit(EXIT_FAILURE);
    }

    //setup Database
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath().append("/users.db"));

    //check openability of database
    if(!db.open())
    {
        QMessageBox::warning(this, "Error","Unable to open Database.");
        exit(EXIT_FAILURE);
    }

    QSqlQuery query;

    //create .db file if it does not exists
    if(!query.exec("CREATE TABLE IF NOT EXISTS patient (id INTEGER NOT NULL PRIMARY KEY,cedula VARCHAR(32) NOT NULL UNIQUE, nombres VARCHAR(64), apellidos VARCHAR(64), lugar VARCHAR(32), fecha VARCHAR(16), sexo VARCHAR(16), eps VARCHAR(32), rfid VARCHAR(32), timestamp VARCHAR(64))") )
    {
       QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
       exit(EXIT_FAILURE);
    }

    if(!query.exec("CREATE TABLE IF NOT EXISTS professional (id INTEGER NOT NULL PRIMARY KEY, nombre VARCHAR(64), ips VARCHAR(32), tarjeta VARCHAR(32) NOT NULL UNIQUE, timestamp VARCHAR(64) )") )
    {
       QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
       exit(EXIT_FAILURE);
    }

    //tests



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startChord()
{
    //asignar GUID a BASE_A
    if(state==PEER_A)
    {
        guid=QUuid::createUuid();

        //create new blockchain
        QFile newBlockchain(QDir::currentPath().append("/bc.json"));
        newBlockchain.open(QIODevice::WriteOnly);
        newBlockchain.close();

        //create genesis block
        Block genesis;
        genesis.insertData();
        insertBlock(genesis);

        //delete data folder
        QDir dir(QDir::currentPath().append("/data"));
        dir.removeRecursively();

        //create data folder again
        if (!dir.exists())
        {
            dir.mkpath(".");
        }
    }

    //construccion del nodo
    peer=new Peer(guid, QHostAddress(local_ip), local_port, QHostAddress(predecessor), port, QHostAddress(successor),port);

    // solicitar GUID BASE_B  (1 vez)
    if(state==PEER_B)
    {
        //delete data folder
        QDir dir(QDir::currentPath().append("/data"));
        dir.removeRecursively();

        //create data folder again
        if (!dir.exists())
        {
            dir.mkpath(".");
        }

        QThread::msleep(1000);
        peer->requestBaseGuid(successor,port);
    }

    // solicitudes de nodos
    peer->listen(QHostAddress::Any,local_port);


    // Join chord   (1 vez)
    if(state==PEER_C)
    {
        QThread::msleep(1000);
        peer->join();

        //purge blocks from blockchain
        peer->purgeBlocks(peer->getGuid().toByteArray());

        //purge users (?)...
    }

    //enable main window push buttons
    enableButtons();

    //stabilize
    connect(timer_stab,&QTimer::timeout,peer,&Peer::stabilize);
    timer_stab->start(10000);

    //enable info
    ui->actionChord_Status->setEnabled(true);

    //disable join action
    ui->actionSet_Chord->setEnabled(false);

    //disable auto join
    ui->actionAuto_Join->setEnabled(false);

    //setup network status image
    QPixmap status(QDir::currentPath().append("/online.png"));
    ui->status_label->setPixmap(status);
}

void MainWindow::enableButtons()
{
    ui->pushButton_Ingreso->setEnabled(true);
    ui->pushButton_Evolucion->setEnabled(true);
    ui->pushButton_Salida->setEnabled(true);
    ui->pushButton_Busqueda->setEnabled(true);
    ui->pushButton_Anadir->setEnabled(true);
    ui->pushButton_AnadirProfesional->setEnabled(true);
    ui->pushButton_EditarPaciente->setEnabled(true);
    ui->pushButton_EditarProfesional->setEnabled(true);
}

void MainWindow::anadirPaciente()
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
        if(uid.length()>=8)
        {
            //end python timer
            timer_anadir_paciente->stop();

            //close dialog paciente
            dialog_paciente->close();

            //clear uid file
            file.remove();

            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                QMessageBox::information(this, "Informacion","El paciente ya existe en la base de datos, no puede ser añadido");

            }

            //if patient does not exists
            else
            {

                query.prepare("SELECT nombre, ips FROM professional WHERE tarjeta = '"+uid+"' ");

                if(!query.exec())
                {
                    QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
                }

                //if patient exists
                if(query.first())
                {
                    QMessageBox::information(this, "Informacion","Diapositivo ya esta asociado a un profesional, no puede ser añadido");
                }

                else
                {
                    //execute dialog añadir
                    DialogAnadir dialog_anadir(peer,uid);
                    dialog_anadir.setModal(true);
                    dialog_anadir.exec();
                }
            }
        }
    }
}

void MainWindow::anadirProfesional()
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
        if(uid.length()>=8)
        {
            //end python timer
            timer_anadir_profesional->stop();

            //close dialog paciente
            dialog_profesional->close();

            //clear uid file
            file.remove();

            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT nombre,ips FROM professional WHERE tarjeta = '"+uid+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                QMessageBox::information(this, "Informacion","El profesional ya existe en la base de datos, no puede ser añadido");

            }

            //if patient does not exists
            else
            {

                query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

                if(!query.exec())
                {
                    QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
                }

                //if patient exists
                if(query.first())
                {
                    QMessageBox::information(this, "Informacion","Dispositivo ya esta asociado a un paciente, no puede ser añadido");
                }

                else
                {
                    //execute dialog añadir profesional
                    DialogAnadirProfesional dialog_anadir_profesional(peer,uid);
                    dialog_anadir_profesional.setModal(true);
                    dialog_anadir_profesional.exec();
                }
            }
        }
    }
}

void MainWindow::ingresoPaciente()
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
        file.close();
        uid=uid.trimmed();

        //assign uid to uid_m
        uid_m=uid;

        //check for uid
        if(uid.length()>=8)
        {
            //end python timer
            timer_ingreso_paciente->stop();

            //close dialog paciente
            dialog_paciente->close();

            //clear uid file
            file.remove();

            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid_m+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                //show dialog espera
                dialog_espera=new DialogEspera();
                dialog_espera->setAttribute(Qt::WA_DeleteOnClose);
                dialog_espera->setWindowModality(Qt::ApplicationModal);
                dialog_espera->show();

                //close dialog
                QTimer::singleShot(3000,dialog_espera,SLOT(close()));

                //end (dialog espera), transition to (ingreso profesional)
                QTimer::singleShot(3000,this,SLOT(ingresoTerminarEspera()));
            }

            //if patient does not exists
            else
            {
                //ask for patient personal information
                QtConcurrent::run(peer,&Peer::obtainPatient,peer->getGuid(),peer->getLocalIP(),peer->getLocalPort(),uid);

                QMessageBox::information(this, "Informacion","El paciente no se encuentra en la red, porfavor intente en unos segundos mientras se obtienen los datos");
            }
        }
    }
}

void MainWindow::ingresoProfesional()
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
        QByteArray tp=file.readAll();
        tp=tp.trimmed();
        file.close();

        //check for uid
        if(tp.length()>=8 && tp!=uid_m)
        {
            //end python timer
            timer_ingreso_profesional->stop();

            //close dialog paciente
            dialog_profesional->close();

            //clear uid file
            file.remove();

            //search for pro in database
            QSqlQuery query;
            query.prepare("SELECT nombre, ips FROM professional WHERE tarjeta = '"+tp+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                QString nombre=query.value(0).toString();
                QString ips=query.value(1).toString();

                //execute dialog ingreso
                dialog_ingreso=new DialogIngreso(peer,uid_m,nombre,ips,QString::fromUtf8(tp));
                dialog_ingreso->setAttribute(Qt::WA_DeleteOnClose);
                dialog_ingreso->setWindowModality(Qt::ApplicationModal);
                dialog_ingreso->exec();
            }

            else
            {
                //request professional
                ///......

                QMessageBox::information(this, "Informacion","Este dispositivo no se encuentra en el sistema, espere un momento mientras se solicita en la red. De lo contrario añada el dispositivo");
            }
        }
    }
}

void MainWindow::ingresoTerminarEspera()
{
    //create dialog profesional
    dialog_profesional=new DialogProfesional(this);
    dialog_profesional->setAttribute(Qt::WA_DeleteOnClose);
    dialog_profesional->setWindowModality(Qt::ApplicationModal);
    dialog_profesional->show();

    //get tag from professional
    timer_ingreso_profesional->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_ingreso_profesional,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_profesional,SLOT(close()));
}

void MainWindow::evolucionPaciente()
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

        //assign uid to uid_m
        uid_m=uid;

        file.close();

        //check for uid
        if(uid.length()>=8)
        {
            //end python timer
            timer_evolucion_paciente->stop();

            //close dialog paciente
            dialog_paciente->close();

            //clear uid file
            file.remove();

            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                //show dialog espera
                dialog_espera=new DialogEspera();
                dialog_espera->setAttribute(Qt::WA_DeleteOnClose);
                dialog_espera->setWindowModality(Qt::ApplicationModal);
                dialog_espera->show();

                //close dialog
                QTimer::singleShot(3000,dialog_espera,SLOT(close()));

                //end (dialog espera), transition to (ingreso profesional)
                QTimer::singleShot(3000,this,SLOT(evolucionTerminarEspera()));
            }

            //if patient does not exists
            else
            {
                //ask for patient personal information
                QtConcurrent::run(peer,&Peer::obtainPatient,peer->getGuid(),peer->getLocalIP(),peer->getLocalPort(),uid);

                QMessageBox::information(this, "Informacion","El paciente no se encuentra en la red, porfavor intente en unos segundos mientras se obtienen los datos");
            }

        }
    }
}

void MainWindow::updateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::on_actionSet_Chord_triggered()
{
    dialog=new Dialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    //connection between dialog and mainwindow
    connect(dialog,&Dialog::startNetwork,this,&MainWindow::startChord);

    dialog->exec();
}

void MainWindow::on_actionAuto_Join_triggered()
{
    qDebug()<<"Auto Join! \n";

    QString ip;
    quint16 port_n;
    QTcpSocket *socket = new QTcpSocket();

    QFile file(QDir::currentPath().append("/addr.dat"));

    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
         QString line = in.readLine();
         QStringList dataList=line.split("_");

         ip=dataList[0];
         port_n=dataList[1].toInt();

         qDebug()<<dataList;

          //connect to host
          socket->connectToHost(ip, port_n);

          if(!socket->waitForConnected(200))
          {
              qDebug() << "Error: " << socket->errorString();
              socket->disconnectFromHost();
          }

          else
          {
             socket->disconnectFromHost();
             file.close();

             //prepare data for peer object members
              successor="null";
              predecessor=ip;
              local_ip=get_ip_address();
              local_port=get_random_port();
              port=port_n;
              state=PEER_C;

              //start chord OPTION C
              startChord();

              break;
          }

          if(in.atEnd())
          {
              QMessageBox::information(this, "Informacion","Esta funcion no esta disponible por el momento.");
          }
       }
    }

    else
    {
        qDebug()<<"ERROR READING addr.dat FILE..";
    }
}

void MainWindow::on_actionChord_Status_triggered()
{
    dialog_status=new DialogStatus(this,peer);
    dialog_status->setModal(true);
    connect(peer,&Peer::setWidget,dialog_status,&DialogStatus::updateChordWidget);
    dialog_status->exec();

    //tests
    //DialogAnadirProfesional *dialogo = new  DialogAnadirProfesional(peer,"103262a8");
    //dialogo->setModal(true);
    //dialogo->exec();

    //dialog_espera=new DialogEspera();
    //dialog_espera->setAttribute(Qt::WA_DeleteOnClose);
    //dialog_espera->setWindowModality(Qt::ApplicationModal);
    //dialog_espera->show();

    //QMessageBox::information(this, "Informacion","Paciente con cedula: 1094903182.Ha sido añadido satisfactoriamente!");

    //execute dialog
    //DialogBusqueda *dialog_busqueda=new DialogBusqueda();
    //dialog_busqueda->setAttribute(Qt::WA_DeleteOnClose);
    //dialog_busqueda->exec();

    //execute dialog añadir profesional
    //DialogAnadirProfesional *dialog_anadir_profesional= new DialogAnadirProfesional(peer,"498222a3");
    //dialog_anadir_profesional->setModal(true);
    //dialog_anadir_profesional->exec();


    //execute dialog añadir
    //DialogAnadir *dialog_anadir = new DialogAnadir(peer,"jijij");
    //dialog_anadir->setModal(true);
    //dialog_anadir->exec();


    //execute dialog ingreso
  /*  DialogIngreso *dialog_ingreso=new DialogIngreso(peer,"","","","");
    dialog_ingreso->setAttribute(Qt::WA_DeleteOnClose);
    dialog_ingreso->setWindowModality(Qt::ApplicationModal);
    dialog_ingreso->exec();


    DialogEvolucion *dialog_evolucion=new DialogEvolucion(peer,"","","","");
    dialog_evolucion->setAttribute(Qt::WA_DeleteOnClose);
    dialog_evolucion->exec();

    DialogSalida *dialog_salida=new DialogSalida(peer,"","","","");
    dialog_salida->setAttribute(Qt::WA_DeleteOnClose);
    dialog_salida->exec();
*/

    //execute dialog
    //DialogBusqueda *dialog_busqueda=new DialogBusqueda("jijij");
    //dialog_busqueda->setAttribute(Qt::WA_DeleteOnClose);
    //dialog_busqueda->exec();



}

void MainWindow::on_actionClose_App_triggered()
{
    qDebug()<<"Desalojando el sistema  :(";

    if(state)
    {
        peer->leaveSuccessor();
        peer->leavePredecessor();
    }

    QCoreApplication::quit();
}

void MainWindow::on_pushButton_Anadir_clicked()
{
    qDebug()<<"Añadir paciente";

    //create dialog
    dialog_paciente=new DialogPaciente(this);
    dialog_paciente->setAttribute(Qt::WA_DeleteOnClose);
    dialog_paciente->setWindowModality(Qt::ApplicationModal);
    dialog_paciente->show();

    //start timer for python script
    timer_anadir_paciente->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_anadir_paciente,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_paciente,SLOT(close()));

}

void MainWindow::on_pushButton_Ingreso_clicked()
{
    qDebug()<<"Ingreso Paciente";

    //create dialog
    dialog_paciente=new DialogPaciente(this);
    dialog_paciente->setAttribute(Qt::WA_DeleteOnClose);
    dialog_paciente->setWindowModality(Qt::ApplicationModal);
    dialog_paciente->show();

    //start timer for python script
    timer_ingreso_paciente->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_ingreso_paciente,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_paciente,SLOT(close()));
}

void MainWindow::on_pushButton_Evolucion_clicked()
{
    qDebug()<<"Evolucion Paciente";

    //create dialog
    dialog_paciente=new DialogPaciente(this);
    dialog_paciente->setAttribute(Qt::WA_DeleteOnClose);
    dialog_paciente->setWindowModality(Qt::ApplicationModal);
    dialog_paciente->show();

    //start timer for python script
    timer_evolucion_paciente->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_evolucion_paciente,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_paciente,SLOT(close()));
}

void MainWindow::on_pushButton_Salida_clicked()
{
    qDebug()<<"Salida Paciente";

    //create dialog
    dialog_paciente=new DialogPaciente(this);
    dialog_paciente->setAttribute(Qt::WA_DeleteOnClose);
    dialog_paciente->setWindowModality(Qt::ApplicationModal);
    dialog_paciente->show();

    //start timer for python script
    timer_salida_paciente->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_salida_paciente,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_paciente,SLOT(close()));
}

void MainWindow::on_pushButton_Busqueda_clicked()
{
    qDebug()<<"Busqueda paciente";

    //create dialog
    dialog_paciente=new DialogPaciente(this);
    dialog_paciente->setAttribute(Qt::WA_DeleteOnClose);
    dialog_paciente->setWindowModality(Qt::ApplicationModal);
    dialog_paciente->show();

    //start timer for python script
    timer_busqueda_paciente->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_busqueda_paciente,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_paciente,SLOT(close()));
}

void MainWindow::on_pushButton_AnadirProfesional_clicked()
{
    qDebug()<<"Añadir Profesional";

    //create dialog
    dialog_profesional=new DialogProfesional(this);
    dialog_profesional->setAttribute(Qt::WA_DeleteOnClose);
    dialog_profesional->setWindowModality(Qt::ApplicationModal);
    dialog_profesional->show();

    //start timer for python script
    timer_anadir_profesional->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_anadir_profesional,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_profesional,SLOT(close()));
}

void MainWindow::evolucionTerminarEspera()
{
    //create dialog profesional
    dialog_profesional=new DialogProfesional(this);
    dialog_profesional->setAttribute(Qt::WA_DeleteOnClose);
    dialog_profesional->setWindowModality(Qt::ApplicationModal);
    dialog_profesional->show();

    //get tag from professional
    timer_evolucion_profesional->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_evolucion_profesional,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_profesional,SLOT(close()));
}

void MainWindow::evolucionProfesional()
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
        QByteArray tp=file.readAll();
        tp=tp.trimmed();
        file.close();

        //check for uid
        if(tp.length()>=8 && tp!=uid_m)
        {
            //end python timer
            timer_evolucion_profesional->stop();

            //close dialog paciente
            dialog_profesional->close();

            //clear uid file
            file.remove();

            //search for pro in database
            QSqlQuery query;
            query.prepare("SELECT nombre, ips FROM professional WHERE tarjeta = '"+tp+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {

                QString nombre=query.value(0).toString();
                QString ips=query.value(1).toString();

                //execute dialog ingreso
                dialog_evolucion=new DialogEvolucion(peer,uid_m,nombre,ips,QString::fromUtf8(tp));
                dialog_evolucion->setAttribute(Qt::WA_DeleteOnClose);
                dialog_evolucion->exec();
            }

            else
            {
                //request professional
                ///......

                QMessageBox::information(this, "Informacion","Este dispositivo no se encuentra en el sistema, espere un momento mientras se solicita en la red. De lo contrario añada el dispositivo");
            }
        }
    }
}

void MainWindow::salidaPaciente()
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

        //assign uid to uid_m
        uid_m=uid;

        file.close();

        //check for uid
        if(uid.length()>=8)
        {
            //end python timer
            timer_salida_paciente->stop();

            //close dialog paciente
            dialog_paciente->close();

            //clear uid file
            file.remove();

            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                //show dialog espera
                dialog_espera=new DialogEspera();
                dialog_espera->setAttribute(Qt::WA_DeleteOnClose);
                dialog_espera->setWindowModality(Qt::ApplicationModal);
                dialog_espera->show();

                //close dialog
                QTimer::singleShot(3000,dialog_espera,SLOT(close()));

                //end (dialog espera), transition to (ingreso profesional)
                QTimer::singleShot(3000,this,SLOT(salidaTerminarEspera()));
            }

            //if patient does not exists
            else
            {
                //ask for patient personal information
                QtConcurrent::run(peer,&Peer::obtainPatient,peer->getGuid(),peer->getLocalIP(),peer->getLocalPort(),uid);

                QMessageBox::information(this, "Informacion","El paciente no se encuentra en la red, porfavor intente en unos segundos mientras se obtienen los datos");
            }
        }
    }
}

void MainWindow::salidaTerminarEspera()
{
    //create dialog profesional
    dialog_profesional=new DialogProfesional(this);
    dialog_profesional->setAttribute(Qt::WA_DeleteOnClose);
    dialog_profesional->setWindowModality(Qt::ApplicationModal);
    dialog_profesional->show();

    //get tag from professional
    timer_salida_profesional->start(500);

    //end timer  after msecs
    QTimer::singleShot(10000,timer_salida_profesional,SLOT(stop()));

    //close patient dialog
    QTimer::singleShot(10000,dialog_profesional,SLOT(close()));

}

void MainWindow::salidaProfesional()
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
        QByteArray cp=file.readAll();
        cp=cp.trimmed();
        file.close();

        //check for uid
        if(cp.length()>=8 && cp!=uid_m)
        {
            //end python timer
            timer_salida_profesional->stop();

            //close dialog paciente
            dialog_profesional->close();

            //clear uid file
            file.remove();

            //search for pro in database
            QSqlQuery query;
            query.prepare("SELECT nombre, ips FROM professional WHERE tarjeta = '"+cp+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                QString nombre=query.value(0).toString();
                QString ips=query.value(1).toString();

                //execute dialog ingreso
                dialog_salida=new DialogSalida(peer,uid_m,nombre,ips,QString::fromUtf8(cp));
                dialog_salida->setAttribute(Qt::WA_DeleteOnClose);
                dialog_salida->exec();
            }

            else
            {
                //request professional
                ///......

                QMessageBox::information(this, "Informacion","Este dispositivo no se encuentra en el sistema, espere un momento mientras se solicita en la red. De lo contrario añada el dispositivo");
            }
        }
    }
}

void MainWindow::busquedaPaciente()
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
        if(uid.length()>=8)
        {
            //end python timer
            timer_busqueda_paciente->stop();

            //close dialog paciente
            dialog_paciente->close();

            //clear uid file
            file.remove();
            //look RFID in database
            QSqlQuery query;
            query.prepare("SELECT cedula,nombres,apellidos,lugar,fecha,sexo,eps FROM patient WHERE rfid = '"+uid+"' ");

            if(!query.exec())
            {
                QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
            }

            //if patient exists
            if(query.first())
            {
                //hash de cedula
                data=QCryptographicHash::hash(query.value(0).toString().toUtf8(),QCryptographicHash::Sha256);

                //busqueda de bloques correspondientes a data
                QtConcurrent::run(peer,&Peer::blocksFromChain,data.toHex());

                //execute dialog
                dialog_busqueda=new DialogBusqueda(data.toHex());
                dialog_busqueda->setAttribute(Qt::WA_DeleteOnClose);
                connect(peer,&Peer::displayRecord,dialog_busqueda,&DialogBusqueda::update);
                dialog_busqueda->exec();
            }

            //if patient does not exists
            else
            {
                //ask for patient personal information
                peer->obtainPatient(peer->getGuid(),peer->getLocalIP(),peer->getLocalPort(),uid);

                QMessageBox::information(this, "Informacion","El paciente no esta en la red, porfavor intente nuevamente mientras se actualizan los datos");
            }
        }
    }
}

void MainWindow::on_pushButton_EditarPaciente_clicked()
{
    QString *cedula=new QString("*");

    dialog_cedula=new DialogCedula(cedula);
    dialog_cedula->setAttribute(Qt::WA_DeleteOnClose);
    dialog_cedula->exec();

    //check if cedula is in patient table
    QSqlQuery query;
    query.prepare("SELECT nombres,apellidos,lugar,fecha,sexo,eps,rfid FROM patient WHERE cedula = '"+*cedula+"' ");

    if(!query.exec())
    {
        QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
    }

    //if patient exists
    if(query.first())
    {
        //patient info
        QString nombres=query.value(0).toString();
        QString apellidos=query.value(1).toString();
        QString lugar=query.value(2).toString();
        QString fecha=query.value(3).toString();
        QString sexo=query.value(4).toString();
        QString eps=query.value(5).toString();
        QString rfid=query.value(6).toString();

        dialog_editar_paciente=new DialogEditarPaciente(*cedula,nombres,apellidos,lugar,fecha,sexo,eps,rfid);
        dialog_editar_paciente->setAttribute(Qt::WA_DeleteOnClose);
        dialog_editar_paciente->exec();
    }

    //if patient does not exists
    else
    {
        //request patient to network
        QMessageBox::information(this, "Informacion","El paciente no esta en la red, porfavor intente nuevamente mientras se actualizan los datos");
    }
}

void MainWindow::on_pushButton_EditarProfesional_clicked()
{
    QString *tarjeta=new QString("*");

    dialog_tarjeta=new DialogTarjeta(tarjeta);
    dialog_tarjeta->setAttribute(Qt::WA_DeleteOnClose);
    dialog_tarjeta->exec();

    qDebug()<<*tarjeta;

    //check if tarjeta is in professional table
    QSqlQuery query;
    query.prepare("SELECT id,nombre,ips FROM professional WHERE tarjeta = '"+*tarjeta+"' ");

    if(!query.exec())
    {
        QMessageBox::warning(this, "QUERY ERROR",query.lastError().text());
    }

    //if patient exists
    if(query.first())
    {
        //patient info
        QString id=query.value(0).toString();
        QString nombre=query.value(1).toString();
        QString ips=query.value(2).toString();

        dialog_editar_profesional=new DialogEditarProfesional(id,nombre,ips,*tarjeta);
        dialog_editar_profesional->setAttribute(Qt::WA_DeleteOnClose);
        dialog_editar_profesional->exec();
    }

    //if patient does not exists
    else
    {
        //request patient to network
        QMessageBox::information(this, "Informacion","El profesional no esta en la red, porfavor intente nuevamente mientras se actualizan los datos");
    }
}
