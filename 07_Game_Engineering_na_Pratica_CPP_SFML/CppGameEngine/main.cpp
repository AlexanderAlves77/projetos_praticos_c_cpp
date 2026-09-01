#include <iostream>

int main()
{
    const int EXPERIENCE_REQUIRED = 100;

    int playerHealth = 30;
    int damage = 50;
    int playerCoins = 80;
    int itemPrice = 50;
    int playerExperience = 120;

    std::cout << "=== INITIAL STATE ===" << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Experience: " << playerExperience << std::endl;

    int newHealth = playerHealth - damage;

    if (newHealth < 0)
    {
        newHealth = 0;
    }

    playerHealth = newHealth;

    if (playerHealth <= 0)
    {
        std::cout << std::endl;
        std::cout << "Player defeated." << std::endl;
    }

    if (playerCoins >= itemPrice)
    {
        playerCoins -= itemPrice;

        std::cout << "Item purchased." << std::endl;
    }

    if (playerExperience >= EXPERIENCE_REQUIRED)
    {
        std::cout << "Experience requirement reached." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== CURRENT STATE ===" << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Experience: " << playerExperience << std::endl;

	return 0;
}