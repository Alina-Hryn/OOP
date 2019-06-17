#include "workwithfiles.h"
#include"slcircular.h"

#include<QFile>
#include<QIODevice>
#include<QDebug>

WorkWithFiles::WorkWithFiles()
{

}

void WorkWithFiles::readFile(){
    SLcircular *list;
    Official person;
    QFile file(":/data/data.txt");
    if (!file.open(QIODevice::ReadOnly)){
        qDebug()<<"notopen";
        return;
    }
    while (!file.atEnd())
    {
         QByteArray line = file.readLine();
         QString str = QString::fromUtf8(line);
         qDebug()<<str;
        int pos = str.lastIndexOf(QChar('<'));
        person.ministry=str.left(pos);
        str=str.right(str.size()-pos-1);
        pos = str.lastIndexOf(QChar('>'));
        person.organization=str.left(pos);
        str=str.right(str.size()-pos-1);
        pos = str.lastIndexOf(QChar('{'));
        person.unit=str.left(pos);
        str=str.right(str.size()-pos-1);



        pos = str.lastIndexOf(QChar('}'));
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.secondName=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.sirname=str.left(pos);
        person.name=str.right(str.size()-pos-1);
        //list->Add(person);
        qDebug()<<person.ministry<<"  "<<person.organization<<"  "<<person.unit<<"  "<<person.sirname<<"  "<<person.name<<"  "<<person.secondName<<"  ";
    }
    qDebug()<<list->Count();
}
