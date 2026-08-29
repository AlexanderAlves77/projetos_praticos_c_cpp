#include "gameFramework/GameApplication.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication() 
		: Application{ 600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close }
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawActor<Actor>();
		actorsToDestroy = newWorld.lock()->SpawActor<Actor>();
		actorsToDestroy.lock()->SetTexture("C:/Users/Alexander/Downloads/AECA/node_sistemas/projetos_praticos_c_cpp/05_Exercicios_Programacao_Games_C_Cpp/LightYears/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;

		if (counter > 2.0f)
		{
			if (!actorsToDestroy.expired())
			{
				actorsToDestroy.lock()->Destroy();
			}
		}

	}
}