/**********************************************************************************
* Arquivo    : AnimaWalk (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 18 Abr 2012
* Atualização: 16 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Usando a classe Animation para animar um personagem
*
**********************************************************************************/

#ifndef _ANIMAWALK_H_
#define _ANIMAWALK_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Lady.h"

// ------------------------------------------------------------------------------

class AnimaWalk : public Game
{
private:
    Sprite * backg = nullptr;       // sprite de fundo
    Lady * lady = nullptr;          // objeto com animação    

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif