/**********************************************************************************
* Arquivo    : Explosion (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 07 Fev 2013
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Anima��o de uma explos�o
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