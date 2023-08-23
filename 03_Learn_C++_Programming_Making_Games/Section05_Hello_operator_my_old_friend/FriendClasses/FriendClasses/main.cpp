/**********************************************************************************************
* Name            : ArcadeApp.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Operators in C++
*
**********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class A
{
private:
	float mVal;

	friend class B;
};

class B
{
public:
	B() {}
	void DoSomethingWithA(A& a)
	{
		a.mVal = 5;
		cout << a.mVal << endl;
	}
};

int main(int argc, const char* argv[])
{
	A a;
	B b;

	b.DoSomethingWithA(a);

	cout << endl;
	system("Pause");
	return 0;
}

