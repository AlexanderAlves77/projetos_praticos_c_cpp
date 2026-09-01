#include <iostream>

enum class GameState
{
	Menu,
	Playing,
	GameOver
};

void ShowGameStart();
void ShowStartGameMessage();
void ShowSeparator();
void ShowGameOver();
void ShowGameFinished();
void ShowPlayerHealth(int playerHealth);
void ShowPlayerState(int frame, int playerHealth, int playerCoins);
void ShowGameSummary(int frame, int playerHealth, int playerCoins);

int main()
{
	const int DAMAGE_PER_FRAME = 25;

	bool isRunning = true;
	int frame = 0;
	int playerHealth = 100;
	int playerCoins = 0;

	ShowPlayerHealth(playerHealth);

	GameState currentState = GameState::Menu;

	ShowSeparator();
	ShowGameStart();
	ShowSeparator();

	while (isRunning)
	{
		frame++;

		// 1. Process
		if (currentState == GameState::Menu)
		{
			ShowStartGameMessage();

			currentState = GameState::Playing;
		}

		// 2. Update
		if (currentState == GameState::Playing)
		{
			playerHealth -= DAMAGE_PER_FRAME;
			playerCoins++;
		}

		// 3. Check
		if (playerHealth <= 0)
		{
			playerHealth = 0;
			currentState = GameState::GameOver;
		}

		// 4. Show State
		ShowPlayerState(frame, playerHealth, playerCoins);		

		if (currentState == GameState::GameOver)
		{
			ShowGameOver();

			isRunning = false;
		}		
	}

	ShowSeparator();
	ShowGameFinished();
	ShowGameSummary(frame, playerHealth, playerCoins);
	ShowSeparator();

	return 0;
}

void ShowGameStart()
{
	std::cout << "=== MINI GAME LOOP START ===" << std::endl;
}

void ShowStartGameMessage()
{
	std::cout << "Starting Game." << std::endl;
}

void ShowSeparator()
{
	std::cout << "--------------------------------" << std::endl;
}

void ShowGameOver()
{
	std::cout << "Player defeated." << std::endl;
}


void ShowPlayerHealth(int playerHealth)
{
	std::cout << "Health: " << playerHealth << std::endl;
}

void ShowPlayerState(int frame, int playerHealth, int playerCoins)
{
	std::cout << "Frame: " << frame << std::endl;
	std::cout << "Health: " << playerHealth << std::endl;
	std::cout << "Coins: " << playerCoins << std::endl;
	std::cout << std::endl;
}

void ShowGameSummary(int frame, int playerHealth, int playerCoins)
{
	std::cout << "Frames: " << frame << std::endl;
	std::cout << "Health: " << playerHealth << std::endl;
	std::cout << "Final Coins: " << playerCoins << std::endl;
}

void ShowGameFinished()
{
	std::cout << "=== MINI GAME LOOP FINISHED ===" << std::endl;
}