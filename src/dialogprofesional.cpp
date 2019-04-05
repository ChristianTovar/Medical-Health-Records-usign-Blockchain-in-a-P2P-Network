#include "dialogprofesional.h"
#include "ui_dialogprofesional.h"

DialogProfesional::DialogProfesional(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProfesional)
{
    ui->setupUi(this);

    //setup image
    QPixmap image(QDir::currentPath().append("/rfid_profesional.png"));
    ui->label->setPixmap(image);
}

DialogProfesional::~DialogProfesional()
{
    delete ui;
}
