/**********************************************************************************
* Arquivo    : Block (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 22 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Bloco do jogo Breakout
*
**********************************************************************************/

#ifndef _BREAKOUT_BLOCK_H_
#define _BREAKOUT_BLOCK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

// ---------------------------------------------------------------------------------

class Block : public Object
{
private:
    Sprite * sprite;            // sprite do player
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical

public:
    Block(Image * img);
    ~Block();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Block::Draw()
{ sprite->Draw(x,y,z); }

// ---------------------------------------------------------------------------------

#endif