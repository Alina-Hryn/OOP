#include "puzzle.h"
#include "ui_puzzle.h"
#include <QFileDialog>

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
#include <QDebug>
#include <QMouseEvent>

QVector<int> places;

puzzle::puzzle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::puzzle)
{
    ui->setupUi(this);
    show();

        QPixmap pixmap("C:/Users/Alina/Desktop/newPuzzle/1/1.jpg");
        pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);
        QPixmap small=pixmap;
        small = small.scaled(200, 200, Qt::IgnoreAspectRatio);
        QLabel *label=new QLabel;
        label->setPixmap(small);
        ui->gridLayout_3->addWidget(label, 0,0);
        int N = 4;
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

                    label->setPixmap(result.piece);

                    ClickableLabel::connect(label, SIGNAL(clicked()), this, SLOT(pic_clicked()));
                    ui->gridLayout->addWidget(label, result.place/N, result.place%N);
                }
        }


}

void puzzle::pic_clicked()
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


        picture1 = NULL;

    }
}


puzzle::~puzzle()
{
    delete ui;
}
