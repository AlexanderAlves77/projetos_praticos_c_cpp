/**********************************************************************************************
* Name            : Vec2D.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Math for Games in C++
*
**********************************************************************************************/

#include "Vec2D.h"
#include "Utils.h"

ostream& operator<<(ostream& os, const Vec2D& vec)
{
	os << "X: " << vec.mX << ", Y: " << vec.mY << endl;
	return os;
}

bool Vec2D::operator==(const Vec2D& vec2) const
{
	return IsEquals(mX, vec2.mX) && IsEquals(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D& vec2) const
{
	return !(*this == vec2);
}

