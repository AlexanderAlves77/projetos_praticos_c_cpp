/**********************************************************************************************
* Name            : Utils.cpp
* Author          : Alexander Alves
* Date            : 08/23/2023
* Version         : 0.0.1
* Copyright       :
* Update          : 08/23/2023
* Description     : Math for Games in C++
*
**********************************************************************************************/

#include "Utils.h"
#include <cmath>

static const float EPSILON = 0.0001f;

bool IsEquals(float x, float y)
{
	return fabsf(x - y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y)
{
	return x > y || IsEquals(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
	return x < y || IsEquals(x, y);
}