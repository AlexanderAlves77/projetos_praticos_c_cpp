#include "framework/Application.h"

namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const string& title, sf::Uint32 style)
		: mWindow{ sf::VideoMode(windowWidth, windowHeight), title, style },
		mTargetFrameRate{60.0f},
		mTickClock{},
		currentWorld{nullptr}
	{}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.0f;
		float targetDeltaTime = 1.0f / mTargetFrameRate;

		while (mWindow.isOpen())
		{
			sf::Event windowEvent;

			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}

			accumulatedTime += mTickClock.restart().asSeconds();

			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);

		if (currentWorld)
		{
			currentWorld->BeginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}
	}

	void Application::Tick(float deltaTime)
	{
		LOG("Ticking at framerate: %f", 1.0f / deltaTime);
	}

	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display();
	}

	void Application::Render()
	{
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}