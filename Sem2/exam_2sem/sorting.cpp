#include "sorting.h"
#include "ui_sorting.h"
#include"singleton.h"
#include"sortFactory.h"
#include"slcircular.h"
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
    SortFactory* sortFactory= new QuickFactory();
    Sort* s=sortFactory->createSort();
    QVector<int> OffYearsInMinistry;
    for(int i=0; i<Singleton::getInstance().AllOfficials.size();i++){
        OffYearsInMinistry.push_back(Singleton::getInstance().AllOfficials[i].yearsInMinistry);
    }
    s->applysort(OffYearsInMinistry);
    /*for(auto off : sorted) {
        std::cout<<off.yearsInMinistry<<std::endl;
    }*/

}
