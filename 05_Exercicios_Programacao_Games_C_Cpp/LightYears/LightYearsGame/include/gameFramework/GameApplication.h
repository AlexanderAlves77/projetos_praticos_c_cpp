#include <framework/Application.h>
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/Core.h"
using namespace std;

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	private:
		float counter;
		weak<Actor> actorsToDestroy;

	public:
		GameApplication();
		virtual void Tick(float deltaTime) override;
	};
}