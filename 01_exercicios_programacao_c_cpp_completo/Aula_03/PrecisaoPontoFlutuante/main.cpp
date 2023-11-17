#include <iostream>
#include <cfloat>

int main(int argc, char* argv[])
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	float fltvar = 10.0 / 3.0;
	double dblvar = 10.0 / 3.0;
	float milhao = 1.0e6;

	std::cout << "float var = " << fltvar;
	std::cout << ", vezes um milhao = " << milhao * fltvar << std::endl;
	std::cout << "double var = " << dblvar;
	std::cout << ", vezes um milhao = " << milhao * dblvar << std::endl;

	return 0;
}