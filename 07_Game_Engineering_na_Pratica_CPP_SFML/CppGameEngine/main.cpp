#include <iostream>

int main()
{
    std::string playerName = "Alex";
    int playerHealth = 100;
    int playerCoins = 25;
    int playerLevel = 1;
    float playerSpeed = 4.5f;
    bool isAlive = true;
    char playerGrade = 'A';

    std::cout << std::boolalpha;

    std::cout << "=== PLAYER STATE ===" << std::endl;
    std::cout << "Name: " << playerName << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;
    std::cout << "Speed: " << playerSpeed << std::endl;
    std::cout << "Is Alive: " << isAlive << std::endl;
    std::cout << "Grade: " << playerGrade << std::endl;

	return 0;
}