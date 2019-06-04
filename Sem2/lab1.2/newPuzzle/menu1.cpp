#include "menu1.h"
#include "ui_menu1.h"
#include "authorization.h"
#include "forpleasure.h"

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);

}

menu1::~menu1()
{
    delete ui;
}

void menu1::on_pushButton_3_clicked()
{
    close();
}

void menu1::on_pushButton_2_clicked()
{
    hide();
   forPleasure wind;
   wind.setModal(true);
   wind.exec();
}
