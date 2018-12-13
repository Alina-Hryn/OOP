#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

    QPixmap pixmap(":/rec/image.png");
    pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);


    int N = 5;
    QVector <Puzzle> puzzle;

    QVector<int> places;
    for(int i=1;i<=N*N;i++){
        places.push_back(i);
    }
    std::random_shuffle(places.begin(), places.end());


    for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                QLabel *label =  new QLabel();
                Puzzle result;
                result.index=(i-1)*N+j;
                result.place=places[(i-1)*N+j-1];
                QRect rect((j-1)*1000/N, (i-1)*1000/N, 1000/N, 1000/N);
                QPixmap cropped = pixmap.copy(rect);
                cropped = cropped.scaled(1000/N, 1000/N, Qt::IgnoreAspectRatio);
                result.piece=cropped;
                puzzle.push_back(result);
                            //QPainter p;
                            //QPointF center(cropped.width() / qreal(2), cropped.height() / qreal(2));
                            //p.translate(center);
                            //p.rotate(90);
                            //p.translate(-center);

                //label->setPixmap(result.piece);
                label->setText(QString(" %1 ").arg(puzzle[(i-1)*N+j-1].place));
                ui->gridLayout->addWidget(label, i, j);

            }
            //вектор пазлів по порядку
           /* std::sort(puzzle.begin(), puzzle.end(), [](const Puzzle& a, const Puzzle& b) -> bool
                 {
                     return a.place < b.place;
                 });*/

             for(int i=1;i<=N;i++){
                     for(int j=1;j<=N;j++){
                         QLabel *label =  new QLabel();
                         //label->setPixmap(puzzle[(i-1)*N+j-1].piece);
                         label->setText(QString(" %1 ").arg(puzzle[(i-1)*N+j-1].place));
                         ui->gridLayout->addWidget(label, i, j);

                     }
                     }





    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
