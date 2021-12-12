#include<iostream>
#include "math.h"
#include "Header.h"

using namespace std;

Complex y(Complex& z)
{
	Complex i(0, 1);
	Complex res = (i - sin(z * 2) * z);
	return res;
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	Complex a, res; 
	cout << "¬ведите действительную и мнимую часть комплексного числа" << endl;
	cin >> a;
	res = y(a);
	cout << res;
}

