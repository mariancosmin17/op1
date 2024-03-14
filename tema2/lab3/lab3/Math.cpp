#include "Math.h"
#include <cstring>
#include <iostream>
#include <stdarg.h>

using namespace std;


 int Math::Add(int x, int y)
{
	return x + y;
}
 int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
 int Math::Add(double x, double y)
{
	return x + y;
}
 int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
 int Math::Mul(int x, int y)
{
	return x * y;
}
 int Math::Mul(int x, int y, int z)
{
	return x * y* z;
}
 int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y* z;
}
 int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; ++i) {
		sum += va_arg(args, int);
	}

	va_end(args);
	return sum;
}
 char* Math::Add(const char* a, const char* b)
{
	 char* result = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
	 if (result == NULL) {
		 return NULL;
	 }
	 strcpy(result, a);
	 strcat(result, b);
	 return result;

}