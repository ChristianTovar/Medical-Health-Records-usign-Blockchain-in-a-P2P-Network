#ifndef DIALOGTARJETA_H
#define DIALOGTARJETA_H

#include <QDialog>

namespace Ui {
class DialogTarjeta;
}

class DialogTarjeta : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTarjeta(QString *tarjeta);
    ~DialogTarjeta();

private slots:
    void on_lineEdit_textChanged();
    void on_commandLinkButton_clicked();


private:
    Ui::DialogTarjeta *ui;
    QString *tarjeta_m;
};

#endif // DIALOGTARJETA_H
