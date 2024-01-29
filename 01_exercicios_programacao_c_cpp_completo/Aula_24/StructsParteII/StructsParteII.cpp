#include <iostream>
using namespace std;

struct Pessoa
{
private:
	int idade;
public:
	Pessoa(int idade)
	{
		this->idade = idade;
	}

	void setIdade(int idade)
	{
		this->idade = idade;
	}
	int getIdade()
	{
		return this->idade;
	}
};

int main(int argc, char* argv[])
{
	Pessoa p(46);
	cout << p.getIdade() << endl;

	system("Pause");
	return 0;
}