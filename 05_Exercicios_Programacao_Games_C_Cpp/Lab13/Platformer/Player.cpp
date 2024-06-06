/**********************************************************************************
* Arquivo    : Player (Código Fonte)
* Author     : Alexander Alves
* Criação    : 20 Abr 2012
* Atualização: 16 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Define uma classe para o jogador
*
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);    

    uint seqNormal[4] = { 1,2,3,4 };
    uint seqInvert[4] = { 6,7,8,9 };

    anim->Add(INVERTED, seqInvert, 4);
    anim->Add(NORMAL, seqNormal, 4);

    bbox = new Rect(-1.0 * tileset->TileWidth() / 2.0f, 
                    -1.0 * tileset->TileHeight() / 2.0f, 
                    +1.0 * tileset->TileWidth() / 2.0f, 
                    +1.0 * tileset->TileHeight() / 2.0f);

    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
    delete bbox;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mantém personagem na posição correta encima da plataforma
    if (gravity == NORMAL)
        MoveTo(window->CenterX(), obj->Y() - 32);
    else
        MoveTo(window->CenterX(), obj->Y() + 32);
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();

    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);    
}

// ---------------------------------------------------------------------------------