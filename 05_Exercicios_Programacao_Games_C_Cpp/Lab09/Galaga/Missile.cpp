/**********************************************************************************
* Arquivo    : Missile (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 21 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : M�sseis do jogo Galaga
*
**********************************************************************************/

#include "Missile.h"
#include "Galaga.h"

// ---------------------------------------------------------------------------------

Missile::Missile(Image * img)
{
    sprite = new Sprite(img);
    vel    = 250;
}

// ---------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Missile::Update()
{
    // m�ssil se move apenas no eixo y
    Translate(0, -vel * gameTime);

    // remove m�sseis que saem da janela
    if (y < 0)
        Galaga::scene->Remove();
}

// ---------------------------------------------------------------------------------
