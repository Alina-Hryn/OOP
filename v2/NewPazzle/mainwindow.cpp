#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/rec/image.png");
    pixmap = pixmap.scaled(100, 100, Qt::IgnoreAspectRatio);


    int N = 5;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            QLabel *label =  new QLabel();
            QRect rect(0, 0, 40, 40);
            QPixmap cropped = pixmap.copy(rect);
            label->setPixmap(cropped);
            ui->gridLayout->addWidget(label, i, j);

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
