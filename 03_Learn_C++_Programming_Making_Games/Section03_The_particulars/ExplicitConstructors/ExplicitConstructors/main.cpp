#include <iostream>
#include <string>
using namespace std;

class String
{
private:
	string mStr;

public:
	explicit String(int n);
	String(const char* p);
	void Display();
};

String::String(int n)
{
	for (int i = 0; i < n; ++i)
		mStr += '0';
}

String::String(const char* p) : mStr(p) {}

void String::Display()
{
	cout << mStr << endl;
}

int main(int argc, const char* argv[])
{
	String myString = String(10);
	myString.Display();

	cout << endl;
	system("Pause");
	return 0;
}