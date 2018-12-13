#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPainter>
#include <QPointF>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

    QPixmap pixmap(":/rec/image.png");
    pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);


    int N = 5;
    QImage image(":/rec/image.png");


    /*for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            QLabel *label =  new QLabel();
            QRect rect((i-1)*160, (j-1)*160, i*160, j*160);
            QPixmap cropped = pixmap.copy(rect);
            cropped = cropped.scaled(100, 100, Qt::IgnoreAspectRatio);
            label->setPixmap(cropped);
            ui->gridLayout->addWidget(label, i, j);

        }*/
    for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                QLabel *label =  new QLabel();
                QRect rect((j-1)*1000/N, (i-1)*1000/N, 1000/N, 1000/N);

                QPixmap cropped = pixmap.copy(rect);
                cropped = cropped.scaled(100, 100, Qt::IgnoreAspectRatio);
                //QPainter p;
                //QPointF center(cropped.width() / qreal(2), cropped.height() / qreal(2));
                //p.translate(center);
                //p.rotate(90);
                //p.translate(-center);

                label->setPixmap(cropped);
                ui->gridLayout->addWidget(label, i, j);

            }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
