#ifndef DIALOGPROFESIONAL_H
#define DIALOGPROFESIONAL_H

#include <QDialog>
#include <QDir>

namespace Ui {
class DialogProfesional;
}

class DialogProfesional : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProfesional(QWidget *parent = 0);
    ~DialogProfesional();

private:
    Ui::DialogProfesional *ui;
};

#endif // DIALOGPROFESIONAL_H
