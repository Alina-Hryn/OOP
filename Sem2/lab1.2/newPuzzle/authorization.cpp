#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"


authorization::authorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_clicked()
{
    menu1 window;
    window.setModal(true);
    window.exec();
}
