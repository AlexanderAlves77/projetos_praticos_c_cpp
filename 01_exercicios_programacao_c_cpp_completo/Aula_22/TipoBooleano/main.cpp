#include <iostream>

int main(int argc, char* argv[])
{
	bool buzinar = false;

	std::cout << "Buzinar? ";
	std::cin >> buzinar;

	if (buzinar == true)
		std::cout << "Buzina\a\a\a\a\a\n";
	else
		std::cout << "Silêncio" << std::endl;

	return 0;
}