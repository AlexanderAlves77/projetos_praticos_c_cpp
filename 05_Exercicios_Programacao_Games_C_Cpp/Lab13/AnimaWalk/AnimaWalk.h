/**********************************************************************************
* Arquivo    : AnimaWalk (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 18 Abr 2012
* Atualiza��o: 16 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Usando a classe Animation para animar um personagem
*
**********************************************************************************/

#ifndef _ANIMAWALK_H_
#define _ANIMAWALK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Lady.h"

// ------------------------------------------------------------------------------

class AnimaWalk : public Game
{
private:
    Sprite * backg = nullptr;       // sprite de fundo
    Lady * lady = nullptr;          // objeto com anima��o    

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif