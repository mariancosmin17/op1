#pragma once
class Sort
{
    int nrel;
    int el[100];
public:
    
    void InsertSort();
    void QuickSort();
    void BubbleSort();
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    Sort(int mini, int maxi, int nrel);
    Sort(int v[], int nrel);
    Sort(char a[]);
    Sort(int n, ...);
    
    
    
};

