#include <array>
#include <iostream>
#include <string>

void ShowScores(std::array<int, 5> scores);
int FindHighestScore(std::array<int, 5> scores);
int CalculateTotalScore(std::array<int, 5> scores);
void ShowTools(std::array<std::string, 4> toolNames);

int main()
{
    std::string playerName = "Alexander";
    std::array<int, 5> scores =
    {
        100,
        200,
        150,
        300,
        250
    };

    std::array<std::string, 4> toolNames =
    {
        "Axe",
        "Pickaxe",
        "Hoe",
        "Watering Can"
    };

    std::cout << "=== PLAYER ===" << std::endl;
    std::cout << "Name: " << playerName << std::endl;
    std::cout << std::endl;

    std::cout << "=== ARRAY INFORMATION ===" << std::endl;
    std::cout << "Score Count: " << scores.size() << std::endl;
    std::cout << "First Score: " << scores.front() << std::endl;
    std::cout << "Last Score: " << scores.back() << std::endl;
    std::cout << std::endl;

    ShowScores(scores);

    int totalScore = CalculateTotalScore(scores);
    int highestScore = FindHighestScore(scores);

    std::cout << std::endl;
    std::cout << "Total Score: " << totalScore << std::endl;
    std::cout << "Highest Score: " << highestScore << std::endl;
    std::cout << std::endl;

    ShowTools(toolNames);

    return 0;
}

void ShowScores(std::array<int, 5> scores)
{
    std::cout << "=== SCORES ===" << std::endl;

    for (std::size_t index = 0; index < scores.size(); index++)
    {
        std::cout
            << "Score ["
            << index
            << "]: "
            << scores[index]
            << std::endl;
    }
}

int CalculateTotalScore(std::array<int, 5> scores)
{
    int totalScore = 0;

    for (int score : scores)
    {
        totalScore += score;
    }

    return totalScore;
}

int FindHighestScore(std::array<int, 5> scores)
{
    int highestScore = scores.front();

    for (int score : scores)
    {
        if (score > highestScore)
        {
            highestScore = score;
        }
    }

    return highestScore;
}

void ShowTools(std::array<std::string, 4> toolNames)
{
    std::cout << "=== TOOLS ===" << std::endl;
    for (std::string toolName : toolNames)
    {
        std::cout << toolName << std::endl;
    }
}