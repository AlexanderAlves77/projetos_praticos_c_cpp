#include <iostream>
#include <string>
using namespace std;

void showMessage(const char* str)
{
	cout << str << endl;
}

int main(int argc, char* argv[])
{
	//char str[] = "alexander alves";
	string str = "alexander";
	cout << "String: " << str << endl;
	cout << "Tamanho: " << str.size() << endl;
	cout << "Tamanho: " << str.length() << endl;
	cout << "Posicao (1): " << str.at(1) << endl;
	cout << "Primeira Posicao: " << str.front() << endl;
	cout << "Ultima Posicao: " << str.back() << endl;
	cout << "Concatenar: " << str.append(" alves") << endl;
	cout << "Inserir: " << str.insert(0, "alves") << endl;
	cout << "Apagar caracteres: " << str.erase(0, str.size()) << endl;
	cout << "Apagar Strings: " << str.clear() << endl;
	if(str.empty())
		cout << "String vazia!!" << endl;
	else
		cout << "String NAO vazia!!" << endl;
	showMessage(str.c_str());
	cout << "Alterar: " << str.replace(0, 9, "alves") << endl;
	//cout << "Adicionar: " << str.push_back('x') << endl;
	size_t achou = str.find("alves");
	if (achou != string::npos)
		cout << "Achou a substring!!" << endl;
	else
		cout << "Substring nao encontrada" << endl;

	//string my_str;
	//cout << "Digite seu nome: ";
	//getline(cin, my_str);
	//cout << "Nome digitado: " << my_str << endl;
	str += " alves";
	cout << "Nome completo: " << str << endl;
	return 0;
}
