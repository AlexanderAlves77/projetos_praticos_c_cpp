#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int num = 1;

	while (num < 11)
	{
		if (num % 2 != 0)
		{
			num++;
			continue;
		}
		cout << "Numero: " << num << endl;
		num++;
	}
	system("Pause");
	return 0;
}