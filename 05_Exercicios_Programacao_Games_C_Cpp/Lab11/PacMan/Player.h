/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 01 Jan 2013
* Atualiza��o: 14 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Player do jogo PacMan
*
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERSTATE {STOPED, UP, DOWN, LEFT, RIGHT};    

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite * spriteR = nullptr;         // sprite do player indo para direita
    Sprite * spriteU = nullptr;         // sprite do player indo para cima
    Sprite * spriteD = nullptr;         // sprite do player indo para baixo
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

public:
    uint currState = STOPED;            // estado atual do jogador
    uint nextState = STOPED;            // pr�ximo estado do jogador

    Player();                           // construtor
    ~Player();                          // destrutor

    void Stop();                        // p�ra jogador
    void Up();                          // muda dire��o para cima
    void Down();                        // muda dire��o para baixo
    void Left();                        // muda dire��o para esquerda
    void Right();                       // muda dire��o para direita

    void OnCollision(Object * obj);     // resolu��o da colis�o
    void PivotCollision(Object * obj);  // revolve colis�o com piv�
    
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif