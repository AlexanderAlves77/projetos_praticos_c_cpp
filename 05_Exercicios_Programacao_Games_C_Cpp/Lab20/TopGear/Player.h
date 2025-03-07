/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 12 Jul 2019
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : O carro do jogador
*
**********************************************************************************/

#ifndef _TOPGEAR_PLAYER_H_
#define _TOPGEAR_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"              // objetos do jogo
#include "TileSet.h"             // folha de sprites
#include "Animation.h"           // anima��o de sprites
#include "Types.h"               // tipos espec�ficos do motor
#include "Font.h"                // desenho de texto 
#include <sstream>
using std::stringstream;

// ---------------------------------------------------------------------------------

enum Direction { STRAIGHT, LEFT, RIGHT };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet * carSet;           // folha de sprites do carro
    Animation * carAni;         // anima��o do carro
    Font * speedFont;           // fonte para exibir a velocidade
    float & speed;              // velocidade do carro
    stringstream text;          // exibi��o de texto

public:
    Player();                   // construtor
    ~Player();                  // destrutor

    void Update();              // atualiza estado do objeto
    void Draw();                // desenha objeto
}; 

// ---------------------------------------------------------------------------------

#endif