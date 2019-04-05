#ifndef DIALOGESPERA_H
#define DIALOGESPERA_H

#include <QDialog>
#include <QDir>

namespace Ui {
class DialogEspera;
}

class DialogEspera : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEspera(QWidget *parent = 0);
    ~DialogEspera();

private:
    Ui::DialogEspera *ui;
};

#endif // DIALOGESPERA_H
