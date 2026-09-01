#include <iostream>

enum class GameState
{
	Menu,
	Playing,
	GameOver
};

int main()
{
	const int DAMAGE_PER_FRAME = 5;
	const int COINS_PER_FRAME = 1;
	const int MAX_FRAMES = 100;

	bool isRunning = true;
	int frame = 0;
	int playerHealth = 100;
	int playerCoins = 0;

	GameState currentState = GameState::Menu;
	std::cout << "=== MINI GAME LOOP START ===" << std::endl;

	while (isRunning)
	{
		frame++;

		// 1. Process
		if (currentState == GameState::Menu)
		{
			std::cout << "Starting Game." << std::endl;
			currentState = GameState::Playing;
		}

		// 2. Update
		if (currentState == GameState::Playing)
		{
			playerHealth -= DAMAGE_PER_FRAME;
			playerCoins += COINS_PER_FRAME;
		}

		// 3. Check
		if (playerHealth <= 0)
		{
			playerHealth = 0;
			currentState = GameState::GameOver;
		}

		if (frame >= MAX_FRAMES)
		{
			isRunning = false;
		}	

		// 4. Show State
		std::cout << std::endl;
		std::cout << "Frame: " << frame << std::endl;
		std::cout << "Health: " << playerHealth << std::endl;
		std::cout << "Coins: " << playerCoins << std::endl;		

		if (currentState == GameState::Playing)
		{
			std::cout << "State Playing" << std::endl;
		}

		if (currentState == GameState::GameOver)
		{
			std::cout << "State: GameOver" << std::endl;
			std::cout << "Player defeated." << std::endl;
			isRunning = false;
		}		
	}

	std::cout << std::endl;
	std::cout << "=== MINI GAME LOOP FINISHED ===" << std::endl;
	std::cout << "Frames: " << frame << std::endl;
	std::cout << "Final Health: " << playerHealth << std::endl;
	std::cout << "Final Coins: " << playerCoins << std::endl;

	return 0;
}