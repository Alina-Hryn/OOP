#include "newperson.h"
#include "ui_newperson.h"

NewPerson::NewPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPerson)
{
    ui->setupUi(this);
}

NewPerson::~NewPerson()
{
    delete ui;
}
