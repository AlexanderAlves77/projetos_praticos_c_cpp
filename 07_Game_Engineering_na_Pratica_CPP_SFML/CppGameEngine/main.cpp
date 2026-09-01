#include <iostream>

int main()
{
    const int SPRING = 1;
    const int SUMMER = 2;
    const int AUTUMN = 3;
    const int WINTER = 4;

    int currentSeason = SUMMER;

    std::cout << "=== CURRENT SEASON ===" << std::endl;

    switch (currentSeason)
    {
    case SPRING:
        std::cout << "Spring" << std::endl;
        std::cout << "Flowers begin to bloom." << std::endl;
        break;

    case SUMMER:
        std::cout << "Summer" << std::endl;
        std::cout << "Days are longer and warmer." << std::endl;
        break;

    case AUTUMN:
        std::cout << "Autumn" << std::endl;
        std::cout << "Leaves begin to fall." << std::endl;
        break;

    case WINTER:
        std::cout << "Winter" << std::endl;
        std::cout << "Cold weather reaches the farm." << std::endl;
        break;

    default:
        std::cout << "Unknown season." << std::endl;
        break;
    }


	return 0;
}