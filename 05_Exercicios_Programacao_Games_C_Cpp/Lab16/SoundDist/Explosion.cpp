/**********************************************************************************
* Arquivo    : Explosion (Código Fonte)
* Author     : Alexander Alves
* Criação    : 07 Fev 2013
* Atualização: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Animação de uma explosão
*
**********************************************************************************/

#include "SoundDist.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(TileSet * tiles)
{
    anim = new Animation(tiles, 0.015f, false);
    //BBox(new Circle(12.0f));
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
        SoundDist::scene->Delete();    
}

// ---------------------------------------------------------------------------------