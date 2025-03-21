/**********************************************************************************
* Arquivo    : Vector (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 18 Nov 2011
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Classe para representar um vetor
*
**********************************************************************************/

#include "Vector.h"

// ------------------------------------------------------------------------------

const double Vector::PI = 3.1415926535;

// ------------------------------------------------------------------------------

Vector::Vector()
{
    angle     = 0;
    magnitude = 0;
}

// ------------------------------------------------------------------------------

Vector::Vector(float ang, float mag)
{
    angle     = ang;
    magnitude = mag;
}

// ------------------------------------------------------------------------------

void Vector::Rotate(float theta)
{
    angle -= theta;

    // mant�m o �ngulo entre 0 e 359 graus
    while (angle < 0 || angle >= 360)
        angle += (angle >= 360 ? -360.0f : 360.0f);
}

// ------------------------------------------------------------------------------

void Vector::Scale(float factor)
{
    magnitude *= factor;
}

// ------------------------------------------------------------------------------