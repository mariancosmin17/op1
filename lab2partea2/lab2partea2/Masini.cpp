#include "Masini.h"
#include <iostream>
#include <cstring>
using namespace std;

char* Masini::GetName()
{
    return this->nume;
}
float Masini::GetComb()
{
    return this->l;
}
float Masini::GetKm()
{
    return this->km;
}
void Masini::SetName(char* name)
{
    if (this->nume == 0)
        this->nume = new char[100];
    for (int i = 0; i < strlen(name); i++)
        this->nume[i] = name[i];

    cout << nume << '\n';
}
bool Masini::SetComb(float c)
{
    if (c < 0)
        return 0;
    else {
        this->l = c;
        return 1;
    }
}
bool Masini::SetKm(float k)
{
    if (k < 0)
        return 0;
    else {
        this->km = k;
        return 1;
    }

}
float Masini::GetConsum()
{
    return this->cons;
}
bool Masini::SetConsum(float cs)
{
    if (cs < 0)
        return 0;
    else {
        this->cons = cs;
        return 1;
    }
}
void Masini::bisnitar()
{
    this->km = this->km - 1000;
}
void Masini::cursa(float d)
{
    this->km = this->km - d;
    this->l = this->l - d / this->cons;

}