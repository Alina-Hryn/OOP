#ifndef SORT_H
#define SORT_H
#include<QVector>
#include"singleton.h"
#include"slcircular.h"
#include <algorithm>

class Sort
{
  public:
    QVector<Official> unsorted;
    int numberOfElements;
    virtual void info() = 0;
    virtual ~Sort() {}
};
/*
class Insertion: public Sort
{
  public:
    void info() {

    };
};

class Heap: public Sort
{
  public:
    void info() {
    };
};

class Merge: public Sort
{
  public:
    void info() {
    };
};

class Bucket: public Sort
{
  public:
    void info() {
    };
};


class SortFacory
{
public:
    virtual QVector<Official> sort();
    virtual Sort* show();

    virtual ~SortFacory(){}
};

#endif // SORT_H



class InsertFacory: public SortFacory
{
  public:
    QVector<Official> sort(QVector<Official> arr,int n, int priority) {
        int i,j;
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
           return arr;
    }
};

class HeapFacory: public SortFacory
{
  public:

};

class MergeFacory: public SortFacory
{
 // public:
  //  Sort* sort();
};

class BucketFacory: public SortFacory
{
  public:
    QVector<Official> sort(QVector<Official> arr,int n, int priority) {
        // 1) Create n empty buckets
            QVector<Official> b[n];

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
            return arr;
    }
};

*/

#endif // SORT_H
