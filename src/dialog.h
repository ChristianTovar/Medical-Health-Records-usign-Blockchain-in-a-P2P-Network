#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "functions.h"

#define PEER_A 1
#define PEER_B 2
#define PEER_C 3

extern  QString predecessor;
extern  QString successor;
extern  QString local_ip;
extern  quint16 local_port;
extern  quint16 port;
extern  quint8  state;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on_pushButton_Next_clicked();

    void on_radioButton_Join_clicked();

    void on_radioButton_Base_clicked();

    void on_lineEdit_Port_textChanged();

    void on_lineEdit_Local_Port_textChanged();

    void on_pushButton_Base_clicked();

signals:
    void startNetwork();


private:
    Ui::Dialog *ui;
    Peer *socket;
};

#endif // DIALOG_H


