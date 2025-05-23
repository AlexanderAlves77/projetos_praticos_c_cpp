/**********************************************************************************
* Arquivo    : TileSet (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 17 Abr 2012
* Atualiza��o: 25 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Representa uma folha de sprites
*
**********************************************************************************/

#include "TileSet.h"
#include "Image.h"

// -------------------------------------------------------------------------------

TileSet::TileSet(string filename, uint tileWidth, uint tileHeight, uint numCols, uint numTiles) : 
    image(new Image(filename)), 
    width(tileWidth), 
    height(tileHeight), 
    columns(numCols),    
    size(numTiles)
{
    
}

// -------------------------------------------------------------------------------

TileSet::TileSet(string filename, uint numLines, uint numCols) :
    image(new Image(filename)),
    columns(numCols),
    size(numLines* numCols)
{
    width = image->Width() / numCols;
    height = image->Height() / numLines;
}

// -------------------------------------------------------------------------------

TileSet::~TileSet()
{
    // libera mem�ria ocupada pela imagem
    if (image)
    {
         delete image;
    }
}

// -------------------------------------------------------------------------------