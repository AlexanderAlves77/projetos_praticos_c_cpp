/**********************************************************************************
* Arquivo    : Mouse (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 14 Mai 2012
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Gerencia mouse na tela
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
    void Update();      // atualiza��o do objeto
    void Draw();        // desenho do objeto 
}; 

// ---------------------------------------------------------------------------------

#endif