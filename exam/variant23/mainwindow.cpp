#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int b=rand()%10;
    vector<Approach> Approches;
    for(int i=0;i<b;i++){
        Approach piece;
        piece.TypeOfApproach=rand()%3+1;
        switch(piece.TypeOfApproach){
        case 1:
           { FirstApproach fa;
            fa.create();
            fa.solve();
            Approches.push_back(fa);
            break;
            }
        case 2:
        { SecondApproach fa;
         fa.create();
         fa.solve();
         Approches.push_back(fa);
         break;
         }
        case 3:
        { ThirdApproach fa;
         fa.create();
         fa.solve();
         Approches.push_back(fa);
         break;
         }
        case 4:
        { FourthApproach fa;
         fa.create();
         fa.solve();
         Approches.push_back(fa);
         break;
         }
        }
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
