#include <random>
#include <string>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <array>
#include "Utilities.h"
#include "Casino 6.h"


namespace Utilities {
    //std::array<Utilities::eGameResult, 5>& myLastResults

    int Lobby(int& aMoney, const Casino& aCasino)
    {
        std::cout << "Your Money: " << aMoney << "\n\n";
        std::cout << "Hello " << aCasino.GetName() << " and welcome to our casino!\n";
        std::cout << "What do you want to do?\n";
        std::cout << "1. Play guess the dices with low stakes\n";
        std::cout << "2. Play guess the dices with high stakes\n";
        std::cout << "3. Play guess odd or even\n";
        std::cout << "4. A nice game for everyone!\n"; 
        std::cout << "5. Guess the Randy\n";
        std::cout << "6. Roulette\n";
        std::cout << "7. stats\n";
        std::cout << "8. Quit\n";

        return aMoney;
    }

    int NumberInput(const int aMinValue, const int aMaxValue, const std::string& aMessage, const Casino& aCasino)
    {
        if (aMinValue > aMaxValue)
        {
            std::cout << aCasino.GetName() << " Wrong!!" << std::endl;
        }

        int choice = -1;

        while (true)
        {
            std::cout << aMessage << std::endl;
            std::cin >> choice;
            if (std::cin.fail() == true || choice < aMinValue || choice > aMaxValue)
            {
                std::cout << aCasino.GetName() << " You must enter a number between " << aMinValue << " to " << aMaxValue << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
            else
            {
                return choice;
            }
        }

        return -1;
    }

    int Bet(int& aPlayerMoney, const Casino& aCasino)
    {
        int bet = NumberInput(1, aPlayerMoney, "How much money do you want to bet? ", aCasino);
        if (bet == aPlayerMoney)
        {
            std::cout << aCasino.GetName() << " Daring bravely! Well, it's yours truly..." << std::endl;
        }

        aPlayerMoney -= bet;

        return bet;
    }

    int GuessDiceStake(int& aPlayerMoney, const int aMinBet, const int aMaxBet, const Casino& aCasino)
    {
        int maxBet = 0;
        if (aMaxBet > aPlayerMoney)
        {
            maxBet = aPlayerMoney;
        }
        else
        {
            maxBet = aMaxBet;
        }
        std::cout << "\nMoney: " << aPlayerMoney << std::endl;

        int bet = NumberInput(aMinBet, maxBet, "How much money do you want to bet? ", aCasino);
        if (bet == aPlayerMoney)
        {
            std::cout << "Wow! " << aCasino.GetName() << " Going all in. It's your money..." << std::endl;
        }
        aPlayerMoney -= bet;

        return bet;
    }

    void uStats(const Utilities::eGameResult aOutCome, std::array<eGameResult, 5>& myLastResults)
    {
        for (size_t outcomeIndex = myLastResults.size() - 1; outcomeIndex > 0; --outcomeIndex)
        {
            myLastResults[outcomeIndex] = myLastResults[outcomeIndex - 1];
        }

        myLastResults[0] = aOutCome;
    }

    void Win(int aMoneys, int& ref, std::array<eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        if (aMoneys < 1)
        {
            std::cout << "ERROR! " << aCasino.GetName() << " won 0 or less!";
        }
        uStats(eGameResult::WIN, myLastResults);

        std::cout << "Gz! " << aCasino.GetName() << " You won " << aMoneys << " moneys!" << std::endl;

        ref += aMoneys;
    }

    void Lose(std::array<eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        std::cout << aCasino.GetName() << " lost big time!\n";
        uStats(eGameResult::LOSE, myLastResults);
    }

    void Stats(const std::array<eGameResult, 5>& myLastResults)
    {
        std::cout << "Gambling history" << std::endl;
        std::cout << "----------------" << std::endl;

        for (size_t outcomeIndex = 0; outcomeIndex < myLastResults.size(); ++outcomeIndex)
        {
            switch (myLastResults[outcomeIndex])
            {
            case eGameResult::WIN:
                std::cout << "WON" << std::endl;
                break;
            case eGameResult::LOSE:
                std::cout << "LOST" << std::endl;
                break;
            default:
                std::cout << std::endl;
            }
        }
        std::cout << "----------------" << std::endl;
    }


    int GuessNum()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 5);
        return dist(rng);
    }
    int GuessOddOrEven()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);
        return dist(rng);
    }
    int ANiceGame()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);
        return dist(rng);
    }
    int RandomNumbers()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 8);
        return dist(rng);
    }
    int RouletteNumber()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 36);
        return dist(rng);
    }

    void GameBoard()
    {
        std::cout << "\n";
        std::cout << " __________________________________ \n";
        std::cout << "| |3 6 9 12|15 18 21 24|27 30 33 36|\n";
        std::cout << "|0|2 5 8 11|14 17 20 23|26 29 32 35|\n";
        std::cout << "| |1 4 7 10|13 16 19 22|25 28 31 34|\n";
        std::cout << "|_|________________________________|\n";
        std::cout << "\n";
    }
    void StreetTripleGameBoard()
    {
        std::cout << "\n";
        std::cout << " __________________________________ \n";
        std::cout << "| |3 6 9 12|15 18 21 24|27 30 33 36|\n";
        std::cout << "|0|2 5 8 11|14 17 20 23|26 29 32 35|\n";
        std::cout << "| |1 4 7 10|13 16 19 22|25 28 31 34|\n";
        std::cout << "|_|________________________________|\n";
        std::cout << "   1 2 3 4  5  6  7  8  9  10 11 12 <- Lines\n";
        std::cout << "\n";
    }
    void CornerFourGameBoard()
    {
        std::cout << " ____________________________________________________________ \n";
        std::cout << "|3 6|6 9|9 12|12 15|15 18|18 21|21 24|24 27|27 30|30 33|33 36|\n";
        std::cout << "|2 5|5 8|8 11|11 14|14 17|17 20|20 23|23 26|26 29|29 32|32 35|\n";
        std::cout << "|___|___|____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
        std::cout << "|1  |2  |3   |4    |5    |6    |7    |8    |9    |10   |11    \n\n";

        std::cout << " ____________________________________________________________ \n";
        std::cout << "|2 5|5 8|8 11|11 14|14 17|17 20|20 23|23 26|26 29|29 32|32 35|\n";
        std::cout << "|1 4|4 7|7 10|10 13|13 16|16 19|19 22|22 25|25 28|28 31|31 34|\n";
        std::cout << "|___|___|____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
        std::cout << "|12 |13 |14  |15   |16   |17   |18   |19   |20   |21   |22   |\n\n";
    }
    void LineGameBoard()
    {
        std::cout << "\n";
        std::cout << " __________________________________ \n";
        std::cout << "| |3 6 9 12|15 18 21 24|27 30 33 36|\n";
        std::cout << "|0|2 5 8 11|14 17 20 23|26 29 32 35|\n";
        std::cout << "| |1 4 7 10|13 16 19 22|25 28 31 34|\n";
        std::cout << "| | | | |  |  |  |  |  |  |  |  |  |\n";
        std::cout << "| | 1 2 3  4  5  6  7  8  9  10 11 <- Lines\n";
        std::cout << "|_|________________________________|\n";
        std::cout << "\n";
    }
    void ColumnGameBoard()
    {
        std::cout << "\n";
        std::cout << " __________________________________ \n";
        std::cout << "| |3 6 9 12|15 18 21 24|27 30 33 36|<- Column 3\n";
        std::cout << "|0|2 5 8 11|14 17 20 23|26 29 32 35|<- Column 2\n";
        std::cout << "| |1 4 7 10|13 16 19 22|25 28 31 34|<- Column 1\n";
        std::cout << "|__________________________________|\n";
        std::cout << "\n";
    }
    void DozenGameBoard()
    {
        std::cout << "\n";
        std::cout << " __________________________________ \n";
        std::cout << "| |3 6 9 12|15 18 21 24|27 30 33 36|\n";
        std::cout << "|0|2 5 8 11|14 17 20 23|26 29 32 35|\n";
        std::cout << "| |1 4 7 10|13 16 19 22|25 28 31 34|\n";
        std::cout << "|__________________________________|\n";
        std::cout << "| |Dozen 1 |Dozen 2    |Dozen 3    |\n";
        std::cout << "\n";
    }
    void LowBoard()
    {
        std::cout << "\n";
        std::cout << " ________________ \n";
        std::cout << "| |3 6 9 12 15 18|\n";
        std::cout << "|0|2 5 8 11 14 17|\n";
        std::cout << "| |1 4 7 10 13 16|\n";
        std::cout << "|_|______________|\n";
        std::cout << "|Low             |\n";
        std::cout << "|________________|\n";
        std::cout << "\n";
    }
    void HighBoard()
    {
        std::cout << "\n";
        std::cout << " ___________________ \n";
        std::cout << "| |21 24 27 30 33 36|\n";
        std::cout << "|0|20 23 26 29 32 35|\n";
        std::cout << "| |19 22 25 28 31 34|\n";
        std::cout << "|_|_________________|\n";
        std::cout << "|High               |\n";
        std::cout << "|___________________|\n";
        std::cout << "\n";
    }
    void RedAndBlackNumbers()
    {
        std::cout << "\n";
        std::cout << "Numbers that are red\n";
        std::cout << "1 3 5 7 9 12 14 16 18 19 21 23 25 27 30 32 34 36\n\n";

        std::cout << "Numbers that are black\n";
        std::cout << "2 4 6 8 10 11 13 15 17 20 22 24 26 28 29 31 33 35\n\n";
    }


    void Roulette(const int param[], const int randy, const int length, std::array<eGameResult, 5>& myLastResults, const int aMoneys, int& ref, const Casino& aCasino)
    {
        bool valid = false;
        for (int i = 0; i < length; i++)
        {
            if (randy == param[i])
            {
                std::cout << "\n" << aCasino.GetName() <<" You won!\n";
                valid = true;
                std::cout << "Randy is: " << randy << "\n";
                Win(aMoneys, ref, myLastResults, aCasino);
            }
        }
        if (valid == false)
        {
            std::cout << aCasino.GetName() << " You lost\n";
            std::cout << "Randy is: " << randy << "\n";
            uStats(eGameResult::LOSE, myLastResults);
        }
    }
}