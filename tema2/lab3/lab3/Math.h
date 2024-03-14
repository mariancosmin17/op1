#pragma once
class Math
{
public:
    static int Add(int x, int y);
    static int Add(int x, int y, int z);
    static int Add(double x, double y);
    static int Add(double x, double y, double z);
    static int Mul(int x, int y);
    static int Mul(int x, int y, int z);
    static int Mul(double x, double y);
    static int Mul(double x, double y, double z);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char* a, const char* b);
};

