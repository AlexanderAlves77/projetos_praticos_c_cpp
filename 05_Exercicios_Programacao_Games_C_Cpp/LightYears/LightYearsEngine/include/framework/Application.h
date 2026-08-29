#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <framework/Core.h>
#include "framework/World.h"
using namespace std;

namespace ly
{
	class World;

	class Application
	{
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;	

		shared<World> currentWorld;

		void RenderInternal();
		void TickInternal(float deltaTime);

		virtual void Render();
		virtual void Tick(float deltaTime);

	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, 
			const string & title, sf::Uint32 style);		
		void Run();	

		template<typename WorldType>
		weak<WorldType> LoadWorld();
	};
}

#endif