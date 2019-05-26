#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    for(int i=1; i<5;i++){
    ui->comboBox_2->addItem(QString(" %1 ").arg(i));
    }
}

Settings::~Settings()
{
    delete ui;
}
