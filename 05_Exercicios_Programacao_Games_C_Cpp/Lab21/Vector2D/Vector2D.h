/**********************************************************************************
* Arquivo    : Vector2D (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 11 Nov 2011
* Atualiza��o: 20 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Exemplo de utiliza��o da classe Vector
*
**********************************************************************************/

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Scene.h"
#include "Audio.h"
#include "Sprite.h"
#include "Resources.h"
#include "Plane.h"

// ------------------------------------------------------------------------------

enum SoundIDs { PULSE, EXPLOSION };

// ------------------------------------------------------------------------------

class Vector2D : public Game
{
private:
    Sprite * backg = nullptr;           // pano de fundo
    Sprite * infoBox = nullptr;         // caixa de informa��es
    Sprite * keyMap = nullptr;          // caixa para teclas de atalho    
    Plane * plane = nullptr;            // objeto avi�o
    
    float bgScale = 0.0f;               // escala do pano de fundo

public:
    static Scene * scene;               // gerenciador de cena 
    static Audio * audio;               // sistema de �udio

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif