#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	class Actor;
	class Application;

	class World
	{
	private:
		bool mBeginPlay;
		Application* mOwningApp;

		void BeginPlay();
		void Tick(float deltaTime);

		List<shared<Actor>> mActors;
		List<shared<Actor>> mPendingActors;

	public:
		World(Application * owningApp);
		virtual ~World();
		
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow & window);

		template<typename ActorType>
		weak<ActorType> SpawActor();
	};
}

#endif