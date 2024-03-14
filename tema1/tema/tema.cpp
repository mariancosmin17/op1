#include "NumberList.h"
#include <iostream>

using namespace std;
int main()
{
    NumberList n;
    n.Init();
    n.Add(10);
    n.Add(30);
    n.Add(40);
    n.Add(50);
    n.Add(431);
    n.Add(201);
    n.Add(321);
    n.Add(532);
    n.Print();
    
}
