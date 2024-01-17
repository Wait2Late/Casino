#include "NiceGame.h"
#include <iostream>
#include "Utilities.h"

namespace Games {

    void NiceGames::NiceGame(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        if (cMoney >= 10000)
        {
            myPenning == false;
            std::cout << "\n\n" << "You've earned too much and we don't trust you no more!\n";
        }
        else
        {
            myPenning = true;
        }
        if (myPenning == true)
        {
            std::cout << "Do you want to read the instructions?\n1. Yes\n2. No\n";
            std::cin >> myPlayerInput;

            if (myPlayerInput == myPlay)
            {
                std::cout << "Guess a number between 1 to 100. It will be easier with your next try! So keep on trying!\n";
            }
        }
        while (myPenning)
        {
            myPlaying = true;
            while (myPlaying)
            {
                int bet = Utilities::Bet(cMoney, aCasino);
                int hiddenNum = Utilities::ANiceGame();
                //std::cout << hiddenNum << "\n"; //Ger till spelaren det hemliga numret

                for (int i = 0; i < 5; i++)
                {
                    if (i == 4)
                    {
                        Lose(myLastResults, aCasino);
                        std::cout << "You lost\n";
                        break;
                    }

                    std::cout << "Guess the number!: ";
                    std::cin >> myGuessNum;

                    if (hiddenNum == myGuessNum)
                    {
                        Utilities::Win(bet * 2, cMoney, myLastResults, aCasino);
                        Utilities::Stats(myLastResults);
                        break;
                    }
                    else if (hiddenNum <= myGuessNum)
                    {
                        std::cout << "It's lower" << std::endl;
                    }
                    else
                    {
                        std::cout << "It's Higher" << std::endl;
                    }
                }

                //while (hiddenNum != myGuessNum) //Ska använda detta till denna uppgift
                //{
                //    if (hiddenNum <= myGuessNum)
                //    {
                //        std::cout << "It's lower" << std::endl;
                //    }
                //    else
                //    {
                //        std::cout << "It's Higher" << std::endl;
                //    }
                //    std::cin >> myGuessNum;
                //}
                //Utilities::Win(bet * 2, cMoney, myLastResults, aCasino);
                //Utilities::Stats(myLastResults);

                std::cout << "Do you want to play again?\n1. Yes\n2. No\n: ";
                std::cin >> myPlayerInput;

                if (myPlayerInput == myPlay)
                {
                    myPlaying = true;
                }
                else
                {
                    myPlaying = false;
                    myPenning = false;
                }
            }
        }

    }
}