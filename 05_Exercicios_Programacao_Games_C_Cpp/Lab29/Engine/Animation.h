/**********************************************************************************
* Arquivo    : Animation (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 28 Set 2011
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Classe para animar sequ�ncias em folha de sprites
*
**********************************************************************************/

#ifndef _PROGJOGOS_ANIMATION_H_
#define _PROGJOGOS_ANIMATION_H_

#ifdef ENGINE_EXPORTS
#define DLL __declspec( dllexport ) 
#else
#define DLL __declspec( dllimport )
#endif

// ---------------------------------------------------------------------------------

#include "Sprite.h"              // tipo sprite para renderiza��o
#include "TileSet.h"             // folha de sprites da anima��o
#include "Timer.h"               // tempo entre quadros da anima��o
#include "Types.h"               // tipos espec�ficos da engine

#include <unordered_map>         // biblioteca STL                
using std::unordered_map;        // usando tabelas de dispers�o
using std::pair;                 // usando pares de elementos

// seq��ncia <vetor, tam>
using AnimSeq = pair<uint*, uint>;

// tabela de dispers�o <uint, AnimSeq>
using HashTable = unordered_map<uint, AnimSeq>;

// ---------------------------------------------------------------------------------

class DLL Animation
{
private:
    uint  iniFrame;             // quadro inicial da seq��ncia
    uint  endFrame;             // quadro final da seq��ncia
    uint  frame;                // quadro atual da anima��o    
    bool  animLoop;             // anima��o em loop infinito
    float animDelay;            // espa�o de tempo entre quadros (em segundos)
    Timer timer;                // medidor de tempo entre quadros da anima��o
    TileSet * tileSet;          // ponteiro para folha de sprites da anima��o
    SpriteData sprite;          // sprite a ser desenhado
    HashTable table;            // tabela com seq��ncias de anima��o
    uint * sequence;            // seq��ncia atualmente selecionada

public:
    Animation(TileSet* tiles, float delay, bool repeat);                
    ~Animation();                                                           

    void Add(uint id, uint * seq, uint seqSize);    // adiciona sequ�ncia de anima��o
    void Select(uint id);                           // seleciona sequ�ncia atual 

    void Draw(                                      // desenha o quadro atual da anima��o
        float x, float y, float z = Layer::MIDDLE,  // coordenadas da tela
        float scale = 1.0f, float rotation = 0.0f,  // escala e rota��o
        Color color = { 1, 1, 1, 1 });              // efeito de cor

    void Draw(                                      // desenha um quadro da folha de sprites    
        uint aFrame,                                // quadro da folha a desenhar
        float x, float y, float z = Layer::MIDDLE,  // coordenadas da tela
        float scale = 1.0f, float rotation = 0.0f,  // escala e rota��o
        Color color = { 1, 1, 1, 1 });              // efeito de cor

    void Frame(uint aFrame);                        // define o quadro atual da anima��o
    uint Frame();                                   // retorna o quadro de anima��o ativo
    void Delay(float delay);                        // define o tempo entre quadros

    bool Inactive();                                // verifica se a anima��o j� encerrou
    void NextFrame();                               // passa para o pr�ximo frame da anima��o
    void Restart();                                 // reinicia a animac�o (pelo primeiro frame da seq��ncia)
}; 

// ---------------------------------------------------------------------------------
// fun��es membro inline

// desenha quadro atual da anima��o
inline void Animation::Draw(float x, float y, float z, float scale, float rotation, Color color)
{ sequence ? Draw(sequence[frame], x, y, z, scale, rotation, color) : Draw(frame, x, y, z, scale, rotation, color); }

// define o frame atual da anima��o
inline void Animation::Frame(uint aFrame)
{ frame = aFrame; }

// retorna o frame de anima��o ativo
inline unsigned Animation::Frame()
{ return (sequence ? sequence[frame] : frame); }

inline void Animation::Delay(float delay)
{ animDelay = delay; }

// verifica se a anima��o j� encerrou
inline bool Animation::Inactive()
{ return !animLoop && (frame > endFrame || (frame == endFrame && timer.Elapsed(animDelay))); }

// reinicia a animac�o (pelo primeiro frame da sequencia)
inline void Animation::Restart()
{ frame = 0; timer.Start(); }

// ---------------------------------------------------------------------------------

#endif