/**********************************************************************************
* Arquivo    : Galaga (Arquivo de Cabeçalho)
* Author     : Alexander Alves
* Criação    : 23 Set 2011
* Atualização: 13 Dez 2023
* Compilador : Visual C++ 2019
*
* Descrição  : Usa a classe Scene para gerenciar muitos objetos na tela
*
**********************************************************************************/


#include "Game.h"
#include "Scene.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Galaga : public Game
{
private:
    Sprite * backg = nullptr;
    Sprite * title = nullptr;

public:
    static Scene * scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------
