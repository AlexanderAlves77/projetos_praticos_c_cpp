/**********************************************************************************
* Arquivo    : Home (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 18 Jan 2013
* Atualiza��o: 14 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Tela de abertura do jogo PacMan
*
**********************************************************************************/


#ifndef _PACMAN_HOME_H_
#define _PACMAN_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif