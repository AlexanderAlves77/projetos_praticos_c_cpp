#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Testar qual bit? (Entre 0 e 7): ";
	int bit;
	std::cin >> bit;
	unsigned char mascara = 1 << bit;

	unsigned char estado = 240;
	if (estado & mascara)
		std::cout << "ligado" << std::endl;
	else
		std::cout << "desligado" << std::endl;
	
	return 0;
}