#include <iostream>

int main()
{
    const int TOTAL_DAYS = 5;
    const int RESOURCES_PER_DAY = 3;

    int totalResources = 0;

    std::cout << "=== SIMULATION START ===" << std::endl;

    for (int day = 1; day <= TOTAL_DAYS; day++)
    {
        totalResources += RESOURCES_PER_DAY;

        std::cout << "Day " << day << std::endl;
        std::cout << "Resources Produced Today: " << RESOURCES_PER_DAY << std::endl;
        std::cout << "Total Resources: " << totalResources << std::endl;

        if (day == 3)
        {
            std::cout << "A special event happened." << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Simulation finished." << std::endl;
    std::cout << "Final Resources: " << totalResources << std::endl;

	return 0;
}