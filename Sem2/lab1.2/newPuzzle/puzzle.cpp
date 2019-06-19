#include "puzzle.h"
#include "ui_puzzle.h"
#include"singleton.h"
#include"end.h"
#include"settings.h"
#include <QFileDialog>

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
#include <QDebug>
#include <QStyle>
#include <QMouseEvent>
#include <QDebug>
#include<QSettings>
#include <QMutex>


QVector<int> places;


puzzle::puzzle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::puzzle)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    show();
    places.clear();
    picture1 = NULL;
    if(Singleton::getInstance().wayToTheElement == nullptr){
        Singleton::getInstance().wayToTheElement=":/levels/back.jpg";
        Singleton::getInstance().width=5;
    }
        QPixmap pixmap(Singleton::getInstance().wayToTheElement);
        //QPixmap pixmap(":/levels/1.jpg");
        pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);
        QPixmap small=pixmap;
        small = small.scaled(200, 200, Qt::IgnoreAspectRatio);
        QLabel *label=new QLabel;
        label->setPixmap(small);
        ui->gridLayout_3->addWidget(label, 0,0);
        int N = Singleton::getInstance().width;
        QVector <Puzzle> puzzle;

        for(int i=0;i<N*N;i++){
            places.push_back(i);
        }
        std::random_shuffle(places.begin(), places.end());
               // std::random_shuffle(places.begin(), places.end());


        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){

                    ClickableLabel *label = new ClickableLabel();
                    label->place=places[i*N+j];
                    label->index=(i)*N+j;
                    Puzzle result;
                    result.index=(i)*N+j;
                    result.place=places[i*N+j];
                    QRect rect(j*1000/N, i*1000/N, 1000/N, 1000/N);
                    QPixmap cropped = pixmap.copy(rect);
                    cropped = cropped.scaled(1000/N/2, 1000/N/2, Qt::IgnoreAspectRatio);
                    result.piece=cropped;
                    puzzle.push_back(result);
                    label->setPixmap(result.piece);
                    if(result.index==result.place){
                        label->setStyleSheet("border: 4px solid #FFF851;");
                    }
                    else
                    label->setStyleSheet("border: none;");

                    ClickableLabel::connect(label, SIGNAL(clicked()), this, SLOT(pic_clicked()));
                    ui->gridLayout->addWidget(label, result.place/N, result.place%N);

                }
        }
        QLayoutItem *l1=ui->gridLayout->itemAtPosition(0,0);
        QLayoutItem *l2=ui->gridLayout->itemAtPosition(0,1);
        swapElements(l1,l2);

}

void puzzle::swapElements(QLayoutItem *l1,QLayoutItem *l2){

    //ClickableLabel *a=l1->widget();
    ClickableLabel *a=static_cast<ClickableLabel*>(l1->widget());
    ClickableLabel *b=static_cast<ClickableLabel*>(l2->widget());
    picture1=a;
    b->emitClick();

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
        qDebug()<< "picture1  "<< picture1->index;
        qDebug()<< "obj                 "<< obj->index;


        auto gp = qMakePair(-1,-1);
        int index = ui->gridLayout->indexOf(obj);
        int rs,cs;
        ui->gridLayout->getItemPosition(index, &gp.first, &gp.second, &rs, &cs);


        auto gp1 = qMakePair(-1,-1);
        int index1 = ui->gridLayout->indexOf(picture1);
        int rs1,cs1;
        ui->gridLayout->getItemPosition(index1, &gp1.first, &gp1.second, &rs1, &cs1);

        //qDebug()<< "picture1 1 "<< picture1->index<<"  "<<picture1->place;
        //qDebug()<< "obj                 "<< obj->index<<"  "<<obj->place;
        ui->gridLayout->removeWidget(picture1);
        ui->gridLayout->removeWidget(obj);
        ui->gridLayout->addWidget(picture1, gp.first, gp.second);
        ui->gridLayout->addWidget(obj, gp1.first, gp1.second);


        int var=picture1->place;
        picture1->place=obj->place;
        obj->place=var;


      places[picture1->index]=picture1->place;
      places[obj->index]=obj->place;
     // qDebug()<< "picture1 2 "<< picture1->index<<"  "<<places[picture1->index];
     // qDebug()<< "obj                 "<< obj->index<<"  "<<places[obj->index];




            if(obj->place==obj->index){
                obj->setStyleSheet("border: 4px solid #FFF851; ");

            }
            if(obj->place != obj->index) {
                obj->setStyleSheet("border: none;");
            }
            if(picture1->place == picture1->index){
                picture1->setStyleSheet("border: 4px solid #FFF851;");
            }
            if(picture1->place != picture1->index) {
                picture1->setStyleSheet("border: none;");
            }




        picture1 = NULL;


    }
    int trueN =0;
    for(int i=0;i<places.size();i++){
        if(places[i]==i){
            trueN++;
        }
    }
    if(trueN==places.size()){


           //checking if this level was visited earlier
           if(Singleton::getInstance().IfLevels==true){
               bool a=false;
               for(int i=0; i<Singleton::getInstance().visitedLevels.size();i++){
                   if(Singleton::getInstance().visitedLevels[i]==Singleton::getInstance().sublevel){
                       a=true;
                   }
               }
               if(a==false){
                   bool ifNew=true;
                   for(int i=0; i< Singleton::getInstance().visitedLevels.size();i++){
                       if(Singleton::getInstance().wayToTheElement== Singleton::getInstance().visitedLevels[i])
                           ifNew=false;
                   }
                   if(ifNew){
                       Singleton::getInstance().NumberOfStars+=5;
                   }
                   Singleton::getInstance().visitedLevels.push_back(Singleton::getInstance().wayToTheElement);
               }
           }
           QMutex mutex;
              mutex.lock();
              //mutex.tryLock(1000);
              mutex.unlock();
              Singleton::getInstance().IfLevels=false;
              Singleton::getInstance().wayToTheElement=nullptr;
              Singleton::getInstance().sublevel=0;
            hide();
            End w;
            w.setModal(true);
            w.exec();


    }

}


puzzle::~puzzle()
{
    delete ui;
}

void puzzle::on_pushButton_clicked()
{

    Settings w;
    w.setModal(true);
    w.exec();
}




