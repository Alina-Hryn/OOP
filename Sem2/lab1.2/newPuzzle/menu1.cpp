#include "menu1.h"
#include "ui_menu1.h"
#include "levels.h"
#include "authorization.h"
#include "forpleasure.h"

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);

}



void menu1::on_pushButton_3_clicked()
{
    hide();

    authorization w;
    w.show();

}

void menu1::on_pushButton_2_clicked()
{
    hide();
   forPleasure wind;
   wind.setModal(true);
   wind.exec();
}

void menu1::on_pushButton_clicked()
{
    hide();
   levels window;
   //forPleasure window;
   window.setModal(true);
   window.exec();


}
menu1::~menu1()
{
    delete ui;
}
