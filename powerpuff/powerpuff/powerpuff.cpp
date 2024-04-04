#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class PowerPuffGirl
{public:
    float damage;
    float health;
    const char* nume;
    virtual const char* GetNume()=0;
    virtual void SetNume(const char * nume)=0;

};
class Bubbles :public PowerPuffGirl
{public:
    Bubbles() {
        damage = 35;
        health = 150;
        nume = "Bubbles";
    }
    const char* GetNume()
    {
        return this->nume;
    }
    void SetNume(const char* nume)
    {
        this->nume = nume;
    }
};
class Blossom :public PowerPuffGirl
{
public:
    Blossom() {
        damage = 70;
        health = 70;
        nume = "Blossom";
    }
    const char* GetNume()
    {
        return this->nume;
    }
    void SetNume(const char* nume)
    {
        this->nume = nume;
    }
};
class ButterCup :public PowerPuffGirl
{
public:
    ButterCup() {
        damage = 50;
        health = 100;
        nume = "ButterCup";
    }
    const char* GetNume()
    {
        return this->nume;
    }
    void SetNume(const char* nume)
    {
        this->nume = nume;
    }
};
class MojoJojo :public PowerPuffGirl
{
public:
    MojoJojo()
    {
        damage = 1000;
        health = 10000;
        nume = "MojoJojo";
    }
    const char* GetNume()
    {
        return this->nume;
    }
    void SetNume(const char* nume)
    {
        this->nume = nume;
    }
};
class Profesor
{
    MojoJojo j;
    PowerPuffGirl** girl;
    int nr;
    int sugar;
    int spice;
    int en;
    int ture;
    int jojo;
    int death;
public:
    Profesor()
    {
        death = 0;
        jojo = 1;
        ture = 0;
        sugar = 0;
        en = 0;
        spice = 0;
        nr = 0;
        girl = new PowerPuffGirl*[100];
    }
    void GetIngredients(int s, int sp, int en)
    {
        this->sugar = s;
        this->spice = sp;
        this->en = en;
    }
    void Creare()
    {
        srand(time(nullptr));
        while (this->sugar >= 1 && this->spice >= 1 && this->en >= 1)
        {
            int sansa = rand() % 3;
            if (sansa % 3 == 1)
                girl[this->nr ++] = new ButterCup();
            if (sansa % 3 == 2)
                girl[this->nr++] = new Blossom();
            if (sansa % 3 == 0)
                girl[this->nr++] = new Bubbles();
            this->sugar--;
            this->spice--;
            this->en--;   
        }
        
    }
    void Afis()
    {
        for(int i = 0; i < this->nr; i++)
            cout << girl[i]->GetNume()<<" ";
    }
    void Lupta()
    {
        
        srand(time(nullptr));
        int damagetot = 0;
        for (int i = 0; i <this->nr; i++)
            damagetot = damagetot + girl[i]->damage;
        while (this->nr > 0)
        {
            int sansa = rand() % this->nr;
            j.health = j.health - damagetot;
            if (j.health < 0)
            {
                 jojo = 0;
                break;
            }
            girl[sansa]->health = girl[sansa]->health - j.damage;
            if (girl[sansa]->health < 0)
            {
                death++;
                for (int i=sansa;i<this->nr; i++)
                    girl[i] = girl[i + 1];
                this->nr--;
            }
       }
        
    }
    void Stats()
    {
        if (jojo == 0)
            cout << "Fetitele au castigat " << '\n';
        else cout << "MojoJojo a castigat" << '\n';
        cout <<"nr ture "<< this->ture << '\n' <<"cate au murit " << this->death<<" " << '\n';
    }
    int Survive()
    {
        if (this->nr == 0)
        {
            cout << "Nu a supravietuit nicio fetita " << '\n';
            return 0; 
        }
        cout << "cate au supravietuit "<<this->nr << '\n';
        for (int i = 0; i < this->nr; i++)
            cout <<"viata "<< girl[i]->health<<'\n';
        return 1;
    }

};
int main()
{
    Profesor p;
    p.GetIngredients(4, 5, 7);
    p.Creare();
    p.Lupta();
    p.Stats();
    p.Survive();
    
}

