#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QImage>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int N=3;
    ui->setupUi(this);

   // create(N,"C:/Users/Alina/Documents/pazzle/initial_image.jpg" );
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
    QLabel *label =  new QLabel();
    QString txt="pazzles";

    label->setText("pazzles");
   // label->setStyleSheet("background-image: url(file://C:/Users/Alina/Documents/pazzle/initial_image.jpg)");
   // QPixmap image("C:/Users/Alina/Documents/pazzle/initial_image.jpg");
    //label->setPixmap(image);
    label->setMinimumWidth(100);// You can set other properties similarly

    ui->gridLayout->addWidget(label, i, j);


        }
    }
}


void MainWindow::create(int N, QString filepath)
{
    QImage firstimage(filepath);

    //index - масив, в якому зберігаються місця
    for(int i=0; i<N*N; i++){


        pazzles[i].place=i+1;//потім зробити рандомне переміщення всередині
        pazzles[i].rotation= rand()%4;
    }

    //порізати картинку для пазлу
    for(int i=0; i<N; i++){
        //(0;0+l/n;l/n;l/n+l/n)
        QImage copy ;
        copy = image.copy( 0, 0, 300, 300); //((поки воводжу одну й ту саму картинку))
        copy.save("cropped_image.jpg");

    }
  //  QList<Pazzl> result;
}




MainWindow::~MainWindow()
{

    delete ui;
}
