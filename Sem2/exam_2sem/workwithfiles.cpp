#include "workwithfiles.h"
#include"slcircular.h"
#include"singleton.h"

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
         //qDebug()<<str;
         str=str.left(str.size()-3);
        int pos = str.lastIndexOf(QChar(';'));
        person.univ=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.yearsInMinistry=str.right(str.size()-pos-1).toInt();
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.secondName=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.name=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.sirname=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.unit=str.right(str.size()-pos-1);
        str=str.left(pos);
        pos = str.lastIndexOf(QChar(';'));
        person.organization=str.right(str.size()-pos-1);
        person.ministry=str.left(pos);
        Singleton::getInstance().AllOfficials.push_back(person);
        qDebug()<<person.ministry<<"  "<<person.organization<<"  "<<person.unit<<"  "<<person.sirname<<"  "<<person.name<<"  "<<person.secondName<<"  "<<person.yearsInMinistry<<"  "<<person.univ<<"  ";
    }
    //qDebug()<<list->Count();
}
