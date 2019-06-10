#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"
#include "singleton.h"
#include<QSettings>
#include<QDebug>


authorization::authorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet( "background-image: url('back.jpg');" );
    readSettings();
    //qDebug()<<Singleton::getInstance().NumberOfStars;

}


void authorization::readSettings(){
    QSettings users("Users", "user1");
    users.beginGroup("user1");
    Singleton::getInstance().NumberOfStars = users.value("numberOfStars", 0).toInt();
    QString w = users.value("visited Levels", "").toString();

    int pos = w.lastIndexOf(QChar(';'));
    if(pos==-1)
        Singleton::getInstance().visitedLevels.push_back(w);
    else{
    while(w.size()>0){
    Singleton::getInstance().visitedLevels.push_back(w.right(pos));
    //qDebug()<<w.right(pos);
    w= w.left(pos);
    qDebug()<<w;
    }
    }

    users.endGroup();

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

void authorization::on_pushButton_2_clicked()
{
    hide();
}

void authorization::on_pushButton_3_clicked()
{
    Singleton::getInstance().NumberOfStars=0;
    Singleton::getInstance().wayToTheElement.clear();
}
