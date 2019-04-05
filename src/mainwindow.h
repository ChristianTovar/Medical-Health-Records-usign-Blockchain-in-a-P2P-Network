#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "dialog.h"
#include "dialoganadir.h"
#include "dialogstatus.h"
#include "dialogingreso.h"
#include "dialogevolucion.h"
#include "dialogsalida.h"
#include "dialogbusqueda.h"
#include "dialogpaciente.h"
#include "dialogprofesional.h"
#include "dialogespera.h"
#include "dialoganadirprofesional.h"
#include "block.h"
#include "peer.h"
#include "dialogcedula.h"
#include "dialogeditarpaciente.h"
#include "dialogeditarprofesional.h"
#include "dialogtarjeta.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startChord();
    void updateChordWidget(Peer *peer);
    void updateWaitForPatient();
    void enableButtons();
    void closeDialog();

    Dialog *dialog;
    DialogStatus *dialog_status;
    //DialogAnadir *dialog_anadir;
    DialogIngreso *dialog_ingreso;
    DialogEvolucion *dialog_evolucion;
    DialogSalida *dialog_salida;
    DialogBusqueda *dialog_busqueda;
    //DialogAnadirProfesional *dialog_anadir_profesional;


private slots:

    void anadirPaciente();
    void anadirProfesional();

    void ingresoPaciente();
    void ingresoTerminarEspera();
    void ingresoProfesional();

    void evolucionPaciente();
    void evolucionTerminarEspera();
    void evolucionProfesional();

    void salidaPaciente();
    void salidaTerminarEspera();
    void salidaProfesional();

    void busquedaPaciente();

    void updateTime();
    void on_actionSet_Chord_triggered();
    void on_actionChord_Status_triggered();
    void on_actionClose_App_triggered();
    void on_pushButton_Anadir_clicked();
    void on_pushButton_Ingreso_clicked();
    void on_pushButton_Evolucion_clicked();
    void on_pushButton_Salida_clicked();
    void on_pushButton_Busqueda_clicked();
    void on_pushButton_AnadirProfesional_clicked();
    void on_actionAuto_Join_triggered();
    void on_pushButton_EditarPaciente_clicked();
    void on_pushButton_EditarProfesional_clicked();

signals:
    void patientOK();
    void professionalOK();

private:

    Ui::MainWindow *ui;
    Peer *peer;
    QUuid guid;
    QByteArray data;
    QByteArray uid_m;

    QTimer *timer_edit=new QTimer();
    QTimer *timer_stab=new QTimer();

    QTimer *timer_anadir_paciente=new QTimer();
    QTimer *timer_anadir_profesional=new QTimer();

    QTimer *timer_ingreso_paciente=new QTimer();
    QTimer *timer_ingreso_profesional=new QTimer();

    QTimer *timer_evolucion_paciente=new QTimer();
    QTimer *timer_evolucion_profesional=new QTimer();

    QTimer *timer_salida_paciente=new QTimer();
    QTimer *timer_salida_profesional=new QTimer();

    QTimer *timer_busqueda_paciente=new QTimer();

    DialogPaciente *dialog_paciente;
    DialogProfesional *dialog_profesional;
    DialogEspera *dialog_espera;
    DialogCedula *dialog_cedula;
    DialogEditarPaciente *dialog_editar_paciente;
    DialogTarjeta *dialog_tarjeta;
    DialogEditarProfesional *dialog_editar_profesional;
};

#endif // MAINWINDOW_H
