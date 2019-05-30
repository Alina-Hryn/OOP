#include "authorization.h"
#include <QApplication>
#include <QDialog>
int width=2;
string WayToTheFile;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    authorization w;
    w.show();

    return a.exec();
}
