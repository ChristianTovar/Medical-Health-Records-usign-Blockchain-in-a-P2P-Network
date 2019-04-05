#ifndef DIALOGPACIENTE_H
#define DIALOGPACIENTE_H

#include <QDialog>
#include <QDir>


namespace Ui {
class DialogPaciente;
}

class DialogPaciente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPaciente(QWidget *parent = 0);
    ~DialogPaciente();

private:
    Ui::DialogPaciente *ui;
};

#endif // DIALOGPACIENTE_H
