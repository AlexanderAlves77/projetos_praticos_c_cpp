#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vetor;
	vetor.push_back(20);
	vetor.push_back(30);
	vetor.push_back(40);

	int tam = vetor.size();
	for (int i = 0; i < tam; i++) {
		cout << vetor[i] << endl;
	}
	return 0;
}