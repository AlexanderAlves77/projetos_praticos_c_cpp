#include <iostream>
#include "Pilha.h"
using namespace std;

int main(int argc, char* argv[])
{
	Pilha<int> p(100);
	p.empilhar(10);
	p.empilhar(11);
	p.empilhar(12);
	p.desempilhar();
	if(p.vazia())
		cout << "Pilha vazia!" << endl;
	else 
		cout << "Pilha NAO vazia!" << endl;
	if(p.getTopo() != NULL)
		cout << "Topo: " << p.getTopo() << endl;
	else
		cout << "A pilha está vazia!" << endl;
	return 0;
}
