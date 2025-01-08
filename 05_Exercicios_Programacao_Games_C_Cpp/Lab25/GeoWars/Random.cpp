/**********************************************************************************
* Arquivo    : Random (C�digo Fonte)
* Author     : Alexander Alves
* Cria��o    : 03 Ago 2019
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Gerador de n�meros pseudoaleat�rios
*
**********************************************************************************/

#include "Random.h"

// ---------------------------------------------------------------------------------

random_device Random::seed;
mt19937 Random::mt { seed() };

// ---------------------------------------------------------------------------------

RandI::RandI(int min, int max): dist(min, max) {}

int RandI::Rand() { return dist(mt); }

// ---------------------------------------------------------------------------------

RandF::RandF(float min, float max) : dist(min, max) {}

float RandF::Rand() { return dist(mt); }

// ---------------------------------------------------------------------------------
