/*=================================================================================
*  Arquivo     : Utils.cpp
*  Author      : Alexander Alves
*  Criação     : 13 Set 2023
*  Compilador  : Visual C++ 2019
*  Atualização : 13 Set 2023
*
*  Descrição:   Hello World in C++, Ansi-style
===================================================================================*/

#include "Utils.h"
#include <cmath>

bool IsEqual(float x, float y)
{
	return fabsf(x - y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}
