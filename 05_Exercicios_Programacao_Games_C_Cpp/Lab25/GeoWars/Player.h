/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 10 Out 2012
* Atualização: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Define a classe jogador
*
**********************************************************************************/

#ifndef _GEOWARS_PLAYER_H_
#define _GEOWARS_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                        // objetos do jogo
#include "Sprite.h"                        // desenho de sprites
#include "Vector.h"                        // representação de vetores
#include "Particles.h"                     // sistema de partículas

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Particles * tail;                   // calda do jogador

public:
    Vector * speed;                     // velocidade e direção

    Player();                           // construtor
    ~Player();                          // destrutor
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualização
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

#endif