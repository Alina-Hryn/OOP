#ifndef INITIAL_H
#define INITIAL_H

#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class Initial;
}

class Initial : public QMainWindow
{
    Q_OBJECT

public:
    explicit Initial(QWidget *parent = nullptr);
    ~Initial();

public slots:
    void onButtonPlayClicked(){

        hide();
 //       MainWindow* w = new MainWindow();
    }

private:
    Ui::Initial *ui;
};

#endif // INITIAL_H
