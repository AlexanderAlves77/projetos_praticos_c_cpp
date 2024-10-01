/**********************************************************************************
* Arquivo    : Plane (Código Fonte)
* Author     : Alexander Alves
* Criação    : 24 Set 2012
* Atualização: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Define uma classe para um avião
*
**********************************************************************************/

#include "Plane.h"

// ---------------------------------------------------------------------------------

Plane::Plane()
{
    // configura sprite
    sprite = new Sprite("Resources/Airplane.png");

    // configura posição do objeto
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
    // converte ângulo em radianos antes de desenhar
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------