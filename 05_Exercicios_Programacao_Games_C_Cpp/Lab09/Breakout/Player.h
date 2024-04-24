/**********************************************************************************
* Arquivo    : Player (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 21 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Player do jogo Galaga
*
**********************************************************************************/

#ifndef _BREAKOUT_PLAYER_H_
#define _BREAKOUT_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"          // tipos espec�ficos da engine
#include "Object.h"         // interface de Object
#include "Sprite.h"         // interface de Sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite * sprite;
	float vel;

public:
	Player();
	~Player();

	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------

#endif