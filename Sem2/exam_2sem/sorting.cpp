#include "sorting.h"
#include "ui_sorting.h"
#include"singleton.h"
#include"sortFactory.h"
#include<QDebug>
#include <iostream>

Sorting::Sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sorting)
{
    ui->setupUi(this);
}

Sorting::~Sorting()
{
    delete ui;
}


void Sorting::on_pushButton_clicked()
{
    SortFactory* sortFactory= new InsertFactory();
    Sort* s=sortFactory->createSort();
    QVector<Official> sorted = s->applysort(Singleton::getInstance().AllOfficials,7);
    for(auto off : sorted) {
        std::cout<<off.yearsInMinistry<<std::endl;
    }

}
