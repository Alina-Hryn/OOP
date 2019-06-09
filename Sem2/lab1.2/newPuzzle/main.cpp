#include "authorization.h"
#include "singleton.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include<QDebug>


int main(int argc, char *argv[])
{
    Singleton::getInstance().NumberOfStars=135;
    Singleton::getInstance().visitedLevels={};
    QApplication a(argc, argv);
    authorization w;
    w.show();

    return a.exec();
}
