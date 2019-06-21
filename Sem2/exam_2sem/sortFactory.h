#ifndef SORT_H
#define SORT_H
#include<QVector>
#include"singleton.h"
#include"slcircular.h"
#include <algorithm>
#include<QDebug>

class Sort
{
  public:
    virtual void applysort(QVector<int> &arr) = 0;


};



class Insertion: public Sort
{
  public:
    void applysort(QVector<int> &data) {

        int j, val;

          //iterate through entire list
          for(int i = 1; i < data.size(); i++){
             val = data[i];
             j = i - 1;

             while(j >= 0 && data[j] > val){
                       data[j + 1] = data[j];
                       j = j - 1;

             }//end while
             data[j + 1] = val;

    }
    }

};

class Bubble: public Sort
{
  public:

    void applysort(QVector<int> &arr)  {
        bool swapp = true;
             while(swapp){
               swapp = false;
               for (int i = 0; i < arr.size()-1; i++) {
                   if (arr[i]>arr[i+1] ){
                       arr[i] += arr[i+1];
                       arr[i+1] = arr[i] - arr[i+1];
                       arr[i] -=arr[i+1];
                       swapp = true;

                   }
               }
           }
     }
};





class Heap: public Sort
{
  public:
    void Swap(QVector<int>& vHeap, QVector<int>::size_type i, QVector<int>::size_type j)
    {
        if(i == j)
            return;

        int temp;
        temp = vHeap[i];
        vHeap[i] = vHeap[j];
        vHeap[j] = temp;


    }
    void Sift(QVector<int>& vHeap, const QVector<int>::size_type heapSize, const QVector<int>::size_type siftNode)
    {
        QVector<int>::size_type i, j;

        j = siftNode;
        do
        {
            i = j;
            if(((2*i + 1) < heapSize) && vHeap[j] < vHeap[2*i + 1])
                j = 2*i + 1;
            if(((2*i + 2) < heapSize) && vHeap[j] < vHeap[2*i + 2])
                j = 2*i + 2;

            Swap(vHeap, i, j);
        }
        while(i != j);
    }

    void MakeInitialHeap(QVector<int>& vHeap)
    {
        for(int i = vHeap.size()- 1; i >= 0; --i)
        {
            Sift(vHeap, vHeap.size(), i);
        }
    }

    void applysort(QVector<int> &arr)
    {
        MakeInitialHeap(arr);
            for(std::vector<int>::size_type i = arr.size()-1; i > 0; --i)
            {
                Swap(arr, i, 0);
                Sift(arr, i, 0);


            }
    }
};

class Quick: public Sort
{
  public:
    int partition(QVector<int> & a, int start, int end) {
      int pivot = a[start];
      int from_left = start+1;
      int from_right = end;
      int tmp;

      while (from_left != from_right) {
        if (a[from_left]  <= pivot) from_left++;
        else {
          while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
          //cout << "swaping " << a[from_left] << " with "<< a[from_right] << endl;
          tmp =  a[from_right];
          a[from_right] = a[from_left];
          a[from_left] = tmp;

        }
      }

      if (a[from_left]>pivot) from_left--;
      a[start] = a[from_left];
      a[from_left] = pivot;

      return (from_left);
    }

    /*
      Recursive QS function. Base case is an empty vector.
      Precondition:
      Postcondition: The vector that was passed as parameter will be
        sorted in ascending order.
    */
    void quickSort(QVector <int> & a, int p, int r) {
      if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
      }
    }
    void applysort(QVector<int> &arr)  {
        quickSort(arr,0,arr.size()-1);
    }
};


class SortFactory
{
public:

    virtual Sort* createSort() = 0;
};




class InsertFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Insertion();
    }

};

class BubbleFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Bubble();
    }
};

class HeapFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Heap();
    }
};

class QuickFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Quick();
    }

};


#endif // SLCIRCULAR_H
