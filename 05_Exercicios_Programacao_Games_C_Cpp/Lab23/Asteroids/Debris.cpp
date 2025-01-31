/**********************************************************************************
* Arquivo    : Debris (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 07 Fev 2013
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Anima��o de explos�o
*
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    anim = new Animation(Asteroids::debriSet, 0.060f, false);
    MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
    anim->NextFrame();

    if (anim->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------