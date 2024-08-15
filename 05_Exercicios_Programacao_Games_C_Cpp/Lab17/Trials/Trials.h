/**********************************************************************************
* Arquivo    : Trials (Arquivo de Cabe�alho)
* Author     : Alexander Alves
* Cria��o    : 14 Mai 2012
* Atualiza��o: 19 Dez 2023
* Compilador : Visual C++ 2019
*
* Descri��o  : Exemplo de interface com menus
*
**********************************************************************************/

#ifndef _TRIALS_H_
#define _TRIALS_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Mouse.h"
#include "Item.h"
#include "Sprite.h"
#include "Scene.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

enum MenuID {SINGLE, MULTI, TRACKS, LEADERBOARD, OPTIONS, EXIT};

enum Music  {EVOLUTION};

// ------------------------------------------------------------------------------

class Trials : public Game
{
private:
    static const int MaxItens = 6;    // n�mero de itens do menu

    Scene  * scene = nullptr;         // cena do jogo
    Audio  * audio = nullptr;         // sistema de �udio
    Sprite * backg = nullptr;         // plano de fundo
    Mouse  * mouse = nullptr;         // objeto mouse
  
    Item * selected = nullptr;        // item selecionado    
    Item * menu[MaxItens] = { 0 };    // itens do menu
    
    bool viewBBox = false;            // visualiza bounding box
    bool editMode = false;            // jogo em modo de exibi��o
    bool followMode = false;          // item em modo seguidor
    
public:
    void Init();                      // inicializa��o
    void Update();                    // atualiza��o
    void Draw();                      // desenho
    void Finalize();                  // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif