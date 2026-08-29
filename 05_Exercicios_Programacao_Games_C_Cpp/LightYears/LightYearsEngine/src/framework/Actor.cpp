#include "framework/Actor.h"

namespace ly
{
	Actor::Actor(World* owingWorld, const string& texturePath)
		: mOwingWorld{owingWorld},
		mHasBeginPlay{false},
		mSprite{}, mTexture{}
	{
		SetTexture(texturePath);
	}

	Actor::~Actor()
	{
		LOG("Actor Destroy");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeginPlay)
		{
			mHasBeginPlay = true;
			BeginPlay();
		}
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}

	void Actor::SetTexture(const string& texturePath)
	{
		mTexture.loadFromFile(texturePath);
		mSprite.setTexture(mTexture);

		int textureWidth = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;
		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth,textureHeight} });
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy())
			return;

		window.draw(mSprite);
	}
}