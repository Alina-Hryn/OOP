#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct Pazzl{
    QImage square;//

    int rotation;//поворот пазла(вкінці повинен дорівнювати 0)
    int place;//поточне місце пазла
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int choosed;
public:
    QImage image;
    QList<Pazzl> pazzles;
    void create(int N, QString filepath="C:/Users/Alina/Documents/pazzle/initial_image.jpg");
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
