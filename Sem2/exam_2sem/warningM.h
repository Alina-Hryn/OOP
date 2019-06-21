#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class warningM;
}

class warningM : public QDialog
{
    Q_OBJECT

public:
    explicit warningM(QWidget *parent = nullptr);
    ~warningM();

private slots:
    void on_pushButton_clicked();

private:
    Ui::warningM *ui;
};

#endif // WARNING_H
