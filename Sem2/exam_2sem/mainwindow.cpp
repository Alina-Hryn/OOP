#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"workwithfiles.h"
#include"sorting.h"
#include"newperson.h"
#include"listofpersons.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WorkWithFiles a;
    a.readFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Sorting wind;
    wind.setModal(true);
    wind.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    ListOfPersons wind;
    wind.setModal(true);
    wind.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    NewPerson w;
    w.setModal(true);
    w.exec();
}
