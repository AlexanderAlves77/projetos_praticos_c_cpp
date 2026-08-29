#include "framework/World.h"

namespace ly
{
	World::World(Application* owningApp) 
		: mOwningApp{ owningApp }, 
		mBeginPlay(false),
		mActors{},
		mPendingActors{}
	{ }

	World::~World() {}

	void World::BeginPlayInternal()
	{
		if (!mBeginPlay)
		{
			mBeginPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();

		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}
		}			

		Tick(deltaTime);
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto actor : mActors)
		{
			actor->Render(window);
		}
	}

	void World::BeginPlay()
	{
		LOG("begin play");
	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at frame rate %f", 1.0 / deltaTime);
	}

	template<typename ActorType>
	weak<ActorType> World::SpawActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}