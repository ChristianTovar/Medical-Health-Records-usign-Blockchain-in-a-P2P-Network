#include "dialogpaciente.h"
#include "ui_dialogpaciente.h"

DialogPaciente::DialogPaciente(QWidget *parent) :QDialog(parent),ui(new Ui::DialogPaciente)
{
    ui->setupUi(this);

    //setup image
    QPixmap image(QDir::currentPath().append("/rfid_paciente.png"));
    ui->label->setPixmap(image);
}

DialogPaciente::~DialogPaciente()
{
    delete ui;
}
