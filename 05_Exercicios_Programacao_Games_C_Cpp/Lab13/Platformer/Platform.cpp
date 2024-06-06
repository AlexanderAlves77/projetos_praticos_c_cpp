/**********************************************************************************
* Arquivo    : Platform (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 21 Abr 2012
* Atualiza��o: 16 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Plataformas do jogo
*
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
    platform = new Sprite("Resources/LongGray.png");

    bbox = new Rect(-1.0 * platform->Width() / 2.0f,
        -1.0 * platform->Height() / 2.0f,
        +1.0 * platform->Width() / 2.0f,
        +1.0 * platform->Height() / 2.0f);

    MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
