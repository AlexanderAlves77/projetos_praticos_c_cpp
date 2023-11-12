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
