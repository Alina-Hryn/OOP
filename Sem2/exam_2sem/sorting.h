#ifndef SORTING_H
#define SORTING_H

#include <QDialog>

namespace Ui {
class Sorting;
}

class Sorting : public QDialog
{
    Q_OBJECT

public:
    explicit Sorting(QWidget *parent = nullptr);
    ~Sorting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Sorting *ui;
};

#endif // SORTING_H
