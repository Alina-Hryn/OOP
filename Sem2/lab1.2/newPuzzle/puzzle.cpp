#include "puzzle.h"
#include "ui_puzzle.h"
#include"singleton.h"
#include <QFileDialog>

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
#include <QDebug>
#include <QStyle>
#include <QMouseEvent>

QVector<int> places;


puzzle::puzzle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::puzzle)
{
    ui->setupUi(this);
    setStyleSheet( "background-color: pink;" );
    show();


        QPixmap pixmap(Singleton::getInstance().wayToTheElement);
        pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);
        QPixmap small=pixmap;
        small = small.scaled(200, 200, Qt::IgnoreAspectRatio);
        QLabel *label=new QLabel;
        label->setPixmap(small);
        ui->gridLayout_3->addWidget(label, 0,0);
        int N = Singleton::getInstance().width;
        QVector <Puzzle> puzzle;

       // QVector<int> places;
        for(int i=0;i<N*N;i++){
            places.push_back(i);
        }
        std::random_shuffle(places.begin(), places.end());


        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){

                    ClickableLabel *label = new ClickableLabel();
                    label->place=places[i*N+j];
                    Puzzle result;
                    result.index=(i)*N+j+1;
                    result.place=places[i*N+j];
                    QRect rect(j*1000/N, i*1000/N, 1000/N, 1000/N);
                    QPixmap cropped = pixmap.copy(rect);
                    cropped = cropped.scaled(1000/N/2, 1000/N/2, Qt::IgnoreAspectRatio);
                    result.piece=cropped;
                    puzzle.push_back(result);
                    label->setPixmap(result.piece);
                    if(result.index-1==result.place){
                        label->setStyleSheet("border: 4px solid red;");
                    }
                    else
                    label->setStyleSheet("border: 4px double black;");

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

        places[index1]=obj->place;
        places[index]=picture1->place;
        int trueN =0;
        for(int i=0;i<places.size();i++){
            if(places[i]==i){
                trueN++;
            }
        }
        if(trueN==places.size()){
            hide();
        }

            if(obj->place==ui->gridLayout->indexOf(obj)){
                obj->setStyleSheet("border: 4px solid red;");
            }
            if(obj->place != ui->gridLayout->indexOf(obj)) {
                obj->setStyleSheet("border: none;");
            }
            if(picture1->place == ui->gridLayout->indexOf(picture1)){
                picture1->setStyleSheet("border: 4px solid red;");
            }
            if(picture1->place != ui->gridLayout->indexOf(picture1)) {
                picture1->setStyleSheet("border: none;");
            }

        picture1 = NULL;

    }
}


puzzle::~puzzle()
{
    delete ui;
}
