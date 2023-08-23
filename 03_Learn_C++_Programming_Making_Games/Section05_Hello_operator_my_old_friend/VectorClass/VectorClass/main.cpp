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

class Vec2D
{
private:
	float mX, mY;

public:
	static const Vec2D Zero;

	Vec2D() : Vec2D(0,0) {}
	Vec2D(float x, float y): mX(x), mY(y) {}

	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }
	inline int GetX() const { return mX; }
	inline int GetY() const { return mY;  }
	void Display() const
	{
		cout << "X: " << mX << " , Y: " << mY << endl;
	}
};

const Vec2D Vec2D::Zero;

int main(int argc, const char* argv[])
{


	cout << endl;
	system("Pause");
	return 0;
}
