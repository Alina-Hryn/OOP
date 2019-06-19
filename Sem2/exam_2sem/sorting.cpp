#include "sorting.h"
#include "ui_sorting.h"

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


}
