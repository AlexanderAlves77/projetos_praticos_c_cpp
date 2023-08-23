/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Instantiate or not to instantiate Class in C++
*
**********************************************************************************************/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class B
{
public:
	B(int value) :mValue(value)	{}
	int Value()	{ return mValue; }
	void SetValue(int value) {	mValue = value;	}

private:
	int mValue;
};

class A
{
public:
	A() :mB(0){};
	~A(){};
	void SetValue(int value) { mB.SetValue(value); }
	void Display() { std::cout << "A's value is: " << mB.Value() << std::endl; }

private:
	B mB;
};

int main(int argc, const char argv[])
{
	vector<B> myBVec;

	cout << endl;
	system("Pause");
	return 0;
}
