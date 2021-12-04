#include "math.h"
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex();
	Complex(double);
	Complex(double, double);
	double Phi() const;
	double R() const;
	double Re() const;
	double Im() const;

	Complex operator- ();
	Complex operator+ (double);
	Complex operator- (double);
	Complex operator* (double);
	Complex operator/ (double);
	Complex operator+ (Complex&);
	Complex operator- (Complex&);
	Complex operator* (Complex&);
	Complex operator/ (Complex&);
	
	explicit operator double()
	{
		return m_r * cos(m_phi);
	}

	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& c);
private:
	double m_r;      //модуль
	double m_phi;	 //аргумент

};

Complex sin(const Complex& c);