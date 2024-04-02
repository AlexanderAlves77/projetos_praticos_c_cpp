/**********************************************************************************
* Arquivo    : WinGame (Código Fonte)
* Author     : Alexander Alves
* Criação    : 19 Mai 2007
* Atualização: 12 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Um jogo para Windows é uma classe derivada de Game.
*              Crie uma classe derivada e sobrescreva os métodos Init,
*              Update, Draw e Finalize.
*
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
/*	stringstream textSize;
	stringstream textMode;
	stringstream textMouse; */
	HDC hdc;
	int X = 0, Y = 0, endX = 0, endY = 0;
	int velX = 0, velY = 0, velXfn = 0, velYfn = 0;

public:	
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{
/*	textSize << "Tamanho: " << window->Width() << " x " << window->Height();
	textMode << "Formato: " << (window->Mode() == WINDOWED ? "Em Janela" : "Tela Cheia");  */

	hdc = GetDC(window->Id());
	X = 10;
	Y = 10;
	endX = 100;
	endY = 100;
	velX = 5;
	velY = 5;
	velXfn = 5;
	velYfn = 5;
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

/*	textMouse.str("");
	textMouse << window->MouseX() << " x " << window->MouseY();  */

	X += velX;
	Y += velY;
	endX += velXfn;
	endY += velYfn;

	if (X > window->Width()) velX = -velX;	
	if (Y > window->Height()) velY = -velY;
	if (X < 0) velX = -velX;
	if (Y < 0) velY = -velY;

	if (endX > window->Width()) velXfn = -velXfn;
	if (endY > window->Height()) velYfn = -velYfn;
	if (endX < 0) velXfn = -velXfn;
	if (endY < 0) velYfn = -velYfn;

	MoveToEx(hdc, X, Y, NULL);
} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{	
/*	window->Print("Window Game Demo", 10, 10, RGB(0, 0, 0));
	window->Print(textSize.str(), 10, 50, RGB(0,0,0)); 
	window->Print(textMode.str(), 10, 70, RGB(0,0,0)); 
	window->Print(textMouse.str(), 10, 90, RGB(0, 0, 0));  */

	LineTo(hdc, endX, endY);
} 

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}	


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------

