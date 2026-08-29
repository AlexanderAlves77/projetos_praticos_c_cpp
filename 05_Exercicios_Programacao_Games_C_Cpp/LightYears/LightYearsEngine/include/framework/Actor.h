#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Object.h"
using namespace std;

namespace ly
{
	class World;

	class Actor : public Object
	{
	private:
		World* mOwingWorld;
		bool mHasBeginPlay;

		sf::Sprite mSprite;
		sf::Texture mTexture;
		
	public:
		Actor(World* owingWorld, const string & texturePath = "");
		virtual ~Actor();

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		void Tick(float deltaTime);
		void SetTexture(const string& texturePath);
		void Render(sf::RenderWindow& window);
	};
}

#endif