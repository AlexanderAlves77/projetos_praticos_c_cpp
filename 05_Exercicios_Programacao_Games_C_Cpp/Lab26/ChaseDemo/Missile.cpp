/**********************************************************************************
* Arquivo    : Missile (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 23 Nov 2011
* Atualiza��o: 23 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define uma classe para um m�ssil
*
**********************************************************************************/

#include "Missile.h"
#include "WallHit.h"
#include "ChaseDemo.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Player* & Missile::player = ChaseDemo::player;        // refer�ncia para o player

// ------------------------------------------------------------------------------

Missile::Missile()
{
    // inicializa sprite
    sprite = new Sprite("Resources/Missile.png");

    // cria bounding box
    BBox(new Circle(8));
    
    // inicializa velocidade
    speed.RotateTo(player->speed->Angle());
    speed.ScaleTo(15.0f);
    
    // move para posi��o
    MoveTo(player->X() + 22 * cos(speed.Radians()), player->Y() - 22 * sin(speed.Radians()));
    RotateTo(-player->speed->Angle() + 90.0f);

    // define tipo
    type = MISSILE;

    // incrementa contador
    ++Hud::missiles;
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;

    // decrementa contador
    --Hud::missiles;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // move m�ssel com vetor resultante
    Translate(speed.XComponent() * 90.0f * gameTime, -speed.YComponent() * 90.0f * gameTime);

    // remove m�ssil da cena se ele sair da �rea de jogo
    if (x > game->Width() || x < 0 || y > game->Height() || y < 0)
    {
        // volume do som de destrui��o depende da dist�ncia para o jogador
        const float MaxDistance = 4406;
        const float BaseVolume = 0.8f;
        float distance = Point::Distance(Point(x, y), Point(player->X(), player->Y()));
        float level = (MaxDistance - distance) / MaxDistance * BaseVolume;
        ChaseDemo::audio->Volume(HITWALL, level);
        ChaseDemo::audio->Play(HITWALL);

        // adiciona explos�o na cena
        ChaseDemo::scene->Add(new WallHit(x,y), STATIC);

        // remove m�ssil da cena
        ChaseDemo::scene->Delete();
    }
}

// -------------------------------------------------------------------------------
