#include "Header.h"
#include "math.h"
#include<iostream>

//Конструктор по умолчанию
Complex::Complex():
	m_r{ sqrt(0)}, m_phi{ atan2(0, 0) }
{}
//Конструктор преобразования
Complex::Complex(double re):
	m_r{ sqrt(re * re) }, m_phi{ atan2(0, 0) }
{} 
//Конструктор инициализации

Complex::Complex(double re, double im) :
	m_r{ sqrt(re * re + im * im) }, m_phi{ atan2(im, re) }
{}

//Публичные функции-члены
double Complex::Re() const
{
	return m_r * cos(m_phi);
}
double Complex::Im() const
{
	return m_r * sin(m_phi);
}
double Complex::R() const
{
	return m_r;
}
double Complex::Phi() const
{
	return m_phi;
}

Complex Complex::operator- ()
{
	return Complex(-Re(), -Im());
}
Complex& Complex::operator+=(const Complex& right)
{
	*this = Complex(Re() + right.Re(), Im() + right.Im());
	return *this;
}
Complex& Complex::operator-=(const Complex& right)
{
	*this = Complex(Re() - right.Re(), Im() - right.Im());
	return *this;
}
Complex& Complex::operator*=(const Complex& right)
{
	*this = Complex(Re() * right.Re(), Im() * right.Im());
	return *this;
}
Complex& Complex::operator/=(const Complex& right)
{
	*this = Complex(Re() / right.Re(), Im() / right.Im());
	return *this;
}
Complex Complex::operator+ (const Complex& right)

{
	Complex res = *this;
	return res += right;
}
Complex Complex::operator- (const Complex& right)
{
	Complex res = *this;
	return res -= right;
}
Complex Complex::operator* (const Complex& right)
{
	Complex res = *this;
	return res *= right;
}
Complex Complex:: operator/ (const Complex& right)
{
	Complex res = *this;
	return res /= right;
}

//Перегрузка операторов вывода
ostream& operator<<(ostream& out, const Complex& c) 
{
	out << "(" << c.Re() << ", " << c.Im() << ")";
	return out;
}
istream& operator>>(istream& in, Complex& c)
{
	double re, im;
	in >> re >> im;
	c.m_r = sqrt(re * re + im * im);
	c.m_phi = atan2(im, re);
	return in;
}

//Перегрузка тригонометрической функции
Complex sin(const Complex& c)
{
	return Complex(sin(c.Re()) * cosh(c.Im()), cos(c.Re()) * sinh(c.Im()));
}
