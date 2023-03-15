#include "Math.h"
#include <stdarg.h>
#include <cstring>



int Math::Add(int x, int y)
{
	return x+y;
}

int Math::Add(int x, int y, int z)
{
	return x+y+z;
}

int Math::Add(double x, double y)
{
	return (double)x+y;
}

int Math::Add(double x, double y, double z)
{
	return (double)x+y+z;
}

int Math::Mul(int x, int y)
{
	return x*y;
}

int Math::Mul(int x, int y, int z)
{
	return x*y*z;
}

int Math::Mul(double x, double y)
{
	return (double)x*y;
}

int Math::Mul(double x, double y, double z)
{
	return (double)x*y*z;
}

int Math::Add(int count, ...)
{
	int sum=0;;
	va_list arg;
	va_start(arg, count);
	for (int i = 0;i < count;i++)
	{
		sum+= va_arg(arg, int);
	}
	va_end(arg);
	return sum;
}

char* Math::Add(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return nullptr;
	char* result = new char[ strlen(str1) + strlen(str2) +1];
	strcpy(result, str1);
	strcat(result, str2);
	return result;
}
