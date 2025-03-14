/**********************************************************************************
* Arquivo    : FontDemo (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 07 Out 2011
* Atualiza��o: 14 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Testa a classe Font com exibi��o de texto com diversas fontes.
*
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

class FontDemo : public Game
{
private:
    Sprite * backg    = nullptr;
    Font   * consolas = nullptr;
    Font   * courier  = nullptr;
    Font   * verdana  = nullptr;
    Font   * segoe    = nullptr;
    Font   * firecode = nullptr;
    
public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------

void FontDemo::Init()
{
    // background
    backg = new Sprite("Resources/paper.png");

    // cria fontes
    consolas = new Font("Resources/consolas12.png");
    consolas->Spacing("Resources/consolas12.dat");
    //consolas->Spacing(12);

    courier = new Font("Resources/courier12.png");
    courier->Spacing("Resources/courier12.dat");
    //courier->Spacing(12);

    verdana  = new Font("Resources/verdana12.png");
    verdana->Spacing("Resources/verdana12.dat");
    //verdana->Spacing(12);

    segoe = new Font("Resources/SegoeUI32.png");
    segoe->Spacing("Resources/SegoeUI32.dat");
    //segoe->Spacing(32);

    firecode = new Font("Resources/FiraCode12.png");
    firecode->Spacing("Resources/FiraCode12.dat");
    //firecode->Spacing(20);
}

// ------------------------------------------------------------------------------

void FontDemo::Update()
{
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
} 

// ------------------------------------------------------------------------------

void FontDemo::Draw()
{
    // desenha background
    backg->Draw(window->CenterX(), window->CenterY());

    Color black (0.0f, 0.0f, 0.0f, 1.0f);
    Color blue  (0.2f, 0.2f, 1.0f, 1.0f);
    Color red   (1.0f, 0.2f, 0.2f, 1.0f);
    Color green (0.1f, 0.6f, 0.1f, 1.0f);

    firecode->Draw(60, 45, "Fira Code 12", green);
    firecode->Draw(60, 75, "Esta � a fonte Fira Code 12 pontos", black);
    firecode->Draw(60, 105, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black);
    firecode->Draw(60, 135, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black);

    // desenha o mesmo texto com v�rias fontes diferentes 
    //consolas->Draw(60, 45, "Consolas 12", blue);
    //consolas->Draw(60, 75, "Esta � a fonte Consolas 12 pontos", black);
    //consolas->Draw(60, 105, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black);
    //consolas->Draw(60, 135, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black);

    //courier->Draw(60, 195, "Courier 12", red);
    //courier->Draw(60, 225, "Esta � a fonte Courier 12 pontos", black);
    //courier->Draw(60, 255, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black);
    //courier->Draw(60, 285, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black);

    courier->Draw(60, 195, "Courier 12", red, Layer::FRONT, 1.0f, -90);
    courier->Draw(60, 225, "Esta � a fonte Courier 12 pontos", black, Layer::FRONT, 1.0f, -60);
    courier->Draw(60, 255, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black, Layer::FRONT, 1.0f, -45);
    courier->Draw(60, 285, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black, Layer::FRONT, 1.0f, -30);

    //verdana->Draw(60, 345, "Verdana 12", green);
    //verdana->Draw(60, 375, "Esta � a fonte Verdana 12 pontos", black);
    //verdana->Draw(60, 405, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black);
    //verdana->Draw(60, 435, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black);

    verdana->Draw(60, 345, "Verdana 12", green);
    verdana->Draw(60, 375, "Esta � a fonte Verdana 12 pontos", black, Layer::FRONT, 0.5f);
    verdana->Draw(60, 405, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", black, Layer::FRONT, 0.75f);
    verdana->Draw(60, 435, "abcdefghijklmnopqrstuvwxyz!@#$%&*(+^~������", black, Layer::FRONT, 1.50f);    

    //segoe->Draw(60, 500, "Font Demo", Color(0.5f, 0.3f, 0.9f, 1.0f), Layer::FRONT, 1.0f, -45);
} 

// ------------------------------------------------------------------------------

void FontDemo::Finalize()
{
    delete backg;
    delete consolas;
    delete courier;
    delete verdana;
    delete segoe;
    delete firecode;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(600, 474);
    engine->window->Color(240, 240, 120);
    engine->window->Title("Font Demo");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new FontDemo());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

