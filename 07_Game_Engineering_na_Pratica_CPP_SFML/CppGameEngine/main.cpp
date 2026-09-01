#include <iostream>

int main()
{
    const int MAX_PLAYER_HEALTH = 100;
    const int MAX_INVENTORY_SLOTS = 20;
    const float DEFAULT_PLAYER_SPEED = 4.5f;

    int playerHealth = MAX_PLAYER_HEALTH;
    int inventorySlotsUsed = 5;
    float playerSpeed = DEFAULT_PLAYER_SPEED;

    std::cout << "=== GAME RULES ===" << std::endl;
    std::cout << "Maximum Health: " << MAX_PLAYER_HEALTH << std::endl;
    std::cout << "Maximum Inventory Slots: " << MAX_INVENTORY_SLOTS << std::endl;
    std::cout << "Default Player Speed: " << DEFAULT_PLAYER_SPEED << std::endl;

    std::cout << std::endl;

    std::cout << "=== PLAYER STATE ===" << std::endl;
    std::cout << "Current Health: " << playerHealth << std::endl;
    std::cout << "Inventory Used: " << inventorySlotsUsed << std::endl;
    std::cout << "Current Speed: " << playerSpeed << std::endl;

    playerHealth = playerHealth - 20;
    inventorySlotsUsed = inventorySlotsUsed + 1;

    std::cout << std::endl;

    std::cout << "=== UPDATED PLAYER STATE ===" << std::endl;
    std::cout << "Current Health: " << playerHealth << std::endl;
    std::cout << "Inventory Used: " << inventorySlotsUsed << std::endl;
    std::cout << "Current Speed: " << playerSpeed << std::endl;

	return 0;
}