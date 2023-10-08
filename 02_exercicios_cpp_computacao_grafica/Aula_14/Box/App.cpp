/*=================================================================================
*  Arquivo     : App (Código Fonte)
*  Criação     : 16 Set 2023
*  Author      : Alexander Alves
*  Compilador  : Visual C++ 2019
*  Atualização : 16 Set 2023
*
*  Descrição   : Uma classe abstrata para representar uma aplicação
*                Todas as aplicações derivadas da classe App devem
*                sobrescrever os métodos Init, Update, Draw e Finalize.
===================================================================================*/

#include "App.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Graphics* & App::graphics  = Engine::graphics;       // componente gráfico 
Window*   & App::window    = Engine::window;         // janela da aplicação
Input*    & App::input     = Engine::input;          // dispositivos de entrada
double    & App::frameTime = Engine::frameTime;      // tempo do último quadro

// -------------------------------------------------------------------------------

App::App()
{
}

// -------------------------------------------------------------------------------

App::~App()
{
}

// -------------------------------------------------------------------------------