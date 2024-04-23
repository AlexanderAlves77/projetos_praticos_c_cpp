/**********************************************************************************
* Arquivo    : Ball (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 22 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Bola do jogo Breakout
*
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"            // tipos espec�ficos da engine
#include "Object.h"            // interface de Object
#include "Sprite.h"            // interface de Sprites
#include "Player.h"            // jogador do Breakout

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
	Player * player;
	Sprite * sprite;
	float velX, velY;

public:
	Ball(Player * p);
	~Ball();

	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------

#endif