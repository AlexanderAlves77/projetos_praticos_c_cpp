/**********************************************************************************
* Arquivo    : Particles (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 07 Out 2012
* Atualiza��o: 21 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Define um sistema de part�culas
*
**********************************************************************************/

#ifndef _PROGJOGOS_PARTICLES_H_
#define _PROGJOGOS_PARTICLES_H_

// ---------------------------------------------------------------------------------

#include "Sprite.h"              // desenho de sprites
#include "Timer.h"               // controle do tempo
#include "Types.h"               // tipos espec�ficos da engine
#include "Vector.h"              // representa��o de vetores
#include <list>                  // lista de elementos
#include <random>                // n�meros aleat�rios

// ---------------------------------------------------------------------------------

using std::list;
using std::random_device;
using std::mt19937;
using Rnd = std::uniform_real_distribution<float>;

// ---------------------------------------------------------------------------------

struct Generator
{
    string imgFile;        // arquivo de imagem da part�cula
    float  angle;          // dire��o do emissor de part�culas
    float  spread;         // �ngulo de espalhamento das part�culas
    float  lifetime;       // tempo de vida das part�culas (em segundos)
    float  frequency;      // frequ�ncia de gera��o de part�culas (em segundos)
    float  percentToDim;   // percentual de vida para come�ar a desaparecer
    float  minSpeed;       // velocidade m�nima das part�culas
    float  maxSpeed;       // velocidade m�xima das part�culas
    Color  color;          // cor das part�culas
};

struct Particle
{
    float  x, y;           // posi��o da part�cula
    Vector speed;          // dire��o e velocidade
    llong  timestamp;      // instante de cria��o
};

// ---------------------------------------------------------------------------------

class Particles
{
private:
    Generator generator;           // gerador de part�culas
    Sprite * sprite;               // sprite da part�cula    
    list<Particle*> particles;     // lista de part�culas

    Timer timer;                   // controle de tempo
    random_device rd;              // gerador de semente
    mt19937 mt{ rd() };            // gerador de n�mero aleat�rio
    Rnd RandSpread { -generator.spread/2, generator.spread/2 }; // valores aleat�rios para o espalhamento
    Rnd RandSpeed { generator.minSpeed, generator.maxSpeed };   // valores aleat�rios para a velocidade

    void Build(float posX, float posY);   // cria uma part�cula

public:
    Particles(const Generator & gen);     // construtor
    ~Particles();                         // destrutor

    uint Size();                          // retorna o n�mero de part�culas
    bool Inactive();                      // retorna o estado das part�culas
    void Generate(float x, float y, int count = 1); // gera novas part�culas
    void Update(float delta);             // atualiza posi��o das part�culas por delta
    void Draw(float z, float factor = 0.0f);        // desenha part�culas        
}; 

// ---------------------------------------------------------------------------------

inline uint Particles::Size()
{ return uint(particles.size()); }

inline bool Particles::Inactive()
{ return (particles.size() == 0); }

// ---------------------------------------------------------------------------------

#endif