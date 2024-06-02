/**********************************************************************************
* Arquivo    : TileSet (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 17 Abr 2012
* Atualiza��o: 16 Dez 2023
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

TileSet::~TileSet()
{
    // libera mem�ria ocupada pela imagem
    if (image)
    {
         delete image;
    }
}

// -------------------------------------------------------------------------------