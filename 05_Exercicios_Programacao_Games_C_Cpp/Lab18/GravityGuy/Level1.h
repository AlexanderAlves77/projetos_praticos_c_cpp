/**********************************************************************************
* Arquivo    : Level1 (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 14 Fev 2013
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : N�vel 1 do jogo
*
**********************************************************************************/

#ifndef _GRAVITYGUY_LEVEL1_H_
#define _GRAVITYGUY_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado

public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif