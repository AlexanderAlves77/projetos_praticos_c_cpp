#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char * argv[])
{
	sf::RenderWindow renderWindow{ sf::VideoMode(100,100), "MyWindow" };
	cout << "Hello Wrold!" << endl;
	return 0;
}