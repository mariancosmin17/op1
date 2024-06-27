class Masini
{
    char* nume = 0;
    float km;
    float l;
    float cons;
public:
    void SetName(char* name);
    char* GetName();
    bool SetComb(float c);
    float GetComb();
    bool SetKm(float k);
    float GetKm();
    float GetConsum();
    bool SetConsum(float cs);
    void bisnitar();
    void cursa(float d);
};