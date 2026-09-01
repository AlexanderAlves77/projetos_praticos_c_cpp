#include <iostream>

int main()
{
    const int EXPERIENCE_REQUIRED = 100;

    int playerCoins = 30;
    int itemPrice = 50;
    int playerExperience = 80;

    std::cout << "=== PURCHASE ===" << std::endl;

    if (playerCoins >= itemPrice)
    {
        playerCoins -= itemPrice;

        std::cout << "Item purchased." << std::endl;
        std::cout << "Coins Left: " << playerCoins << std::endl;
    }
    else
    {
        int missingCoins = itemPrice - playerCoins;

        std::cout << "Not enough coins." << std::endl;
        std::cout << "Missing Coins: " << missingCoins << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== EXPERIENCE ===" << std::endl;

    if (playerExperience >= EXPERIENCE_REQUIRED)
    {
        std::cout << "Experience requirement reached." << std::endl;
    }
    else
    {
        int missingExperience = EXPERIENCE_REQUIRED - playerExperience;

        std::cout << "More experience required." << std::endl;
        std::cout << "Missing Experience: " << missingExperience << std::endl;
    }

	return 0;
}