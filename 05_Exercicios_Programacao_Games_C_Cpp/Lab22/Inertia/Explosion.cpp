/**********************************************************************************
* Arquivo    : Explosion (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 07 Fev 2013
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Anima��o de uma explos�o
*
**********************************************************************************/

#include "Explosion.h"
#include "Inertia.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(TileSet * tiles)
{
    anim = new Animation(tiles, 0.020f, false);
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
        Inertia::scene->Delete();    
}

// ---------------------------------------------------------------------------------