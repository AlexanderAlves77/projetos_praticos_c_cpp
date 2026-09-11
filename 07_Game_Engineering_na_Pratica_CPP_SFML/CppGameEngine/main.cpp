#include <iostream>
#include <string>

std::string BuildGreeting(std::string playerName);
void ShowDialogue(std::string speakerName, std::string dialogue);
void ShowPlayerInfo(std::string playerName, std::string locationName, int playerHealth, int playerCoins);

int main()
{
    std::string playerName = "Alex";
    std::string npcName = "Guard";
    std::string locationName = "Initial Forest";
    std::string dialogue = "Welcome to the Initial Forest.";

    int playerHealth = 100;
    int playerCoins = 25;

    std::string greeting = BuildGreeting(playerName);
    std::cout << "=== GAME TEXT DATA ===" << std::endl;
    std::cout << greeting << std::endl;
    std::cout << std::endl;

    ShowPlayerInfo(playerName, locationName, playerHealth, playerCoins);
    std::cout << std::endl;

    ShowDialogue(npcName, dialogue);
    std::cout << std::endl;

    std::cout << "Player Name Length: " << playerName.size() << std::endl;

    if (playerName.empty())
    {
        std::cout << "Player name is empty." << std::endl;
    }
    else
    {
        std::cout << "Player name is valid for this example." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Characters:" << std::endl;

    for (std::size_t index = 0; index < playerName.size(); index++)
    {
        std::cout << index << ": " << playerName[index] << std::endl;
    }

    return 0;
}

std::string BuildGreeting(std::string playerName)
{
    return "Welcome, " + playerName + "!";
}

void ShowDialogue(std::string speakerName, std::string dialogue)
{
    std::cout << speakerName << ": " << dialogue << std::endl;
}

void ShowPlayerInfo(std::string playerName, std::string locationName, int playerHealth, int playerCoins)
{
    std::cout << "Player: " << playerName << std::endl;
    std::cout << "Location: " << locationName << std::endl;
    std::cout << "Health: " << playerHealth << std::endl;
    std::cout << "Coins: " << playerCoins << std::endl;
}