#include <iostream>
#include "Utilities.h"
#include "Casino 6.h"

void Casino::EnterLobby()
{
    while (myPlayingCasino)
    {
        Utilities::Lobby(myHundred, *this);
        std::cin >> myLobbyChoice;
        std::array<Utilities::eGameResult, 5> myLastResults;

        switch (static_cast<eLobbyChoice>(myLobbyChoice))
        {
        case eLobbyChoice::eGuessDiceLowStakes:objGuessDiceLowStakes.GuessDice(myHundred, myLastResults, 1, 30, *this); break;
        case eLobbyChoice::eGuessDiceHighStakes:objGuessDiceHighStakes.GuessDice(myHundred, myLastResults, 31, 100, *this); break;
        case eLobbyChoice::eOddOrEven:objOddOrEven.OddOrEven(myHundred, myLastResults, *this); break;
        case eLobbyChoice::eNiceGame:objNiceGame.NiceGame(myHundred, myLastResults, *this); break;
        case eLobbyChoice::eGuessRandy:objGuessRandy.GuessRandy(myHundred, myLastResults, *this); break;
        case eLobbyChoice::eRoulette:objRoullete.RouletteGame(myHundred, myLastResults, *this); break;
        case eLobbyChoice::eStatistics:Utilities::Stats(myLastResults); break;
        case eLobbyChoice::quit:std::cout << "You're welcome to return!\nYou left with this much money: " << myHundred << " money\n";
            myPlayingCasino = false; break;
        default: std::cout << "To play try betwwen 1-5!\n\n"; break;
        }
    }
}

Casino::Casino() 
{
    myName = "Default";
}

void Casino::ChooseYourName()
{
    std::cout << "Enter your Name: ";
    std::cin >> myName;
    while (IFValidName(myName) == false)
    {
        std::cout << "\nEnter your Name again: ";
        std::cin >> myName;
    }
}

void Casino::SetName(std::string aName) 
{
    myName = aName;
}
const std::string& Casino::GetName() const 
{
    return myName;
}

bool Casino::IFValidName(const std::string& aName)const 
{
    if (aName.size() < 2)
    {
        std::cout << "\nRedo your name. Needs to be more than 2 letters!\n";
        return false;
    }
    for (int i = 0; i < aName.size(); i++)
    {
        if (std::isalpha(aName[i] == false))
        {
            std::cout << "\nOnly alphabetic characters are legitmate, try again!\n";
            return false;
        }
    }
}