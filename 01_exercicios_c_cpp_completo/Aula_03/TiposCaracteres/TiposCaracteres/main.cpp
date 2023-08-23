#include <iostream>

int main(int argc, char* argv[])
{
	char ch = 'M';
	char alarme = '\a';   // caracter beep
	int senha;

	std::cout << "Digite a senha: ________\b\b\b\b\b\b\b\b";
	std::cin >> senha;

	std::cout << alarme << "Sua senha foi roubada!\a\n";
	std::cout << "Joãozinho \"O Hacker\"\nesteve aqui!\n";

	return 0;
}