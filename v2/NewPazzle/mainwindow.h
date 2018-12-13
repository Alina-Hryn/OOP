#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct Puzzle{
        QPixmap piece;
        int index;
        int place;
        int rotation;
    };

private slots:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
