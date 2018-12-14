#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "clickablelabel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ClickableLabel* picture1;
    struct Puzzle{
        QPixmap piece;
        int index;
        int place;
        int rotation;
    };
    int N;



private slots:
    void on_pushButton_clicked();
    void pic_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
