/*=================================================================================
*  Arquivo     : ScreenBuffer.h
*  Author      : Alexander Alves
*  Criação     : 13 Set 2023
*  Compilador  : Visual C++ 2019
*  Atualização : 13 Set 2023
*
*  Descrição:   Hello World in C++, Ansi-style
===================================================================================*/

#ifndef GRAPHICS_SCREENBUFFER_H_
#define GRAPHICS_SCREENBUFFER_H_

#include <stdint.h>

#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& screenBuffer);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	void Init(uint32_t format, uint32_t width, uint32_t h);

	inline SDL_Surface * GetSurface() {return mSurface;}

	void Clear(const Color& c = Color::Black());

	void SetPixel(const Color& color, int x, int y);

private:

	SDL_Surface * mSurface;
	uint32_t GetIndex(int r, int c);
};



#endif /* GRAPHICS_SCREENBUFFER_H_ */
