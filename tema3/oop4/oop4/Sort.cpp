#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <stdarg.h>
using namespace std;
void QuickSort1(int v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort1(v, st, i - 1);
		QuickSort1(v, i + 1, dr);
	}
}
void Sort::InsertSort()
{
    for (int i = 1; i < nrel; i++)
    {
        int x = el[i];
        int p = i - 1;
        while (p >= 0 && el[p] > x)
            el[p + 1] = el[p], p--;
        el[p + 1] = x;
    }
}
void Sort::QuickSort()
{
	QuickSort1(el, 0, nrel - 1);

}
void Sort::BubbleSort()
{
    int i, j;
    for (i = 0; i < nrel - 1; i++)

        
        for (j = 0; j < nrel - i - 1; j++)
            if (el[j] > el[j + 1])
                swap(el[j], el[j + 1]);
}
void Sort::Print()
{
	for (int i = 0; i < this->nrel; i++)
		cout << el[i] << " ";

}
int  Sort::GetElementsCount()
{
	return nrel;
}
int  Sort::GetElementFromIndex(int index)
{
	return el[index];
}
Sort::Sort(int mini, int maxi, int n)
{
    this->nrel = n;
    srand((unsigned)time(NULL));

    for (int i = 0; i < this->nrel; i++)
    {
        int ra = rand();
        el[i] = ra % maxi;
    }
}
Sort::Sort(int v[], int n)
{
    this->nrel = n;
    for (int i = 0; i < this->nrel; i++)
        el[i] = v[i];
}
Sort::Sort(char a[])
{
    int k = 0;
    int i = 0;
    int j = 0;
    el[0] = 0;
    while (a[i] != NULL)
    {
        if (a[i] == ','&&a[i+1]==NULL)
        {
            break;
        }
        if (a[i] == ',')
        {
            k++;
            el[k] = 0;
            i++;
        }
        else {
            el[k] = el[k] * 10 + (a[i] - 48);
            i++;
        }
    }
    this->nrel = k+1;
}
Sort::Sort(int n, ...)
{

    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; ++i) {
        el[i] = va_arg(args, int);
    }
    va_end(args);
    this->nrel = n;
}

