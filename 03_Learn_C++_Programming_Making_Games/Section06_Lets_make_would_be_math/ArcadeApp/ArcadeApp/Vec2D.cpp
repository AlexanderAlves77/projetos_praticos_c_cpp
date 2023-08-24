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
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

ostream& operator<<(ostream& os, const Vec2D& vec)
{
	os << "X: " << vec.mX << ", Y: " << vec.mY << endl;
	return os;
}

Vec2D operator* (float scalar, const Vec2D& vec)
{
	return vec * scalar;
}

bool Vec2D::operator==(const Vec2D& vec2) const
{
	return IsEquals(mX, vec2.mX) && IsEquals(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D& vec2) const
{
	return !(*this == vec2);
}

Vec2D Vec2D::operator-() const
{
	return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator*(float scale) const
{
	return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);

	return Vec2D(mX / scale, mY / scale);
}

Vec2D& Vec2D::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2D& Vec2D::operator/=(float scale)
{
	assert(fabsf(scale) > EPSILON);
	*this = *this / scale;
	return *this;
}

Vec2D Vec2D::operator+(const Vec2D& vec) const
{
	return Vec2D(mX + vec.mX, mY + vec.mY);
}

Vec2D Vec2D::operator-(const Vec2D& vec) const
{
	return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
	*this = *this + vec;
	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
	*this = *this - vec;
	return *this;
}

float Vec2D::Mag2() const
{
	return Dot(*this);
}

float Vec2D::Mag() const
{
	return sqrt(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
	float mag = Mag();
	if (mag > EPSILON)
		return *this / mag;
	return Vec2D::Zero;
}

Vec2D& Vec2D::Normalize()
{
	float mag = Mag();
	if (mag > EPSILON)
		*this /= mag;
	return *this;
}

float Vec2D::Distance(const Vec2D& vec) const
{
	return (vec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& vec) const
{
	return mX * vec.mX + mY * vec.mY;
}

Vec2D Vec2D::ProjectOnto(const Vec2D& vec2) const
{
	Vec2D unitVec2 = vec2.GetUnitVec();
	float dot = Dot(unitVec2);
	return unitVec2 * dot;
}

float Vec2D::AngleBetween(const Vec2D& vec2) const
{
	return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));
}

Vec2D Vec2D::Reflect(const Vec2D& normal) const
{
	// v - 2(v dot n)n
	return *this - 2 * ProjectOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);
	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);
	*this = rot + aroundPoint;
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);
	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);
	return rot + aroundPoint;
}