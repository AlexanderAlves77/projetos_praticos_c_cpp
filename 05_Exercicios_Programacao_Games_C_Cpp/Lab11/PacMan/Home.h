/**********************************************************************************
* Arquivo    : Home (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 18 Jan 2013
* Atualização: 14 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Tela de abertura do jogo PacMan
*
**********************************************************************************/


#ifndef _PACMAN_HOME_H_
#define _PACMAN_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif