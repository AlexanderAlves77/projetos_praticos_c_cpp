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
	
	for (unsigned int i = 0; i < vetor.size(); i++) 
		cout << vetor[i] << endl;	
	return 0;
}