/**********************************************************************************
* Arquivo    : Home (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 14 Fev 2013
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Tela de abertura do jogo
*
**********************************************************************************/


#ifndef _GRAVITYGUY_HOME_H_
#define _GRAVITYGUY_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    TileSet * tileset = nullptr;    // tileset da anima��o
    Animation * anim = nullptr;     // anima��o do menu

public:
    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif