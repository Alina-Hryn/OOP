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
    QVector<Official> unsorted;
    int numberOfElements;
    virtual QVector<Official> applysort(QVector<Official> arr, int priority) = 0;

};

class Insertion: public Sort
{
  public:
    QVector<Official> applysort(QVector<Official> arr, int priority) {
        int i,j;
        int n=arr.size();
        //qDebug()<<arr;
        Official key;
           for (i = 1; i < n; i++)
           {
               key = arr[i];
               j = i - 1;

               while (j >= 0 && arr[j].Larger(arr[j],key,priority))
               {
                   arr[j + 1] = arr[j];
                   j = j - 1;
               }
               arr[j + 1] = key;
           }
          //qDebug()<<arr;
          return arr;
    }

};

class Heap: public Sort
{
  public:
    QVector<Official> applysort(QVector<Official> arr, int priority)  {
    };
};

class Merge: public Sort
{
  public:
    QVector<Official> applysort(QVector<Official> arr, int priority)  {
    };
};

class Bucket: public Sort
{
  public:
    QVector<Official> applysort(QVector<Official> arr, int priority)  {
          /*      int n=arr.size();
            // 1) Create n empty buckets
                QVector<Official> b;

                // 2) Put array elements in different buckets
                for (int i=0; i<n; i++)
                {
                   int bi = n*arr[i].yearsInMinistry; // Index in bucket
                   b[bi].push_back(arr[i]);
                }

                // 3) Sort individual buckets
                for (int i=0; i<n; i++)
                   (b[i].begin(), b[i].end());

                // 4) Concatenate all buckets into arr[]
                int index = 0;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < b[i].size(); j++)
                      arr[index++] = b[i][j];
                return arr;*/
        return arr;

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

class HeapFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Heap();
    }
};

class MergeFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Merge();
    }
};

class BucketFactory: public SortFactory
{
  public:
    Sort* createSort(){
        return new Bucket();
    }

};


#endif // SLCIRCULAR_H
