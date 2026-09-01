#include <iostream>

int main()
{
    const int MAX_PLAYER_HEALTH = 100;
    const int EXPERIENCE_PER_LEVEL = 100;

    int playerHealth = MAX_PLAYER_HEALTH;
    int playerCoins = 25;
    int playerExperience = 40;
    int playerLevel = 1;
    int baseDamage = 15;
    int criticalMultiplier = 2;

    std::cout << "=== INITIAL STATE ===" << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Experience: " << playerExperience << std::endl;
    std::cout << "Level: " << playerLevel << std::endl;

    int criticalDamage = baseDamage * criticalMultiplier;

    playerHealth -= criticalDamage;
    playerCoins += 20;
    playerExperience += 160;

    int completedLevels = playerExperience / EXPERIENCE_PER_LEVEL;
    int remainingExperience = playerExperience % EXPERIENCE_PER_LEVEL;

    std::cout << std::endl;
    std::cout << "=== AFTER GAMEPLAY EVENTS ===" << std::endl;
    std::cout << "Critical Damage: " << criticalDamage << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
    std::cout << "Total Experience: " << playerExperience << std::endl;
    std::cout << "Completed Level Units: " << completedLevels << std::endl;
    std::cout << "Remaining Experience: " << remainingExperience << std::endl;

	return 0;
}