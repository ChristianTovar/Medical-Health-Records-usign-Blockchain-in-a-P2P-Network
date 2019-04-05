#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen *splash=new QSplashScreen;
    QPixmap banner(QDir::currentPath().append("/banner.png"));
    splash->setPixmap(banner);
    splash->show();

    MainWindow w;

    QTimer::singleShot(2000,splash,SLOT(close()));
    splash->showMessage("© 2018-2019 Christian Tovar All Rights Reserved",Qt::AlignBottom);
    QTimer::singleShot(2000,&w,SLOT(show()));

    //w.show();
    //w.setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    //w.showFullScreen();

    return app.exec();
}
