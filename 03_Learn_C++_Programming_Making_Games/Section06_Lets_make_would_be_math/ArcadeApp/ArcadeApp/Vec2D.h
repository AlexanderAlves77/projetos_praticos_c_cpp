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
	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }

	friend ostream& operator<<(ostream& os, const Vec2D& vec);

	bool operator==(const Vec2D& vec2) const;
	bool operator!=(const Vec2D& vec2) const;

	Vec2D operator-() const;
	Vec2D operator*(float scale) const;
	Vec2D operator/(float scale) const;
	Vec2D& operator*=(float scale);
	Vec2D& operator/=(float scale);

	Vec2D operator+(const Vec2D& vec) const;
	Vec2D operator-(const Vec2D& vec) const;
	Vec2D& operator+=(const Vec2D& vec);
	Vec2D& operator-=(const Vec2D& vec);

	float Mag2() const;
	float Mag() const;

	Vec2D GetUnitVec() const;
	Vec2D& Normalize();

	float Distance(const Vec2D& vec) const;
	float Dot(const Vec2D& vec) const;

	Vec2D ProjectOnto(const Vec2D& vec) const;

	float AngleBetween(const Vec2D& vec2) const;

	Vec2D Reflect(const Vec2D& normal) const;

	void Rotate(float angle, const Vec2D& aroundPoint);
	Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;

	friend Vec2D operator* (float scalar, const Vec2D& vec2);
};


#endif