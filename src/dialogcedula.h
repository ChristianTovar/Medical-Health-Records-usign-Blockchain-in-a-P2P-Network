#ifndef DIALOGCEDULA_H
#define DIALOGCEDULA_H

#include <QDialog>

namespace Ui {
class DialogCedula;
}

class DialogCedula : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCedula(QString *cedula);
    ~DialogCedula();

private slots:
    void on_lineEdit_textChanged();

    void on_commandLinkButton_clicked();

private:
    Ui::DialogCedula *ui;
    QString *cedula_m;
};

#endif // DIALOGCEDULA_H
