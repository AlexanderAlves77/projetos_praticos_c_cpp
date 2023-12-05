#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	const double PI = 3.1415;
	int var = 10;
	int *p1, *p2;
	
	p1 = &var;
	p2 = &var;

	if (p1 == p2)
		cout << "p1 contem o mesmo endereco de p2" << endl;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << &var << endl;
	cout << PI << endl;

	system("Pause");
	return 0;
}