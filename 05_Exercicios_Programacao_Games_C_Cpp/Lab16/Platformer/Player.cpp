/**********************************************************************************
* Arquivo    : Player (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 07 Fev 2013
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Player usado em SoundDistance
*
**********************************************************************************/

#include "Player.h"
#include "Platformer.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    // sequ�ncias de anima��o do player
    uint invert[4] = {6,7,8,9};
    uint normal[4] = {1,2,3,4};

    anim->Add(INVERTED, invert, 4);
    anim->Add(NORMAL, normal, 4);

    // cria bounding box
    BBox(new Rect(-1.0f * tileset->TileWidth() / 2.0f, 
                  -1.0f * tileset->TileHeight() / 2.0f, 
                   tileset->TileWidth() / 2.0f,
                   tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = NORMAL;
    keyCtrl = false;    

    // posi��o inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);

    // frequ�ncia inicial da m�sica
    freq = 1.0f;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mant�m personagem na posi��o correta em cima da plataforma
    if (gravity == NORMAL) 
    {
        freq += 0.25f * gameTime;
        MoveTo(window->CenterX(), obj->Y() - 32);
    }
    else
    {
        freq -= 0.25f * gameTime;
        MoveTo(window->CenterX(), obj->Y() + 32);
    }

    // limita a faixa da frequ�ncia [0.9 - 1.1]
    if (freq > 1.1)
        freq = 1.1f;
    else
        if (freq < 0.9)
            freq = 0.9f;

    // ajusta a frequ�ncia
    Platformer::audio->Frequency(MUSIC, freq);

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = !gravity;

        // toca efeito sonoro 
        Platformer::audio->Play(TRANSITION);

        // tira player da plataforma para evitar 
        // detec��o de colis�o no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0 , -12);
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // ----------------------------------------------------
    // a��o da gravidade sobre o personagem
    // ----------------------------------------------------
    if (gravity == NORMAL)    
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);

    // atualiza anima��o
    anim->Select(gravity);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------