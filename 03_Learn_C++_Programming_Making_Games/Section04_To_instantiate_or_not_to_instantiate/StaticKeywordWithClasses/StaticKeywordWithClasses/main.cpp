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
#include<vector>
using namespace std;

class B
{
private:
	int mMyInt;

public:
	static int sB;

	B() :mMyInt(0) { std::cout << "Constructor called" << std::endl; }
	~B() { std::cout << "Destructor called" << std::endl; }

	static void PrintStaticMsg()
	{
		std::cout << "static method called" << std::endl;
	}
};

int B::sB = 10;

int main(int argc, const char* argv[])
{
	static B myB;
	std::cout << "End of main" << std::endl;

	B::PrintStaticMsg();
	//B myBObj;
	//std::cout << "sB: " << myBObj.sB << std::endl;
	//std::cout << "sB: " << B::sB << std::endl;

	return 0;
}