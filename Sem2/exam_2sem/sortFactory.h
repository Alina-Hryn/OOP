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
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void heapify(int arr[], int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2*i + 1; // left = 2*i + 1
        int r = 2*i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            int a=arr[i];
            arr[i]=arr[largest];
            arr[largest]=a;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    QVector<Official> applysort(QVector<Official> arr, int priority)  {
        int r[arr.size()];
        for(int i=0; i<arr.size();i++){
            r[i]=arr[i].yearsInMinistry;
        }
        // Build heap (rearrange array)
        int n=arr.size();
            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(r, n, i);

            // One by one extract an element from heap
            for (int i=n-1; i>=0; i--)
            {
                // Move current root to end

                int a=r[0];
                r[0]=r[i];
                r[i]=a;

                // call max heapify on the reduced heap
                heapify(r, i, 0);
            }

    }
};

class Merge: public Sort
{
    //void merge(int arr[], int l, int m, int r) =0;

  public:
    void merge(int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    /* l is for left index and r is right index of the
       sub-array of arr to be sorted */

    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l+(r-l)/2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }
    QVector<Official> applysort(QVector<Official> arr, int priority)  {
        int r[arr.size()];
        for(int i=0; i<arr.size();i++){
            r[i]=arr[i].yearsInMinistry;
        }
        mergeSort(r, arr[0].yearsInMinistry,arr[arr.size()-1].yearsInMinistry);
    }
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
