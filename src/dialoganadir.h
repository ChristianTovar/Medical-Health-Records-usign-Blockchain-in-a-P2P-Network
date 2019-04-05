#ifndef DIALOGANADIR_H
#define DIALOGANADIR_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "peer.h"


namespace Ui {
class DialogAnadir;
}

class DialogAnadir : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAnadir(Peer *mainPeer, QByteArray uid="uid");
    ~DialogAnadir();

private slots:
    void on_lineEditNombres_textChanged();
    void on_lineEditApellidos_textChanged();
    void on_lineEditLugarNacimiento_textChanged();
    void on_dateTimeEdit_dateChanged();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_lineEditEPS_textChanged();
    void on_commandLinkButton_clicked();
    void on_lineEditCedula_textChanged();

private:
    Ui::DialogAnadir *ui;
    Peer *peer;
    QString uid_m;
};

#endif // DIALOGANADIR_H
