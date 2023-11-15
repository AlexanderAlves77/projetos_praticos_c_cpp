#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Desligar qual bit? (Entre 0 e 7): ";
	int bit;
	std::cin >> bit;
	unsigned char mascara = ~(1 << bit);

	unsigned char estado = 252;
	estado = estado & mascara;
	std::cout << int(estado) << std::endl;

	return 0;
}