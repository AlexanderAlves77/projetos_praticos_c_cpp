/**********************************************************************************
* Arquivo    : Image (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 16 Mar 2012
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define uma classe para representar imagens
*
**********************************************************************************/

#ifndef _PROGJOGOS_IMAGE_H_
#define _PROGJOGOS_IMAGE_H_

#ifdef ENGINE_EXPORTS
#define DLL __declspec( dllexport ) 
#else
#define DLL __declspec( dllimport )
#endif

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"        // tipos espec�ficos do motor
#include "Texture.h"      // fun��o para carregar textura
#include <string>         // classe string de C++
using std::string;        // classe pode ser usada sem std::

// ---------------------------------------------------------------------------------

class DLL Image
{
private:
    ID3D11ShaderResourceView * textureView;      // view associada a textura
    uint width;                                  // altura da imagem
    uint height;                                 // largura da imagem

public:
    Image(string filename);                      // constroi imagem a partir de um arquivo

    Image(string filename,                       // arquivo que cont�m os blocos de imagem
        uint tileWidth,                          // largura dos blocos
        uint tileHeight,                         // altura dos blocos
        uint numColumns,                         // n�mero de colunas 
        int* tiledMap,                           // matriz para montagem dos blocos
        uint tiledMapCols,                       // n�mero de colunas da matriz
        uint tiledMapRows);                      // n�mero de linhas da matriz

    ~Image();                                    // destrutor

    uint Width() const;                          // retorna largura da imagem
    uint Height() const;                         // retorna altura da imagem
    ID3D11ShaderResourceView * View() const;     // retorna ponteiro para a view da imagem
};

// ---------------------------------------------------------------------------------
// M�todos Inline

// retorna largura da textura
inline uint Image::Width() const
{ return width; }

// retorna altura da textura
inline uint Image::Height() const
{ return height; }

// retorna ponteiro para textura D3D
inline ID3D11ShaderResourceView * Image::View() const
{ return textureView; }

// --------------------------------------------------------------------------------

#endif




