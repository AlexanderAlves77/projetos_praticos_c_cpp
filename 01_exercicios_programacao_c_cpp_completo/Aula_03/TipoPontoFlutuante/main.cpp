#include <iostream>
#include <cfloat>

int main(int argc, char* argv[])
{
	float f = 6.1f;
	std::cout << "f = " << f << std::endl;

	// exibe n�meros com 8 casas depois da v�rgula
	std::cout << std::fixed;
	std::cout.precision(8);

	std::cout << "f = " << f << std::endl;

	return 0;
}