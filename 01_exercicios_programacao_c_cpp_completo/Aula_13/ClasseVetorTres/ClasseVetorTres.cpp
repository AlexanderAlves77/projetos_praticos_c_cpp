#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vetor(3);
	vetor[0] = 10;
	vetor[1] = 20;
	vetor[2] = 30;

	vector<int>::iterator it;	
	for(it = vetor.begin(); it != vetor.end(); it++)
		cout << *it << endl;

	vector<int>::reverse_iterator rit;
	int i = 0;
	for (rit = vetor.rbegin(); rit != vetor.rend(); rit++)
		*rit = ++i;
	return 0;
}
