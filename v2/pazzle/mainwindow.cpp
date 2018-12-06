#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QImage>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image("C:/Users/Alina/Documents/pazzle/initial_image.jpg");
    ui->label->setPixmap(image);
}
const int N=4;

struct Pazzl{
    QImage square;//
    int index;//"правильне" місце для пазла
    int rotation;//поворот пазла(вкінці повинен дорівнювати 0)
    int place;//поточне місце пазла
};

class picture{
    QImage image;
    Pazzl pazzles[N*N];
public:
    void create() {
        QImage image("C:/Users/Alina/Documents/pazzle/initial_image.jpg");

        //index - масив, в якому зберігаються місця
        for(int i=0; i<N*N; i++){

            pazzles[i].index=i+1;
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
    }
};


MainWindow::~MainWindow()
{

    delete ui;
}
