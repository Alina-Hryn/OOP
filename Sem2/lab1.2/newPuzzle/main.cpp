#include "authorization.h"
#include "singleton.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include<QDebug>
#include<QSettings>





int main(int argc, char *argv[])
{

    Singleton::getInstance().NumberOfStars=0;
    Singleton::getInstance().visitedLevels={};
    QApplication a(argc, argv);
    authorization w;
    //w.readSettings();
    w.show();

    return a.exec();
}
