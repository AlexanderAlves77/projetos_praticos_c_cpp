#include <iostream>
#include "lista.h"
using namespace std;

int main(int argc, char* argv[])
{
	Lista<string> l;

	l.inserir_final("python");
	l.inserir_final("C++");
	l.inserir_final("javascript");
	l.inserir_final("php");

	l.mostrar();

	if (l.vazia())
		cout << "Lista vazia!!\n";
	else
		cout << "Lista NAO vazia!!\n";

	l.mostrar();
	if (l.existe("C++"))
		cout << "\nO elemento C++ existe na lista!!\n";
	else
		cout << "O elemento C++ NAO existe na lista!!\n";
	
	l.mostrar();

	l.mostrar();
	if (l.existe("Vuejs"))
		cout << "\nO elemento Vuejs existe na lista!!\n";
	else
		cout << "O elemento Vuejs NAO existe na lista!!\n";

	l.remover();
	l.mostrar();

	cout << "Tamanho da lista: " << l.tamanho() << endl;

	return 0;
}
