#include "OddOrEven.h"
#include <iostream>
#include "Utilities.h"
#include "Casino 6.h"

namespace Games {
    
    void OddOrEvens::OddOrEven(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        //Casino casino;
        std::cout << "Your Money: " << cMoney << std::endl << std::endl;

        if (cMoney >= 900) 
        {
            std::cout << "\n\n" << aCasino.GetName() << " you've earned too much and don't trust you no more!\n";
            myPenning = false;
        }
        else
        {
            myPenning = true;
        }

        if (myPenning == true)
        {
            std::cout << aCasino.GetName() << " Do you want to read the instructions?\n1. Yes\n2. No\n";
            std::cin >> myPlayerInput;

            if (myPlayerInput == myPlay)
            {
                std::cout << aCasino.GetName() << " Guess an odd or even. If guessed correctly you win! If not you lose and if one dice is either even AND odd you lose aswell\n\n";
            }
        }
        while (myPenning)
        {
            myPlaying = true;
            while (myPlaying)
            {
                std::cout << "\n" << aCasino.GetName() << " Your Money: " << cMoney << std::endl << std::endl;
                int bet = Utilities::Bet(cMoney, aCasino);

                std::cout << aCasino.GetName() << " Guess? \n1. odd \nor \n2. even?: ";
                std::cin >> myPlayerInput;

                myGuessOddOrEven1;
                myGuessOddOrEven2;

                if (myPlayerInput == myEven) //0 == even
                {
                    if (myGuessOddOrEven1 == 0 && myGuessOddOrEven2 == 0)
                    {
                        std::cout << "Both dices showed even!\n" << std::endl;
                        Utilities::Win(bet * 2, cMoney, myLastResults, aCasino);
                    }
                    else if (myGuessOddOrEven1 != 0 && myGuessOddOrEven2 != 0)
                    {
                        Lose(myLastResults, aCasino);
                        std::cout << aCasino.GetName() << " Both dices showed odd!\n\n";
                    }
                    else
                    {
                        Lose(myLastResults, aCasino);
                        std::cout << aCasino.GetName() << " One dice was odd and the other even!" << std::endl;
                    }
                }
                if (myPlayerInput == myOdd) // 1 == odd
                {
                    if (myGuessOddOrEven1 != 0 && myGuessOddOrEven2 != 0)
                    {
                        std::cout << "Both dices showed odd!\n\n";
                        Utilities::Win(bet * 2, cMoney, myLastResults, aCasino);
                    }
                    else if (myGuessOddOrEven1 == 0 && myGuessOddOrEven2 == 0)
                    {
                        Lose(myLastResults, aCasino);
                        std::cout << aCasino.GetName() << " Both dices showed even!\n\n";
                    }
                    else
                    {
                        Lose(myLastResults, aCasino);
                        std::cout << aCasino.GetName() << " One dice was odd and the other even!" << std::endl;
                    }
                }
                std::cout << '\n';

                Utilities::Stats(myLastResults);

                if (cMoney == 0)
                {
                    std::cout << "\n\n" << aCasino.GetName() << " You no longer have any more money and no longer welcome to our fine established Casino!\n";
                    exit(EXIT_FAILURE);
                }
                std::cout << aCasino.GetName() << " Do you want to play again?\n1. Yes\n2. No\n: ";
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