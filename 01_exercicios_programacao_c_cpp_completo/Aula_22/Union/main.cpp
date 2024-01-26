#include <iostream>
using namesapece std;

union identificador
{
	char ch;
	int num;
	double frac;
};

int main(int argc, char * argv[])
{
	identificador id;
	id.ch = 'A';
	cout << sizeof(id) << endl;
	id.num = 46463;
	
	cout << id.num << endl;
	cout << id.ch << endl;
	
	return 0;
}

