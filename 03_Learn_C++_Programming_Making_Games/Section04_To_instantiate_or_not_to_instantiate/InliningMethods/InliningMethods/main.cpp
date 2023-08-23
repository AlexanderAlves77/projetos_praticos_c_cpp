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
	Obj(int val) :mVal(val)	{}
	inline int GetVal() const { return mVal; }

private:
	int mVal;
};

int main(int argc, const char* argv[])
{


	return 0;
}