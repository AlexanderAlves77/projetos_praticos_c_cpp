/**********************************************************************************
* Arquivo    : Missile (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 23 Nov 2011
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define uma classe para um m�ssil/proj�til
*
**********************************************************************************/

#ifndef _INERTIA_MISSILE_H_
#define _INERTIA_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Ship.h" 

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
    Sprite * sprite;                            // sprite do m�ssil
    Vector   speed;                             // velocidade do m�ssil
    
public:
    Missile(Ship * ship);                       // construtor
    ~Missile();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
}; 

// ------------------------------------------------------------------------------

#endif