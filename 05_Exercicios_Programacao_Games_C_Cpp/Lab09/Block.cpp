/**********************************************************************************
* Arquivo    : Block (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 22 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Bloco do jogo Breakout
*
**********************************************************************************/

#include "Block.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Block::Block(Image * img)
{
    sprite  = new Sprite(img);
    velX = 0.0f;
    velY = 0.0f;
}

// ---------------------------------------------------------------------------------

Block::~Block()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Block::Update()
{
    // desloca bloco
    Translate(velX * gameTime, velY * gameTime);

    // tamanho do bloco � 60x24
    if (y > window->Height())
        Breakout::scene->Remove();
}

// ---------------------------------------------------------------------------------
