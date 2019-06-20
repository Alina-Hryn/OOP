#ifndef SINGLETON_H
#define SINGLETON_H


#include<QString>
#include<QDialog>
#include<QVector>


class Singleton
{

private:
   Singleton() {}



public:
    static Singleton& getInstance() {
        static Singleton  instance;
        return instance;
    }
    QString wayToTheElement;
    int width;
    bool IfLevels;
    int sublevel;
    int NumberOfStars;
    int sort;
    QVector <QString> visitedLevels;

};

#endif // SINGLETON_H
