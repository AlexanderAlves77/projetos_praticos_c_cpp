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

bool Pilha::Cheia() const
{
	return topo == MAX;
}

bool Pilha::Empilhar(const Item& item)
{
	if (topo < MAX)
	{
		itens[topo++] = item;
		return true;
	}

	return false;
}

