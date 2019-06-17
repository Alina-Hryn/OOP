#include "slcircular.h"



SLcircular::~SLcircular()
 {
   while (size != 0)
    {
     Node *temp = Head->Next;
     delete Head;
     Head = temp;
     size--;
    }
 }

int SLcircular::Count()
 {
   return size;
 }


void SLcircular::Add(Official person)
{
 size++;
 Node  *temp = new Node;
 temp->Next = Head;
 temp->official = person;

    if (Head != nullptr)
     {
      Tail->Next = temp;
      Tail = temp;
     }
    else Head = Tail = temp;
}


void SLcircular::Show(int temp)
 {
    Node *tempHead = Head;

    temp = size;
   while (temp != 0)
    {
      //cout << tempHead->official << " ";
      tempHead = tempHead->Next;
      temp--;
    }
 }
