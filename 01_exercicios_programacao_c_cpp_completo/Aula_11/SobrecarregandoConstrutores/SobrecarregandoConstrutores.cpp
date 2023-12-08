#include <iostream>
using namespace std;

class Carro
{
public:
	int ano;
	double preco;

	Carro()
	{
		ano = 0;
		preco = 0.0;
	}
	Carro(int ano)
	{
		this->ano = ano;
		this->preco = 0.0;
	}
	Carro(int ano, double preco)
	{
		this->ano = ano;
		this->preco = preco;
	}
};

int main(int argc, char* argv[])
{
	Carro carro;
	Carro carro2(2014);
	Carro carro3(2014, 200000);

	cout << "Ano do carro: " << carro.preco << endl;
	cout << "Ano do carro2: " << carro2.preco << endl;
	cout << "Ano do carro3: " << carro3.preco << endl;

	return 0;
}