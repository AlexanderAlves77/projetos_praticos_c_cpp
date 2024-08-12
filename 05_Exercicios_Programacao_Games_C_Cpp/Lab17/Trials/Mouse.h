/**********************************************************************************
* Arquivo    : Mouse (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 14 Mai 2012
* Atualização: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Gerencia mouse na tela
*
**********************************************************************************/

#ifndef _TRIALSMENU_MOUSE_H_
#define _TRIALSMENU_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h"        

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();            // construtor
    ~Mouse();           // destrutor

    bool Clicked();     // click do mouse
    void Update();      // atualização do objeto
    void Draw();        // desenho do objeto 
}; 

// ---------------------------------------------------------------------------------

#endif