/**********************************************************************************
* Arquivo    : GameOver (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 14 Fev 2013
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Fim do jogo
*
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "GravityGuy.h"
#include "Home.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
    title = new Sprite("Resources/GameOver.png");
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
        GravityGuy::NextLevel<Home>();
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    title->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete title;
}

// ----------------------------------------------------------------------

