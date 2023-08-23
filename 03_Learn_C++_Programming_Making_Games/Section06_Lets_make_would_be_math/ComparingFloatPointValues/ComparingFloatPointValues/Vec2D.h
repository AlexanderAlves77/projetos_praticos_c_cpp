/**********************************************************************************************
* Name            : Vec2D.h
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Math for Games in C++
*
**********************************************************************************************/

#ifndef _VEC2D_H_
#define _VEC2D_H_

#include <iostream>
#include <string>
using namespace std;

class Vec2D
{
private:
	float mX, mY;

public:
	static const Vec2D Zero;

	Vec2D() : Vec2D(0, 0) {}
	Vec2D(float x, float y) : mX(x), mY(y) {}

	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }
	inline int GetX() const { return mX; }
	inline int GetY() const { return mY; }

	friend ostream& operator<<(ostream& os, const Vec2D& vec);

	bool operator==(const Vec2D& vec2) const;
	bool operator!=(const Vec2D& vec2) const;
};


#endif