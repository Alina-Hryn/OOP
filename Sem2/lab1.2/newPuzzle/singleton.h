#ifndef SINGLETON_H
#define SINGLETON_H

#include<QString>
#include<QDialog>


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




};

#endif // SINGLETON_H
