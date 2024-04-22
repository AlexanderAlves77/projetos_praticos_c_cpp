/**********************************************************************************
* Arquivo    : Ball (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 22 Dez 2012
* Atualiza��o: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Bola do jogo Breakout
*
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player * p)
{
	player = p;
	sprite = new Sprite("Resources/Ball.png");
	velX = 0.0f;
	velY = 0.0f;
	MoveTo(player->x + 60, player->y - 13);
}

Ball::~Ball()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
	// Deslocar a bola
	MoveTo(player->x + 50, player->y - 13);
	//Translate(velX * gameTime, velY * gameTime);

	// Mant�m a bola dentro da janela
	if (x < 0)
		velX = -velX;

	if (x + sprite->Width() > window->Width())
		velX = -velX;

	if (y < 0)
		velY = -velY;

	if (y + sprite->Height() > window->Height())
		velY = -velY;
}

void Ball::Draw()
{
	sprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

