#include <iostream>

int main()
{
    const int MAX_PLAYER_HEALTH = 100;

    int playerHealth = 75;
    int baseDamage = 20;
    int bonusDamage = 10;
    int criticalMultiplier = 2;
    int armor = 15;

    int rawDamage = (baseDamage + bonusDamage) * criticalMultiplier;
    int finalDamage = rawDamage - armor;

    float currentHealth = 75.0f;
    float maximumHealth = 100.0f;
    float healthPercentage = currentHealth / maximumHealth * 100.0f;

    std::cout << "=== PLAYER STATE ===" << std::endl;
    std::cout << "Health: " << playerHealth << " / " << MAX_PLAYER_HEALTH << std::endl;

    std::cout << std::endl;
    std::cout << "=== DAMAGE CALCULATION ===" << std::endl;
    std::cout << "Base Damage: " << baseDamage << std::endl;
    std::cout << "Bonus Damage: " << bonusDamage << std::endl;
    std::cout << "Critical Multiplier: " << criticalMultiplier << std::endl;
    std::cout << "Armor: " << armor << std::endl;
    std::cout << "Raw Damage: " << rawDamage << std::endl;
    std::cout << "Final Damage: " << finalDamage << std::endl;

    std::cout << std::endl;
    std::cout << "=== HEALTH CALCULATION ===" << std::endl;
    std::cout << "Health Percentage: " << healthPercentage << "%" << std::endl;

	return 0;
}