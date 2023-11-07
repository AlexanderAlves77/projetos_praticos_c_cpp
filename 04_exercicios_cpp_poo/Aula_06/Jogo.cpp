#include "Jogo.h"
#include <iostream>
using namespace std;

// -----------------------------------------------
// Definição da Classe Jogo
// -----------------------------------------------

Jogo::Jogo()
{
    cout << "Construindo objeto Padrao\n";
    nome = "";
    preco = custo = 0.0f;
    horas = 0;
}

Jogo::Jogo(const string& titulo, float valor)
{
    cout << "Construindo objeto " << titulo << "\n";
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = preco;
}