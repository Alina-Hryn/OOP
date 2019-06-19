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
    int yearsInMinistry;
    QString univ;
public:
    bool Compare(QString a, QString b){
        int min=a.size();
        if(a > b)
            min=b.size();
        for(int i=0;i < min;i++){
            if(a[i] < b[i])
                return true;
            if(a[i] > b[i])
                return false;
        }
        return true;
    }
    bool Larger(Official f, Official s, int n){
        if( n==7){
            if(f.yearsInMinistry>s.yearsInMinistry)
                return true;
            else {
                return false;
            }
        }
        else{
            switch (n) {
            case 1: return Compare(f.ministry, s.ministry);
            case 2: return Compare(f.organization, s.organization);
            case 3: return Compare(f.unit, s.unit);
            case 4: return Compare(f.sirname, s.sirname);
            case 5: return Compare(f.name, s.name);
            case 6: return Compare(f.secondName, s.secondName);
            case 8: return Compare(f.univ, s.univ);

            }
        }
    }
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
