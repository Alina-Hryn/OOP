#ifndef SLCIRCULAR_H
#define SLCIRCULAR_H
#include<QString>

struct Official{
    QString ministry;
    QString organization;
    QString unit;
    QString sirname;
    QString name;
    QString secondName;
};
class SLcircular
{


    struct  Node
     {
       Official official;
       Node *Next;
     };

    Node *Head, *Tail;
          int size;

          SLcircular():Head(nullptr),Tail(nullptr),size(0){};
          ~SLcircular();
       public:
          void Add(Official person);
          void Show(int size);
          int Count();


};

#endif // SLCIRCULAR_H
