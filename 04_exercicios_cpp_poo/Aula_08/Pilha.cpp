#include "Pilha.h"

// -----------------------------------------------
// Definição da Classe Pilha
// -----------------------------------------------

Pilha::Pilha()
{
	topo = 0;
}

bool Pilha::Vazia() const
{
	return topo == 0;
}

