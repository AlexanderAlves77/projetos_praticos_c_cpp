/**********************************************************************************
* Arquivo    : Missile (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 23 Nov 2011
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define uma classe para um m�ssil/proj�til
*
**********************************************************************************/

#include "Missile.h"
#include "Vector2D.h"

// ------------------------------------------------------------------------------

Missile::Missile(Plane * plane, Image * img, float delta)
{
    // inicializa sprite
    sprite = new Sprite(img);

    // inicializa vetor velocidade
    speed.RotateTo(plane->Angle() + delta);
    speed.ScaleTo(500);
    
    // usa mesma rota��o do avi�o
    RotateTo(plane->Rotation() + delta);
    
    // move para posi��o
    float dx = 50 * cos(speed.Radians());
    float dy = 50 * sin(speed.Radians());
    MoveTo(plane->X() + dx, plane->Y() - dy);
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // desloca m�ssil pelas componentes do vetor speed
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    
    // se o m�ssil sair da janela
    if (x > window->Width() || x < 0 || y > window->Height() || y < 0)
    {
        Vector2D::audio->Play(EXPLOSION);
        Vector2D::scene->Delete();
    }
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
