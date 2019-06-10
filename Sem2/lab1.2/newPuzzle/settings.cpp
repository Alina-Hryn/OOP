#include "settings.h"
#include "menu1.h"
#include "puzzle.h"
#include "singleton.h"
#include "ui_settings.h"
#include<QStyle>
#include<QSettings>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    int a= Singleton::getInstance().NumberOfStars;
    ui->label->setText(QString::number(a));
    QPixmap pixmap("C:/Users/Alina/Desktop/newPuzzle/star.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    QLabel *label=new QLabel;
    label->setPixmap(pixmap);
    ui->gridLayout_2->addWidget(label, 0,0);

}

Settings::~Settings()
{
    delete ui;
}



void Settings::on_pushButton_clicked()
{
    hide();
}
