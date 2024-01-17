#include "GuessDice.h"
#include <iostream>
#include "Utilities.h"
#include "Casino 6.h"

namespace Games {

    void GuessDices::GuessDice(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const int aMinValue, const int aMaxValue, const Casino& aCasino)
    {

        std::cout << "Your Money: " << cMoney << std::endl << std::endl;
        
        if (cMoney >= 400)
        {
            myPenning = false;

            std::cout << "\n\nyou've earned too much and don't trust you no more!\n";
        }
        else
        {
            myPenning = true;
        }
        if (myPenning == true)
        {
            std::cout << "do you want to read the instructions?\n1. yes\n2. no\n";
            std::cin >> myPlayerInput;

            if (myPlayerInput == myPlay)
            {
                std::cout << "guess a number between one to five! \n\nthe earn rate is triple times the count\n\n";
            }
        }

        while (myPenning)
        {
            myPlaying = true;
            while (myPlaying)
            {
                std::cout << aCasino.GetName() <<" Your minimum bet is: " << aMinValue;
                std::cout << "\nand your maximum bet is: " << aMaxValue;
                int bet = Utilities::GuessDiceStake(cMoney, aMinValue, aMaxValue, aCasino);
                int hiddenNum = Utilities::GuessNum();

                std::cout << "\nGuess the number!: ";
                std::cin >> myGuessNum;

                if (myGuessNum != hiddenNum)
                {
                    Lose(myLastResults, aCasino);
                }
                else
                {
                    Utilities::Win(bet * 3, cMoney, myLastResults, aCasino);
                }
                std::cout << "Hidden number is: " << hiddenNum << "\n";
                std::cout << '\n';
                Utilities::Stats(myLastResults);
                std::cout << '\n';

                std::cout << aCasino.GetName() <<" do you want to play again?\n1. Yes\n2. No\n: ";
                std::cin >> myPlayerInput;

                if (myPlayerInput == myPlay)
                {
                    myPlaying = true;

                    if (cMoney <= 0)
                    {
                        std::cout << "\n\n" << aCasino.GetName() <<" you are out of money!\nYou're no longer welcome no more\n";
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    myPenning = false;
                    myPlaying = false;
                }
            }
        }
    }
}

