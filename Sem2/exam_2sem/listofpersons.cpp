#include "listofpersons.h"
#include "ui_listofpersons.h"
#include "singleton.h"
#include "newperson.h"
#include<QScrollArea>

ListOfPersons::ListOfPersons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfPersons)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
    Singleton::getInstance().personInTheList=0;
    form(Singleton::getInstance().personInTheList);


}

void ListOfPersons:: form(int i){
    QString name=Singleton::getInstance().AllOfficials[0].sirname;
    ui->label_2->setText(name+" "+Singleton::getInstance().AllOfficials[i].name[0]+". "+Singleton::getInstance().AllOfficials[i].secondName[0]);
    name+=" "+Singleton::getInstance().AllOfficials[i].name+" "+Singleton::getInstance().AllOfficials[i].secondName;
    ui->label_5->setText(name);
    ui->label_10->setText(Singleton::getInstance().AllOfficials[i].ministry);
    ui->label_12->setText(Singleton::getInstance().AllOfficials[i].organization);
    ui->label_14->setText(Singleton::getInstance().AllOfficials[i].unit);
    ui->label_6->setNum(Singleton::getInstance().AllOfficials[i].yearsInMinistry);
    ui->label_8->setText(Singleton::getInstance().AllOfficials[i].univ);
    ui->label_15->setNum(i+1);
}

ListOfPersons::~ListOfPersons()
{
    delete ui;
}

void ListOfPersons::on_pushButton_5_clicked()
{

    if(Singleton::getInstance().personInTheList+1==Singleton::getInstance().AllOfficials.size())
        Singleton::getInstance().personInTheList=0;
    else
    Singleton::getInstance().personInTheList++;
    form(Singleton::getInstance().personInTheList);

}

void ListOfPersons::on_pushButton_4_clicked()
{
    if(Singleton::getInstance().personInTheList-1<0)
        Singleton::getInstance().personInTheList=Singleton::getInstance().AllOfficials.size()-1;
    else
    Singleton::getInstance().personInTheList--;
    form(Singleton::getInstance().personInTheList);
}

void ListOfPersons::on_pushButton_clicked()
{
    ui->textEdit->setVisible(true);
}
