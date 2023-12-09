#include <iostream>
#include "Pilha.h"
using namespace std;

template <class Type>
Pilha<Type>::Pilha(int tam)
{
	vet = new Type[tam];
	max_tam = tam - 1;
	topo = -1;
}

template <class Type>
Pilha<Type>::~Pilha()
{
	delete[] vet;
}

template <class Type>
void Pilha<Type>::empilhar(Type e)
{
	if (topo == max_tam)
		cout << "Pilha cheia!" << endl;
	else
		vet[++topo] = e;
}

template <class Type>
void Pilha<Type>::desempilhar()
{
	if (topo == -1)
		cout << "Pilha vazia!" << endl;
	else
		topo--;
}

template <class Type>
Type Pilha<Type>::getTopo()
{
	if (topo != -1)
		return vet[topo];
	return NULL;
}

template <class Type>
int Pilha<Type>::vazia()
{
	return (topo == -1);
}



