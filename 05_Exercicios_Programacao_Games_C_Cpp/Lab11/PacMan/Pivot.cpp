/**********************************************************************************
* Arquivo    : Pivot (Código Fonte)
* Author     : Alexander Alves
* Criação    : 01 Jan 2013
* Atualização: 14 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Ponto de mudança de direção para o jogador e fantasmas
*
**********************************************************************************/

#include "PacMan.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Pivot::Pivot(bool l, bool r, bool u, bool d)
{
    left  = l;
    right = r;
    up    = u;
    down  = d;

    BBox(new Rect(-4, -4, 4, 4));
    type = PIVOT;
}

// ---------------------------------------------------------------------------------

Pivot::~Pivot()
{
}

// ---------------------------------------------------------------------------------

