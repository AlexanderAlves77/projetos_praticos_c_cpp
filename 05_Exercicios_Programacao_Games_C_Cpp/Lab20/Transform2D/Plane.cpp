/**********************************************************************************
* Arquivo    : Plane (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 24 Set 2012
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define uma classe para um avi�o
*
**********************************************************************************/

#include "Plane.h"

// ---------------------------------------------------------------------------------

Plane::Plane()
{
    // configura sprite
    sprite = new Sprite("Resources/Airplane.png");

    // configura posi��o do objeto
    MoveTo(window->CenterX(), window->CenterY());
}

// ---------------------------------------------------------------------------------

Plane::~Plane()
{
    delete sprite;
}
// -------------------------------------------------------------------------------

void Plane::Update()
{
    
}

// -------------------------------------------------------------------------------

void Plane::Draw()
{
    // converte �ngulo em radianos antes de desenhar
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------