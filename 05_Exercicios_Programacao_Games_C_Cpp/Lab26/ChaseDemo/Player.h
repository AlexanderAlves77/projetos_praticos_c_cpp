/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 10 Out 2012
* Atualização: 23 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Define a classe jogador
*
**********************************************************************************/


#ifndef _CHASEDEMO_PLAYER_H_
#define _CHASEDEMO_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                 // objetos do jogo
#include "Sprite.h"                 // desenho de sprites
#include "Vector.h"                 // representação de vetores
#include "Particles.h"              // sistema de partículas
#include "Controller.h"             // entrada pelo controle

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;                // sprite do objeto
    Particles * tail;               // calda do jogador
    Controller * gamepad;           // leitura do controle
    bool gamepadOn;                 // controle está ligado

public:
    Vector * speed;                 // velocidade e direção

    Player();                       // construtor
    ~Player();                      // destrutor
    
    void Move(Vector && v);         // movimenta jogador
    void Update();                  // atualização
    void Draw();                    // desenho
}; 
// ---------------------------------------------------------------------------------

#endif