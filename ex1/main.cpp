#include<iostream>
#include<cmath>

class Complex
{
public:
    Complex(double re, double im);
    Complex(double re = 0);

    Complex operator+ (const Complex& b) const;
    Complex operator- (const Complex& b) const;
    Complex operator+ () const;
    Complex operator- () const;
    Complex operator* (const Complex& b) const;
    Complex operator/ (const Complex& b) const;

    bool operator== (const Complex& b) const;
    bool operator!= (const Complex& b) const;

    double Re () const;
    double Im () const;

private:
    double re_, im_;
};

std::ostream& operator<< (std::ostream& a, const Complex& b);

Complex operator+ (double a, const Complex& b);
Complex operator- (double a, const Complex& b);
Complex operator* (double a, const Complex& b);
Complex operator/ (double a, const Complex& b);

double abs(const Complex& a);
bool operator== (double a, const Complex& b);
bool operator!= (double a, const Complex& b);

// some implementations. We need others to solve the problem from contest.
std::ostream& operator<< (std::ostream& a, const Complex& b)
{

    a << b.Re();

    if(fabs (b.Im()) > 1e-16)
        a << '+' << b.Im() << 'i';

    return a;
}

Complex Complex::operator+ (const Complex& b) const
{
    return (Complex(re_ + b.Re(), im_ + b.Im()));
}

Complex operator+ (double a, const Complex& b)
{
    return b + a;
}

bool Complex::operator== (const Complex& b) const
{
    return (fabs (re_ - b.Re()) < 1e-16)
         &&(fabs (im_ - b.Im()) < 1e-16);
}

bool operator== (double a, const Complex& b)
{
    return (b == a);
}


int main ()
{
    Complex c (0), d(0, 1);
    std::cout << 5 + d << "\n";
    std::cout << c.Re ();
}
