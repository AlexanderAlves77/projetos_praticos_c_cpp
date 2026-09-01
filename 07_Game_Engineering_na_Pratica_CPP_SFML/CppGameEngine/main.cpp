#include <iostream>

enum class Season 
{
    Spring,
    Summer,
    Autumn,
    Winter
};

int main()
{
    Season currentSeason = Season::Summer;

    std::cout << "=== CURRENT SEASON ===" << std::endl;

    switch (currentSeason)
    {
    case Season::Spring:
        std::cout << "Spring" << std::endl;
        std::cout << "Flowers begin to bloom." << std::endl;
        break;

    case Season::Summer:
        std::cout << "Summer" << std::endl;
        std::cout << "Days are longer and warmer." << std::endl;
        break;

    case Season::Autumn:
        std::cout << "Autumn" << std::endl;
        std::cout << "Leaves begin to fall." << std::endl;
        break;

    case Season::Winter:
        std::cout << "Winter" << std::endl;
        std::cout << "Cold weather reaches the farm." << std::endl;
        break;

    default:
        std::cout << "Unknown season." << std::endl;
        break;
    }


	return 0;
}