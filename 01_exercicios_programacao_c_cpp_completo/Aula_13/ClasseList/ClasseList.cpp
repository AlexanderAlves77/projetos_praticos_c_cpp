#include <iostream>
#include <list>
using namespace std;

bool par(const int& n)
{
	return (n % 2 == 0);
}

bool comparar_tamanho(const string& s1, const string& s2)
{
	if (s1.length() < s2.length())
		return true;
	return false;
}

int main(int argc, char* argv[])
{
	list<int> l1;
	list<int> l2(3, 10);
	list<int>::iterator it;

	l1.push_back(10);
	l1.push_front(20);
	l1.push_back(30);

	cout << "Mostrando elementos de l1: \n";
	for (it = l1.begin(); it != l1.end(); it++)
		cout << *it << endl;

	cout << "Mostrando elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// acessando o primeiro e ultimo elemento de l1 - front e back
	cout << "\nPrimeiro elemento de l1: " << l1.front();
	cout << "\nUltimo elemento de l1: " << l1.front() << endl;
	cout << "\nTamanho de l1: " << l1.size() << endl;

	// removendo o primeiro elemento de l1
	l1.pop_front();
	// removendo o ultimo elemento de l1
	l1.pop_back();

	cout << "Mostrando novamente elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// removendo todos os elementos de l2
	while (!l2.empty())
		l2.pop_front();
	cout << "\nNovo Tamanho de l2: " << l2.size() << endl;

	// atribuindo elementos a l2 - função assign
	int vetor[] = { 1,2,3,4,5 };
	l2.assign(vetor, vetor + 5);

	cout << "\nMostrando novos elementos de l2:\n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// inserindo um elemento em l2
	l2.insert(l2.begin(), 100);
	cout << "Mostrando novamente elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	it = l2.begin();
	it++;
	l2.insert(it, 200);
	cout << "Elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// inserindo duas vezes o valor 50 na primeira posição
	l2.insert(l2.begin(), 2, 50);
	cout << "Elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// apagando os dois primeiros numeros
	list<int>::iterator it2 = l2.begin();
	it2++;
	it2++;
	l2.erase(l2.begin(), it2);
	cout << "Elementos de l2: \n";
	for (it = l2.begin(); it != l2.end(); it++)
		cout << *it << endl;

	// remover todos os elementos - função clear
	l2.clear();
	cout << "\nTamanho de l2: " << l2.size() << endl;

	// função splice - transfere um elemento de uma lista para outra
	list<int> lista1(2, 10), lista2(2, 20);
	it = lista1.begin();
	// transfere elementos de lista2 para lista1
	lista1.splice(it, lista2);
	cout << "Elementos de lista1: \n";
	for (it = lista1.begin(); it != lista1.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "\nTamanho de lista2: " << lista2.size() << endl;

	// remove todos os elementos de iguais a um valor - função remove
	lista1.remove(20);
	cout << "\nElementos de lista1 sem o valor 20:\n";
	for (it = lista1.begin(); it != lista1.end(); it++)
		cout << *it << " ";
	cout << endl;

	// função remove_if - remove se ocorrer determinada condição
	int vetor2[] = { 6,8,10,5,20,21 };
	list<int> lista3(vetor2, vetor2 + 6);
	cout << "\nElementos de lista3 antes da remocao:\n";
	for (it = lista3.begin(); it != lista3.end(); it++)
		cout << *it << " ";
	cout << endl;

	// removendo todos os elementos pares da lista3
	lista3.remove_if(par);
	cout << "\nElementos de lista3 depois da remocao:\n";
	for (it = lista3.begin(); it != lista3.end(); it++)
		cout << *it << " ";
	cout << endl;

	int vetor3[] = { 17,60,5,30,50 };
	list<int> lista4(vetor3, vetor3 + 5);
	lista4.sort();
	cout << "\nElementos de lista4 ordenados crescentemente:\n";
	for (it = lista4.begin(); it != lista4.end(); it++)
		cout << *it << " ";
	cout << endl;

	// ordenando strings
	list<string> lista5;
	list<string>::iterator it5;
	lista5.push_back("python");
	lista5.push_back("c++");
	lista5.push_back("javascript");
	lista5.push_back("php");
	lista5.sort();
	cout << "\nElementos de lista5 ordenados:\n";
	for (it5 = lista5.begin(); it5 != lista5.end(); it5++)
		cout << *it5 << endl;

	// ordenando usando algum criterio
	// exemplo: ordenando pelo tamanho da string
	lista5.sort(comparar_tamanho);
	cout << "\nElementos de lista5 ordenados pelo tamanho da string:\n";
	for (it5 = lista5.begin(); it5 != lista5.end(); it5++)
		cout << *it5 << " - tamanho: " << (*it5).length() << endl;

	return 0;
}
