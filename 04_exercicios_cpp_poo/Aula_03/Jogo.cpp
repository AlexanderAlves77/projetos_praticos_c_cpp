// definição da classe Jogo
#include <iostream>
#include "Jogo.h"

void Jogo::adquirir(const string& titulo, float valor) 
{
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = preco;
}