#include "Sort.h"

#include <iostream>
using namespace std;
int main()
{
    char x[] = "1,5,3,10,6,4";
    int v[] = { 5,7,4,10,4,21,32 };
    Sort a(v, 7);
    Sort b(1, 99, 8);
    Sort c(x);
    Sort d(5, 1, 70, 3, 81, 2);
    Sort e{v,7};
    a.InsertSort();
    a.Print();
    cout << '\n';
    b.QuickSort();
    b.Print();
    cout << '\n';
    c.BubbleSort();
    c.Print();
    cout << '\n';
    d.BubbleSort();
    d.Print();
    cout << '\n';
    e.QuickSort();
    e.Print();

}
