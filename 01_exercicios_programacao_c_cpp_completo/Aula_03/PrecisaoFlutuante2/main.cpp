#include <iostream>
#include <cfloat>

int main(int argc, char* argv[])
{
	float a = 2.34E+8;
	float b = a + 1.0f;

	std::cout << "a = " << a << std::endl;
	std::cout << "b - a = " << b - a << std::endl;

	return 0;
}