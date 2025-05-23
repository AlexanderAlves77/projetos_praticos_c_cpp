/**********************************************************************************
* Arquivo    : Timer (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 02 Abr 2011
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Usa um contador de alta precis�o para medir o tempo.
*
**********************************************************************************/

#ifndef _PROGJOGOS_TIMER_H_
#define _PROGJOGOS_TIMER_H_

#ifdef ENGINE_EXPORTS
#define DLL __declspec( dllexport ) 
#else
#define DLL __declspec( dllimport )
#endif

// -------------------------------------------------------------------------------

#include <windows.h>                            // contador de alta precis�o
#include "Types.h"                              // tipos espec�ficos do motor

// -------------------------------------------------------------------------------

class DLL Timer
{
private:
    LARGE_INTEGER start, end;                   // valores de in�cio e fim do contador
    LARGE_INTEGER freq;                         // freq��ncia do contador
    bool stoped;                                // estado da contagem
    
public:
    Timer();                                    // constructor

    void  Start();                              // inicia/retoma contagem do tempo
    void  Stop();                               // p�ra contagem do tempo
    float Reset();                              // reinicia contagem e retorna tempo transcorrido
    float Elapsed();                            // retorna tempo transcorrido em segundos    
    bool  Elapsed(float time);                  // testa se transcorreu o tempo em segundos

    llong Stamp();                              // retorna valor atual do contador
    float Elapsed(llong stamp);                 // retorna tempo transcorrido desde a marca
    bool  Elapsed(llong stamp, float time);     // testa se transcorreu o tempo desde a marca
}; 

// -------------------------------------------------------------------------------

// Fun��es Inline

inline bool Timer::Elapsed(float time)
{ return (Elapsed() >= time ? true : false); }

inline bool Timer::Elapsed(llong stamp, float time)
{ return (Elapsed(stamp) >= time ? true : false); }

// -------------------------------------------------------------------------------

#endif