#include "Jogo.h"
#include <iostream>
using namespace std;

// -----------------------------------------------
// Definição da Classe Jogo
// -----------------------------------------------

Jogo::Jogo(const string& titulo, float valor)
{
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = preco;
}