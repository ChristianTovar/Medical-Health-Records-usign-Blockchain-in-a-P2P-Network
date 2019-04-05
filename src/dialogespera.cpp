#include "dialogespera.h"
#include "ui_dialogespera.h"

DialogEspera::DialogEspera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEspera)
{
    ui->setupUi(this);

    //setup image
    QPixmap image(QDir::currentPath().append("/espere.png"));
    ui->label->setPixmap(image);
}

DialogEspera::~DialogEspera()
{
    delete ui;
}
