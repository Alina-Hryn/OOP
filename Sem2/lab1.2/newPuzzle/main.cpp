#include "authorization.h"
#include "singleton.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include<QDebug>

int width=2;
QString WayToTheFile;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    authorization w;
    w.show();

    return a.exec();
}
