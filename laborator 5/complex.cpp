#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++()
{
    real_data++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex tmp(*this);
    operator++();
    return tmp;
}

Complex& Complex::operator--()
{
    real_data--;
    return *this;
}

Complex Complex::operator--(int)
{
    
    Complex tmp(*this);
    operator--();
    return tmp;
}

Complex operator+(const Complex& l, const Complex& r)
{
    double a = l.real() + r.real();
    double b = l.imag() + r.imag();
    return Complex(a,b);
}

Complex operator+(const Complex& l, double r) 
{   
    Complex(0, r);
    double a = l.real() + r;
    double b = l.imag();
    return Complex(a,b);
}

Complex operator+(double l, const Complex& r)
{
    Complex(l, 0);
    double a = l + r.real();
    double b = r.imag();
    return Complex(a,b);
}

Complex operator-(const Complex& l, const Complex& r)
{
    double a = l.real() - r.real();
    double b = l.imag() - r.imag();
    return Complex(a, b);
}

Complex operator-(const Complex& l, double r)
{
    double a = l.real() - r;
    double b = l.imag();
    return Complex(a, b);
}

Complex operator-(double l, const Complex& r)
{
    double a = l - r.real();
    double b = r.imag();
    return Complex(a, b);
}

Complex operator*(const Complex& l, const Complex& r)
{
    double a = l.real() * r.real() - l.imag() * r.imag();
    double b = l.real() * r.imag() + l.imag() * r.real();
    return Complex(a, b);
}

Complex operator*(const Complex& l, double r)
{
    double a = l.real() * r;
    double b = l.imag();
    return Complex(a, b);
}

Complex operator*(double l, const Complex& r)
{
    double a = l * r.real();
    double b = r.imag();
    return Complex(a, b);
}

Complex operator-(const Complex& obj)
{
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == r.imag())
        return true;
    return false;
}

bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() != r.real() || l.imag() != r.imag())
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if(complex.is_real()) 
    {
        out << complex.real();
    }
    else 
    {
     out << complex.real() << (complex.imag() < 0 ? "" : "+") << complex.imag() << "i";
    }
    return out;
}
