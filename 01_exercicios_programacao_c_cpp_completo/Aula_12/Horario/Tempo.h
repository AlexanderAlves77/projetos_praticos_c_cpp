// Classe Tempo

#ifndef _TEMPO_H_
#define _TEMPO_H_
#include <iostream>
using namespace std;

class Tempo
{
private:
	int horas;
	int minutos;

public:
	Tempo(int h = 0, int m = 0);
	~Tempo();
	/*
	operator double();
	operator int();
	*/
	Tempo operator+(const Tempo& t) const;
	friend Tempo operator+(const Tempo& t1, const Tempo& t2);
	friend Tempo operator+(const Tempo& t, int h);
	friend Tempo operator+(int h, const Tempo& t);
	friend ostream& operator<<(ostream& os, const Tempo& t);
};

#endif

