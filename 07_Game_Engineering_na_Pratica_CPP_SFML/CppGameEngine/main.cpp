#include <iostream>

int main()
{
    int day = 1;
    const int TOTAL_DAYS = 5;

    std::cout << "=== SIMULATION START ===" << std::endl;

    while (day <= TOTAL_DAYS)
    {
        std::cout << "Day " << day << std::endl;

        if (day == 3)
        {
            std::cout << "A special event happened." << std::endl;
        }

        day++;
    }

    std::cout << "Simulation finished." << std::endl;

	return 0;
}