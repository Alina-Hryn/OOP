#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
#include <QDebug>
#include <QMouseEvent>

QVector<int> places;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    picture1 = NULL;
    ui->setupUi(this);
    show();

    QPixmap pixmap(":/rec/quad_24.jpg");
    pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);
    QPixmap small=pixmap;
    small = small.scaled(200, 200, Qt::IgnoreAspectRatio);
    QLabel *label=new QLabel;
    label->setPixmap(small);
    ui->gridLayout_3->addWidget(label, 0,0);
    int N = 5;
    QVector <Puzzle> puzzle;

   // QVector<int> places;
    for(int i=0;i<N*N;i++){
        places.push_back(i);
    }
    std::random_shuffle(places.begin(), places.end());


    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ClickableLabel *label = new ClickableLabel();
                Puzzle result;
                result.index=(i)*N+j+1;
                result.place=places[i*N+j];
                QRect rect(j*1000/N, i*1000/N, 1000/N, 1000/N);
                QPixmap cropped = pixmap.copy(rect);
                cropped = cropped.scaled(1000/N/2, 1000/N/2, Qt::IgnoreAspectRatio);
                result.piece=cropped;
                puzzle.push_back(result);
                            //QPainter p;
                            //QPointF center(cropped.width() / qreal(2), cropped.height() / qreal(2));
                            //p.translate(center);
                            //p.rotate(90);
                            //p.translate(-center);

                label->setPixmap(result.piece);

                ClickableLabel::connect(label, SIGNAL(clicked()), this, SLOT(pic_clicked()));

                //label->setText(QString(" %1 ").arg(puzzle[(i-1)*N+j-1].place));
                ui->gridLayout->addWidget(label, result.place/N, result.place%N);
            }
    }



}

void MainWindow::pic_clicked()
{

    ClickableLabel* obj = (ClickableLabel*)sender();


    if(picture1==NULL){
        picture1=obj;
    }
    else if(picture1==obj){
        picture1=NULL;
}
    else {

        auto gp = qMakePair(-1,-1);
        int index = ui->gridLayout->indexOf(obj);
        int rs,cs;
        ui->gridLayout->getItemPosition(index, &gp.first, &gp.second, &rs, &cs);


        auto gp1 = qMakePair(-1,-1);
        int index1 = ui->gridLayout->indexOf(picture1);
        int rs1,cs1;
        ui->gridLayout->getItemPosition(index1, &gp1.first, &gp1.second, &rs1, &cs1);

        ui->gridLayout->removeWidget(picture1);
        ui->gridLayout->removeWidget(obj);
        ui->gridLayout->addWidget(picture1, gp.first, gp.second);
        ui->gridLayout->addWidget(obj, gp1.first, gp1.second);
        int a;
       // a=places[gp1.first*N+gp1.second];
       // places[gp1.first*N+gp1.second]=places[gp.first*N+gp.second];
       // places[gp.first*N+gp.second]=a;
        a=0;
        for(int i=0; i<N*N;i++){
            if(places[i]==i)
                a++;
        }

        picture1 = NULL;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
}





