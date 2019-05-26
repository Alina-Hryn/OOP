#include "initial.h"
#include "ui_initial.h"

Initial::Initial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Initial)
{
    ui->setupUi(this);
}

Initial::~Initial()
{
    delete ui;
}
