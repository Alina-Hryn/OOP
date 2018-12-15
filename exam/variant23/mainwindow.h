#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class Task{
   int type;
   double  size;
public:
    void create(){
        type=rand()%7+1;
        size=rand()%100+(rand()%10)/10+1;
    }

};

class Approach{
 public:
    int NumberOfTypesOfTasks;
    int TypeOfApproach;
    int typeOfTaskThatCanBeSolved;
    double posibility;
    bool IfCanBeRepeated;
    double timeToDo;
    double WastedTime;
    int attempt;
    int N;
    int n;
    int success1;
    bool success;
    QVector<int> IfSameTypesWereSolved;
    void Ifsuccess(){
        N=rand()%10+1;
        n=rand()%N+1;
        success1=rand()%N;
        if(success1<=n)
            success=1;
        else {
            success=0;
        }
    }
    void create(){
        typeOfTaskThatCanBeSolved=rand()%NumberOfTypesOfTasks;
        posibility=(rand()%100+1)/100;
        IfCanBeRepeated=rand()%2;
        WastedTime=0;
        attempt=1;
        timeToDo=(rand()%10)/10+rand()%8+1;
        Ifsuccess();
        for(int i=0; i<NumberOfTypesOfTasks;i++){
           IfSameTypesWereSolved.push_back(0);
        }
    }
};

class FirstApproach: public Approach{
public:

       void solve(){
        if(success==1)
            IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]++;
        else{
        if(IfCanBeRepeated==1){
            attempt++;
            timeToDo+=timeToDo;
            Ifsuccess();

        }
        else {
          printf("Can`t be reapeted");
        }
        }
    }
};
class ThirdApproach: public Approach{
public:
    void solve(){
        if(success==1)
            IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]++;
        else{
            if(IfCanBeRepeated==1){
                attempt++;
                timeToDo+=timeToDo;
                N++;
                Ifsuccess();
            }
            else {
              printf("Can`t be reapeted");
            }

        }
    }
};

class SecondApproach: public Approach{
public:
    void solve(){
        if(success==1)
            IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]++;
        else{
            if(IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]>0){
                attempt++;
                timeToDo-=(rand()%10)/10;
                N--;
                Ifsuccess();
            }
            else {
              printf("Can`t be reapeted");
            }

        }
    }

};

class FourthApproach: public Approach{
public:
    void solve(){
        if(success==1)
            IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]++;
        else{
            if(IfSameTypesWereSolved[typeOfTaskThatCanBeSolved]>0){
                attempt++;
                timeToDo-=(rand()%10)/10;
                N--;
                Ifsuccess();
            }
            else {
              printf("Can`t be reapeted");
            }

        }
    }

};

#endif // MAINWINDOW_H
