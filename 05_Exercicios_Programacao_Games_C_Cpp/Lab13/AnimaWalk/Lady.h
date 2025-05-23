/**********************************************************************************
* Arquivo    : Lady (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 27 Jan 2013
* Atualiza��o: 16 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Objeto Lady animado
*
**********************************************************************************/


#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum LadyState { STILL, WALKUP, WALKDOWN, WALKLEFT, WALKRIGHT };

// ---------------------------------------------------------------------------------

class Lady : public Object
{
private:
    TileSet   * walking;                // folha de sprites do personagem
    Animation * anim;                   // anima��o do personagem
    float       speed;                  // velocidade do personagem

public:
    uint state;                         // estado atual do personagem

    Lady();                             // construtor
    ~Lady();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Lady::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif