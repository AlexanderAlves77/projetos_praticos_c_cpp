/**********************************************************************************
* Arquivo    : Pop (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 29 Jun 2019
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Estouro do Bal�o
*
**********************************************************************************/

#include "Pop.h"
#include "Balloons.h"

// ---------------------------------------------------------------------------------

Pop::Pop(TileSet* tiles, Color tint) : color(tint)
{
    anim = new Animation(tiles, 0.030f, false);
}

// ---------------------------------------------------------------------------------

Pop::~Pop()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Pop::Update()
{
    anim->NextFrame();
    if (anim->Inactive())
        Balloons::scene->Delete();    
}

// ---------------------------------------------------------------------------------