/**********************************************************************************
* Arquivo    : GameOver (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 14 Fev 2013
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Fim do jogo
*
**********************************************************************************/

#ifndef _GRAVITYGUY_GAMEOVER_H_
#define _GRAVITYGUY_GAMEOVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
    Sprite * title = nullptr;       // tela de fim

public:
    void Init();                    // inicializa��o do n�vel
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif