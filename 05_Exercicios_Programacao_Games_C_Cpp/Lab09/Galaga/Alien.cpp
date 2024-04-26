/**********************************************************************************
* Arquivo    : Alien (Código Fonte)
* Author     : Alexander Alves
* Criação    : 21 Dez 2012
* Atualização: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Alienígena do jogo Galaga
*
**********************************************************************************/

#include "Alien.h"

// ---------------------------------------------------------------------------------

Alien::Alien(string filename)
{
    sprite = new Sprite(filename);
    vel = 80.0f;
}

// ---------------------------------------------------------------------------------

Alien::~Alien()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Alien::Update()
{
    // desloca alien
    x += vel * gameTime;

    // mantêm os alienígenas dentro da janela
    // tamanho das imagens é 28x30

    // alien saindo pela esquerda
    if (x + sprite->Width() < 0)
        x = float(window->Width());

    // alien saindo pela direita
    if (x > window->Width())
        x = float(-sprite->Width());
}

// ---------------------------------------------------------------------------------
