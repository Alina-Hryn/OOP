#ifndef SINGLETON_H
#define SINGLETON_H
#include"slcircular.h"
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
   bool ifAscending;
   int typeOfElement;
   int priority;
   QVector <Official> AllOfficials;
    QVector <Official> choosedElements;
};

#endif // SINGLETON_H
