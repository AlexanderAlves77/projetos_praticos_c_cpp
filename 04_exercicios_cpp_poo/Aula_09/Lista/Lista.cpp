#include "Lista.h"
#include <iostream>
using std::cout;

Lista::Lista(int tam)
{
	itens = new Item[tam];
	size = 0;
	max = tam;
}

Lista::~Lista()
{
	delete[] itens;
}

bool Lista::Vazia() const
{
	return size == 0;
}

