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
	cout << vetor.back() << endl;
	cout << vetor.front() << endl;

	cout << vetor.at(1) << endl;
	vector<int>::iterator it = vetor.begin();
	vetor.insert(it + 2, 40);

	for (unsigned int i = 0; i < vetor.size(); i++)
		cout << vetor[i] << endl;

	vetor.erase(vetor.begin() + 1);
	for (unsigned int i = 0; i < vetor.size(); i++)
		cout << vetor[i] << endl;
	return 0;
}