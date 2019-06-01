#include "authorization.h"
#include <QApplication>
#include <QDialog>
#include <QString>

int width=2;
QString WayToTheFile;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    authorization w;
    w.show();

    return a.exec();
}
