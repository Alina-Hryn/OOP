#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"


authorization::authorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet( "background-image: url('back.jpg');" );
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.exec();
}
