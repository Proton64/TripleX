#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Printing out Strings
    if (Difficulty == 1)
    {
        std::cout << "________  _______   ___  ___  ________  ___      ___ ___  ________  ___  ___  ________          ___  ________   _________  _______   ________  ________  ________ _________  ___  ___      ___ _______      " << std::endl;
        std::cout << "|\\   __  \\|\\  ___ \\ |\\  \\|\\  \\|\\   __  \\|\\  \\    /  /|\\  \\|\\   __  \\|\\  \\|\\  \\|\\   __  \\        |\\  \\|\\   ___  \\|\\___   ___\\\\  ___ \\ |\\   __  \\|\\  __  \\|\\   ____\\\\___   ___\\\\  \\|\\  \\    /  /|\\  ___ \\     " << std::endl;
        std::cout << "\\ \\  \\|\\ /\\ \\   __/|\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\  /  / | \\  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\       \\ \\  \\ \\  \\ \\  \\|___ \\  \\_\\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___\\|___ \\  \\_\\ \\  \\ \\  \\  /  / | \\   __/|    " << std::endl;
        std::cout << " \\ \\   __  \\ \\  \\_|/_\\ \\   __  \\ \\   __  \\ \\  \\/  / / \\ \\  \\ \\  \\\\\\  \\ \\  \\\\  \\ \\   _  _\\       \\ \\  \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\_|/_\\ \\   _  _\\ \\   __  \\ \\  \\       \\ \\  \\ \\ \\  \\ \\  \\/  / / \\ \\  \\_|/__  " << std::endl;
        std::cout << "  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\  \\ \\  \\ \\  \\ \\  \\ \\    / /   \\ \\  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\\\  \\|       \\ \\  \\ \\  \\\\ \\  \\   \\ \\  \\ \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\____   \\ \\  \\ \\ \\  \\ \\    / /   \\ \\  \\_|\\ \\ " << std::endl;
        std::cout << "   \\ \\_______\\ \\_______\\ \\__\\ \\__\\ \\__\\ \\__\\ \\__/ /     \\ \\__\\ \\_______\\ \\_______\\ \\__\\\\ _\\        \\ \\__\\ \\__\\\\ \\__\\   \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\_______\\  \\ \\__\\ \\ \\__\\ \\__/ /     \\ \\_______\\" << std::endl;
        std::cout << "    \\|_______|\\|_______|\\|__|\\|__|\\|__|\\|__|\\|__|/       \\|__|\\|_______|\\|_______|\\|__|\\|__|        \\|__|\\|__| \\|__|    \\|__|  \\|_______|\\|__|\\|__|\\|__|\\|__|\\|_______|   \\|__|  \\|__|\\|__|/       \\|_______|" << std::endl;
        std::cout << "\nYou are a hackerman trying to find out more info about the Residen Evil chapter for Dead by Daylight." << std::endl;
    }
    std::cout << "Your current access level is: " << Difficulty << std::endl;
    std::cout << "You need to enter the correct passwords to get further access...\n" << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Defining new integers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    // Defining integers that are additions / multiplications of the previous integers
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Printing out the integers
    std::cout << "- There are 3 numbers in the password" << std::endl;
    std::cout << "- The numbers add-up to: " << CodeSum << std::endl;
    std::cout << "- The numbers mutliply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Message for true / false guess
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\nC:\\System\\BHVR\\access" << Difficulty << ".key found!" << std::endl;
        if (Difficulty != 5)
        {
            std::cout << "\nAccessing the next sublevel..." << std::endl;
        }
        else
        {
            std::cout << "\nExtracting String from Server..." << std::endl;
        }
        return true;
    }
    else
    {
        std::cout << "\nYou failed! Oh no :(" << std::endl;
        std::cout << "\nClearing BHVR Modem and all false attempts..." << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears anny errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }
    std::cout << "\nYou cracked into the buggy system, congratulations!" << std::endl;
    std::cout << "The Servers gave you this encrypted string:" << std::endl;
    std::cout << "aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1kUXc0dzlXZ1hjUQ==" << std::endl;
    std::cout << "\nExiting Linux KVM and resseting BHVR Access Modem..." << std::endl;
    std::cout << "\nC:\\Sys64\\kvmwin64 --stopallbhvrmodems" << std::endl;
    std::cout << "\nStopped all BHVR modems!" << std::endl;

    // Stopping the execution
    return 0;
}