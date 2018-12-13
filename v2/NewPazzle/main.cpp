#include "mainwindow.h"
#include "initial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    Initial iw;
//    iw.show();

    return a.exec();
}
