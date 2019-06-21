#ifndef NEWPERSON_H
#define NEWPERSON_H

#include <QDialog>

namespace Ui {
class NewPerson;
}

class NewPerson : public QDialog
{
    Q_OBJECT

public:
    explicit NewPerson(QWidget *parent = nullptr);
    ~NewPerson();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NewPerson *ui;
};

#endif // NEWPERSON_H
