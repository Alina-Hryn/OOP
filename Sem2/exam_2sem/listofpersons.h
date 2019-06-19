#ifndef LISTOFPERSONS_H
#define LISTOFPERSONS_H

#include <QDialog>

namespace Ui {
class ListOfPersons;
}

class ListOfPersons : public QDialog
{
    Q_OBJECT

public:
    explicit ListOfPersons(QWidget *parent = nullptr);
    ~ListOfPersons();
    void form(int i);

private slots:


    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::ListOfPersons *ui;
};

#endif // LISTOFPERSONS_H
