#ifndef PUZZLE_H
#define PUZZLE_H

#include<QLayout>
#include <QDialog>
#include "clickablelabel.h"

namespace Ui {
class puzzle;
}

class puzzle : public QDialog
{
    Q_OBJECT

public:
    explicit puzzle(QWidget *parent = nullptr);
    ~puzzle();
    ClickableLabel* picture1;

       int N;
    void swapElements(QLayoutItem *l1,QLayoutItem *l2);
    void bubbleSort();
    bool IfFinished();
private slots:

    void pic_clicked();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::puzzle *ui;
};

#endif // PUZZLE_H
