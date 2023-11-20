#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namesapece std;

struct complexo
{
	float real;
	float img;
};

complexo operator+(complexo, complexo);
ostream& operator<<(ostream&, complexo&);
istream& operator>>(istream&, complexo&);

int main(int argc, char * argv[])
{
	cout << "Digite os complexos:\n";
	complexo c1;
	cin >> c1;
	complexo c2;
	cin >> c2;
	complexo resultado = c1 + c2;
	cout << resultado;
	
	return 0;
}

complexo operator+(complexo a, complexo b)
{
	complexo c;
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return c;
}

ostream operator<<(ostream& os, complexo &c)
{
	os << c.real;
	os << showpos;
	os << c.img;
	os << noshowpos;
	os << "i";
	return os;
}

istream& operator>>(istream& is, complexo& temp)
{
	complexo temp;
	cin >> temp.real;
	cin >> temp.img;
	cin.ignore();
	return is;
}
