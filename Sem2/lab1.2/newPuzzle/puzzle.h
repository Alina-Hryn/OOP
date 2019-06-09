#ifndef PUZZLE_H
#define PUZZLE_H

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
       struct Puzzle{
           QPixmap piece;
           int index;
           int place;
           int rotation;
       };
       int N;
private slots:

    void pic_clicked();



private:
    Ui::puzzle *ui;
};

#endif // PUZZLE_H
