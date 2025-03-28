/*=================================================================================
*  Arquivo     : Screen.h
*  Author      : Alexander Alves
*  Cria��o     : 13 Set 2023
*  Compilador  : Visual C++ 2019
*  Atualiza��o : 13 Set 2023
*
*  Descri��o:   Hello World in C++, Ansi-style
===================================================================================*/

#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include <vector>

class Vec2D;
class Line2D;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
	void SwapScreens();

	inline void SetClearColor(const Color& clearColor) {mClearColor = clearColor;}
	inline uint32_t Width() const {return mWidth;}
	inline uint32_t Height() const {return mHeight;}

	//Draw Methods go here
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);

private:

	Screen(const Screen& screen);
	Screen& operator=(const Screen& screen);

	void ClearScreen();
	void FillPoly(const std::vector<Vec2D>& points, const Color& color);
	uint32_t mWidth;
	uint32_t mHeight;

	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrWindowSurface;
};



#endif /* GRAPHICS_SCREEN_H_ */
