#include "NumberList.h"
#include <iostream>
using namespace std;

void NumberList::Init()
{
    this->count = 0;
}
bool NumberList::Add(int x)
{
    if (this->count >= this->count2)
    {
        int* q = new int[this->count+5];
        for (int i = 0; i < this->count; i++)
            q[i] = p[i];
        delete [] p;
        p = q;
        q = NULL;
        this->count2 = this->count2 + this->count;
    }
    
    this->p[this->count] = x;
    this->count++;

    return true;
}
void NumberList::Sort()
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < this->count - 1; i++)
        {
            if (this->p[i] > this->p[i + 1])
            {
                int aux = this->p[i];
                this->p[i] = this->p[i + 1];
                this->p[i + 1] = aux;
                sorted = false;
            }
        }
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
        printf("%d ", this->p[i]);
    printf("\n");
}