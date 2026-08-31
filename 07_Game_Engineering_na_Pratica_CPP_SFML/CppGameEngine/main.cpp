#include <iostream>

int main()
{
    int playerHealth = 100;
    int playerCoins = 25;
    int playerLevel = 1;

    std::cout << "=== Initial State ===" << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;

    playerHealth = playerHealth - 20;
    playerCoins = playerCoins + 10;
    playerLevel = 2;

    std::cout << std::endl;
    std::cout << "=== Current State ===" << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;

	return 0;
}