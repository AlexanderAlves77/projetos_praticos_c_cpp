#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vetor;
	
	if (vetor.empty())
		cout << "Vetor vazio!\n";
	else
		cout << "Vetor NAO vazio!\n";

	vetor.push_back(10);
	vetor.push_back(20);
	vetor.push_back(30);

	if (vetor.empty())
		cout << "Vetor vazio!\n";
	else
		cout << "Vetor NAO vazio!\n";

	while (!vetor.empty())
		vetor.pop_back();

	if (vetor.empty())
		cout << "Vetor vazio!\n";
	else
		cout << "Vetor NAO vazio!\n";

	return 0;
}