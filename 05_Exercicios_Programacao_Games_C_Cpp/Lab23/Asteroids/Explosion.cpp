/**********************************************************************************
* Arquivo    : Explosion (Código Fonte)
* Author     : Alexander Alves
* Criação    : 07 Fev 2013
* Atualização: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Animação de uma explosão
*
**********************************************************************************/

#include "Explosion.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float posX, float posY)
{
    anim = new Animation(Asteroids::exploSet, 0.010f, false);
    MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Explosion::Update()
{
    anim->NextFrame();

    if (anim->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------