/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 07 Fev 2013
* Atualização: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Player usado em SoundDistance
*
**********************************************************************************/

#ifndef _PLATFORMER_PLAYER_H_
#define _PLATFORMER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum Gravity {NORMAL,INVERTED};         // tipo da gravidade

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // animação do personagem
    uint      gravity;                  // gravidade atuando sobre o jogador
    bool      keyCtrl;                  // controle do pressionamento da barra de espaço
    float     freq;                     // frequência da música

public:
    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif