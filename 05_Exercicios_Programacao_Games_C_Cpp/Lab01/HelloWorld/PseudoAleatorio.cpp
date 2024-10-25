#include <iostream>
#include <random>
using namespace std;

int main(int argc, char **argv)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 1000);
	list<int> lista;

	for (int i = 0; i < 100; ++i) {
		int num = dist(mt);
		cout << num << " ";
		lista.push_back(num);
	}		
	cout << endl;

	for (auto j : lista) {
		cout << j << " ";
	}
	
	system("Pause");
	return 0;
}