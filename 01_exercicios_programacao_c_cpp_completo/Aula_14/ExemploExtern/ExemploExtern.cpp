#include <iostream>
#include <string>
using namespace std;

extern int var = 10;

void print_var()
{
	cout << var << endl;
}

int main(int argc, char* argv[])
{
	print_var();
	return 0;
}
