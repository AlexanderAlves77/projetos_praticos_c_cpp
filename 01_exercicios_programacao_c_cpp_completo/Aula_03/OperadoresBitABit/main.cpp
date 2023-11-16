#include <iostream>

int main(int argc, char* argv[])
{
	unsigned char estado = 1;
	estado = ~estado;
	std::cout << (int)estado << std::endl;

	return 0;
}