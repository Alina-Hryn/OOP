#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"workwithfiles.h"
#include"sorting.h"

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
