#include <iostream>
using namespace std;
template<class T1>

void bubble(int n, T1 v[])
{
    T1 aux;
    for (int i = 2; i < n; i++) //i trebuie sa inceapa de la 0
    {
        for (int j = i+1; j < n; j++)
        {
            if (v[i] < v[j]) // trebuie mai > in loc de <
            {
                aux = v[j];//trebuie v[i] in loc de v[j]
                v[i] = v[j];
                v[j] = aux //lipseste ;
            }
        }
    }
}
int main()
{
    int v[100], n;
    cin >> n;
    n++;//nu are ce cauta acest n++ aici
    for (int i = 0; i < n; i++)
        cin >> v[i];
    bubble(n, v);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
}