/**********************************************************************************
* Arquivo    : Explosion (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 17 Mar 2013
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Efeito de explos�o usando sistema de part�culas
*
**********************************************************************************/

#ifndef _GEOWARS_EXPLOSION_H_
#define _GEOWARS_EXPLOSION_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Particles * sparks;                 // sistema de part�culas
    
public:
    Explosion(float pX, float pY);      // construtor
    ~Explosion();                       // destrutor

    int Size();                         // quantidade de part�culas
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline int Explosion::Size()
{ return sparks->Size(); }

inline void Explosion::Draw()
{ sparks->Draw(Layer::MIDDLE, 1.0f); }

// ---------------------------------------------------------------------------------


#endif