#include <stdarg.h>
#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	int a = 1, b = 2, c = 3;
	double d = 1.2, e = 2.3, f = 3.4;
	Math mate;
	cout << mate.Add(a, b) << endl;
	cout << mate.Add(a, b, c) << endl;
	cout << mate.Add(d, e) << endl;
	cout << mate.Add(d, e, f) << endl;
	cout << mate.Mul(a, b) << endl;
	cout << mate.Mul(a, b, c) << endl;
	cout << mate.Mul(d, e) << endl;
	cout << mate.Mul(d, e, f) << endl;
	cout << mate.Add(5, 1, 2, 3, 4, 5) << endl;
	cout << mate.Add("Ion", " Cool") << endl;
	return 0;
}