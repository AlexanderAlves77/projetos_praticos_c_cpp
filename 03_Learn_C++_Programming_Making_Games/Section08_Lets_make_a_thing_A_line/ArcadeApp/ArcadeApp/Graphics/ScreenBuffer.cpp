/*=================================================================================
*  Arquivo     : ScreenBuffer.h
*  Author      : Alexander Alves
*  Cria��o     : 13 Set 2023
*  Compilador  : Visual C++ 2019
*  Atualiza��o : 13 Set 2023
*
*  Descri��o:   Hello World in C++, Ansi-style
===================================================================================*/

#include "../Header/Arcade_Head.h"
#include <cassert>

ScreenBuffer::ScreenBuffer(): mSurface(nullptr)
{

}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
	mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);

	SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
}

ScreenBuffer::~ScreenBuffer()
{
	if(mSurface)
	{
		SDL_FreeSurface(mSurface);
	}
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer)
{
	if(this == &screenBuffer)
	{
		return *this;
	}

	if(mSurface != nullptr)
	{
		SDL_FreeSurface(mSurface);
		mSurface = nullptr;
	}

	if(screenBuffer.mSurface != nullptr)
	{
		mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);

		SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
	}

	return *this;

}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
	mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
	Clear();
}

void ScreenBuffer::Clear(const Color& c)
{
	assert(mSurface);
	if(mSurface)
	{
		SDL_FillRect(mSurface, nullptr, c.GetPixelColor());
	}
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
	assert(mSurface);

	if(mSurface && (y < mSurface->h && y >= 0 && x >= 0 && x < mSurface->w))
	{
		SDL_LockSurface(mSurface);

			uint32_t * pixels = (uint32_t*)mSurface->pixels;

			size_t index = GetIndex(y, x);
        
            pixels[index] = color.GetPixelColor();

			SDL_UnlockSurface(mSurface);
	}
}

uint32_t ScreenBuffer::GetIndex(int r, int c)
{
	assert(mSurface);
	if(mSurface)
	{
		return r * mSurface->w + c;
	}
	return 0;
}

