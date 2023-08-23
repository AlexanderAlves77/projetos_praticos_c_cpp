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
using namespace std;

class Obj
{
public:
	Obj(int val) :mMyInt(val), CONSTANT_MEMBER(val)	{}
	int GetMyValue() const { return mMyInt; }
	void Display() const
	{
		mMyInt = 6;
		std::cout << "mMyInt: " << mMyInt << std::endl;
		std::cout << "CONSTANT_MEMBER: " << CONSTANT_MEMBER << std::endl;

	}
private:
	mutable int mMyInt;
	const int CONSTANT_MEMBER;
};

int main(int argc, const char* argv[])
{


	return 0;
}