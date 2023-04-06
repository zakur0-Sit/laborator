#include <iostream>
using namespace std;

float operator ""_Kelvin(long double temp)
{
    return static_cast<float>(temp) + 273.15f;
}

float operator ""_Fahrenheit(long double temp)
{
    return static_cast<float>(temp *9/5+32);
}

int main() {

    float a = 300.0_Kelvin;

    float b = 120.0_Fahrenheit;


    cout << "300 grade celsius = " << a << " grade kelvin " << endl;
    cout << "120 grade celsius = " << b << " grade fahrenheit " << endl;
    return 0;

}
