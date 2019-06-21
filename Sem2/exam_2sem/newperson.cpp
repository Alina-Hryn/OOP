#include "newperson.h"
#include "ui_newperson.h"
#include "singleton.h"
#include "slcircular.h"

NewPerson::NewPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPerson)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1,35);
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->textEdit_6->setText("");
    ui->textEdit_7->setText("");
}

NewPerson::~NewPerson()
{
    delete ui;
}

void NewPerson::on_pushButton_clicked()
{
    close();
}

void NewPerson::on_pushButton_2_clicked()
{
    Official person;
    QString emptystr="";
    if(ui->textEdit->toPlainText()!=nullptr &&(ui->textEdit_2->toPlainText()!=emptystr &&
                                               (ui->textEdit_3->toPlainText()!=emptystr &&
                                                (ui->textEdit_4->toPlainText()!=emptystr &&
                                                 (ui->textEdit_5->toPlainText()!=emptystr &&
                                                  (ui->textEdit_6->toPlainText()!=emptystr &&
                                                   ui->textEdit_7->toPlainText()!=emptystr)))) )){

        person.ministry=ui->textEdit->toPlainText();
        person.organization=ui->textEdit_2->toPlainText();
        person.unit=ui->textEdit_6->toPlainText();
        person.sirname=ui->textEdit_3->toPlainText();
        person.name=ui->textEdit_4->toPlainText();
        person.secondName=ui->textEdit_5->toPlainText();
        person.yearsInMinistry=ui->spinBox->value();
        person.univ=ui->textEdit_7->toPlainText();
    }
    else{
        ui->label->setText("ПЕРЕВІРТЕ ІНФОРМАЦІЮ");
    }
    bool els=false;
    for(int i=0; i<Singleton::getInstance().AllOfficials.size();i++){
        if(Singleton::getInstance().AllOfficials[i].sirname==person.sirname &&(Singleton::getInstance().AllOfficials[i].name==person.name && Singleton::getInstance().AllOfficials[i].secondName==person.secondName)){
            ui->label->setText("ОДНА ЛЮДИНА НЕ МОЖЕ ОБІЙМАТИ ДВІ ПОСАДИ");
            els=true;
    }
}
    if(!els){
       Singleton::getInstance().AllOfficials.push_back(person);
    }
}

void NewPerson::on_pushButton_3_clicked()
{

}
