
#include "forpleasure.h"
#include "ui_forpleasure.h"
#include "puzzle.h"
#include "singleton.h"
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>


forPleasure::forPleasure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forPleasure)
{
    ui->setupUi(this);

}

forPleasure::~forPleasure()
{
    delete ui;
}


void forPleasure::on_pushButton_clicked()
{

// картинка, яку вибираю
    if( ui->horizontalLayout_2->count()==1){
        ui->horizontalLayout_2->removeItem(ui->horizontalLayout_2->takeAt(0));
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/pic",
                                                    tr("Images (*.png *.xpm *.jpg)"));

    Singleton::getInstance().wayToTheElement=fileName;
    QPixmap pixmap(fileName);
    Singleton::getInstance().width=ui->spinBox->value();
    pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
    QLabel *label=new QLabel;
    label->setPixmap(pixmap);
    ui->horizontalLayout_2->addWidget(label);
//


}

void forPleasure::on_pushButton_2_clicked()
{
    hide();
    puzzle window;
    window.setModal(true);
    window.exec();
}


