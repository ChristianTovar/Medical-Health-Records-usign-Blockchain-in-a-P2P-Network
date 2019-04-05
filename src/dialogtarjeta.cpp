#include "dialogtarjeta.h"
#include "ui_dialogtarjeta.h"

DialogTarjeta::DialogTarjeta(QString *tarjeta) :ui(new Ui::DialogTarjeta),tarjeta_m(tarjeta)
{
    ui->setupUi(this);
}

DialogTarjeta::~DialogTarjeta()
{
    delete ui;
}

void DialogTarjeta::on_lineEdit_textChanged()
{
    ui->commandLinkButton->setEnabled(true);
}

void DialogTarjeta::on_commandLinkButton_clicked()
{
    *tarjeta_m=ui->lineEdit->text();
    this->close();
}
