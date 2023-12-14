#include "Tempo.h"

Tempo::Tempo(int h, int m)
{
	horas = h;
	minutos = m;
	cout << "Construindo Tempo (" << horas << "," << minutos << ")\n";
}

Tempo::~Tempo()
{
	cout << "Destruindo Tempo (" << horas << "," << minutos << ")\n";
}
/*
Tempo::operator double()
{
	return horas + minutos / 60.0;
}

Tempo::operator int()
{
	return horas;
}
*/
Tempo operator+(const Tempo& t1, const Tempo& t2)
{
	Tempo soma;
	soma.horas = t1.horas + t2.horas;
	soma.minutos = t1.minutos + t2.minutos;

	// minutos excedentes viram horas
	soma.horas += soma.minutos / 60;
	soma.minutos %= 60;
	return soma;
}

Tempo operator+(const Tempo& t, int h)
{
	Tempo soma;
	soma.horas = h + t.horas;
	soma.minutos = t.minutos;
	return soma;
}

Tempo operator+(int h, const Tempo& t)
{
	return t + h;
}

ostream& operator<<(ostream& os, const Tempo& t)
{
	os << t.horas << " horas, " << t.minutos << " minutos.";
	return os;
}