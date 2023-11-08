#include "Jogo.h"
#include <iostream>
using namespace std;

// -----------------------------------------------
// Definição da Classe Jogo
// -----------------------------------------------

Jogo::Jogo()
{
    nome = "";
    preco = custo = 0.0f;
    horas = 0;
}

Jogo::Jogo(const string& titulo, float valor, int tempo)
{
    nome = titulo;
    preco = valor;
    horas = tempo;
    custo = valor;
    calcular();
}

Jogo::~Jogo()
{
}

const Jogo& Jogo::comparar(const Jogo& jogo) const
{
    if (jogo.horas > horas)
        return jogo;
    else
        return *this;
}