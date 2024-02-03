#include <iostream>
#include <list>
using namespace std;

//template<typename T> T soma(T n1, T n2)
template<class T>
class Fila
{
private:
	list<T> fila:
public:
	void inserir(const T& e)
	{
		fila.push_back(e);
	}
	bool vazia()
	{
		return fila.empty();
	}
	T remover()
	{
		if (!this->vazia()) 
		{
			T e = fila.front();
			fila.pop_front();
			return e;
		}
		throw "Fila vazia!!";
	}
	T frente()
	{
		if (!this->vazia())
			return fila.front();
		throw "Fila vazia!!";
	}
	T final()
	{
		if (!this->vazia())
			return fila.back();
		throw "Fila vazia!!";
	}
	int tamanho()
	{
		return fila.size();
	}
};

int main(int argc, char* argv[])
{
	Fila<double> f1;
	cout << "ANTES de inserir elementos...\n";

	if (f1.vazia())
		cout << "Fila vazia!\n";
	else
		cout << "Fila NAO vazia!\n";
	try
	{
		double e = f1.remover();
		cout << "Removido o elemento: " << e << endl;
	}
	catch (const char* msg)
	{
		cerr << "Erro: " << msg << endl;
	}

	f1.inserir(5.67);
	f1.inserir(9.23);
	f1.inserir(1.45);
	cout << "\nDEPOIS de inserir elementos...\n";

	if (f1.vazia())
		cout << "Fila vazia!\n";
	else
		cout << "Fila NAO vazia!\n";
	try
	{
		cout << "Elemento da frente: " << f1.frente() << endl;
	}
	catch (const char* msg)
	{
		cerr << "Erro: " << msg << endl;
	}

	try
	{
		cout << "Elemento do final: " << f1.final() << endl;
	}
	catch (const char* msg)
	{
		cerr << "Erro: " << msg << endl;
	}

	try
	{
		double e = f1.remover();
		cout << "Removido o elemento: " << e << endl;
	}
	catch (const char* msg)
	{
		cerr << "Erro: " << msg << endl;
	}

	return 0;
}
