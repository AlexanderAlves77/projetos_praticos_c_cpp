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
public:
	B() :B(0, 0.0f) {}

	/*	Overwrote copy constuctor */
	B(const B& otherB)
	{
		mInt = 5;        //otherB.mInt;
		mFloat = 9.0f;   //otherB.mFloat;
	}

	B(int intVal, float floatVal) :mInt(intVal), mFloat(floatVal) {}

	void Display()
	{
		std::cout << "Int val: " << mInt << ", Float val: " << mFloat << std::endl;
	}
private:
	int mInt;
	float mFloat;
};

void Func(B b) { b.Display(); }

int main(int argc, const char* argv[])
{
	B b;
	b.Display();
	Func(b);

	return 0;
}