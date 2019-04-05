#include "dialogcedula.h"
#include "ui_dialogcedula.h"

DialogCedula::DialogCedula(QString *cedula) : ui(new Ui::DialogCedula), cedula_m(cedula)
{
    ui->setupUi(this);
}

DialogCedula::~DialogCedula()
{
    delete ui;
}

void DialogCedula::on_lineEdit_textChanged()
{
    ui->commandLinkButton->setEnabled(true);
}

void DialogCedula::on_commandLinkButton_clicked()
{
    *cedula_m=ui->lineEdit->text();
    this->close();
}
