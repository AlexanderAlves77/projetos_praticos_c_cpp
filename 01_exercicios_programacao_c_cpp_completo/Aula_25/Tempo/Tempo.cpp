// definição da classe Tempo
#include <iostream>
#include "Tempo.h"
using namespace std;

Tempo::Tempo()
{
    horas = 0;
    minutos = 0;
}

Tempo::Tempo(int h, int m)
{
    horas = h;
    minutos = m;
}

void Tempo::Exibir() const
{
    cout << horas << " horas, "
        << minutos << " minutos";
}

Tempo Tempo::operator+(const Tempo& t) const
{
    Tempo soma;
    soma.minutos = minutos + t.minutos;
    soma.horas = horas + t.horas;

    // minutos excedentes viram horas
    soma.horas += soma.minutos / 60;
    soma.minutos %= 60;
    return soma;
}

const Tempo& Tempo::operator+=(const Tempo& t)
{
    horas += t.horas;
    minutos += t.minutos;

    horas += minutos / 60;
    minutos %= 60;

    return *this;
}

const Tempo& Tempo::operator-=(const Tempo& t)
{
    int mins1 = (horas * 60) + minutos;
    int mins2 = (t.horas * 60) + t.minutos;
    int diff = mins1 - mins2;

    horas = diff / 60;
    minutos = diff % 60;
    return *this;
}
