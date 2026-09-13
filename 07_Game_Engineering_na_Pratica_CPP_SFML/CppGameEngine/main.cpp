#include <iostream>
#include <string>

int main()
{
    const int SCORE_COUNT = 5;
    const int ITEM_COUNT = 3;

    int scores[SCORE_COUNT] =
    {
        100,
        200,
        150,
        300,
        250
    };

    std::string items[ITEM_COUNT] =
    {
        "Sword",
        "Shield",
        "Potion"
    };

    std::cout << "=== SCORES ===" << std::endl;

    int totalScore = 0;
    int highestScore = scores[0];

    for (int index = 0; index < SCORE_COUNT; index++)
    {
        std::cout << "Score [" << index << "]: " << scores[index] << std::endl;

        totalScore += scores[index];

        if (scores[index] > highestScore)
        {
            highestScore = scores[index];
        }
    }

    int averageScore = totalScore / SCORE_COUNT;

    std::cout << std::endl;
    std::cout << "Total Score: " << totalScore << std::endl;
    std::cout << "Average Score: " << averageScore << std::endl;
    std::cout << "Highest Score: " << highestScore << std::endl;
    std::cout << std::endl;
    std::cout << "=== ITEMS ===" << std::endl;

    for (int index = 0; index < ITEM_COUNT; index++)
    {
        std::cout << "Item [" << index << "]: " << items[index] << std::endl;
    }

    return 0;
}