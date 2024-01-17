#include "GuessRandy.h"
#include <iostream>
#include "Utilities.h"


namespace Games {
    
    void GuessRandys::GuessRandy(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        std::cout << "Do you want to know the rules?\n1.Yes\n2.No\n: ";
        std::cin >> myUserIn;
        if (myUserIn == 1)
        {
            std::cout << "These numbers are called Randy. You suspect at minimum one Randy is guilty. Find it and the victor shall be rewarded!\n";
        }

        while (mySann)
        {
            int randy1 = Utilities::RandomNumbers();
            int randy2 = Utilities::RandomNumbers();
            int randy3 = Utilities::RandomNumbers();
            int randy4 = Utilities::RandomNumbers();
            int randy5 = Utilities::RandomNumbers();
            int randy6 = Utilities::RandomNumbers();
            int randy7 = Utilities::RandomNumbers();
            int randy8 = Utilities::RandomNumbers();

            int rightNum = Utilities::RandomNumbers();

            if (rightNum == randy1 ||
                rightNum == randy2 || 
                rightNum == randy3 || 
                rightNum == randy4 || 
                rightNum == randy5 || 
                rightNum == randy6 || 
                rightNum == randy7 || 
                rightNum == randy8
                )
            {
                std::cout << "\nYour Money: " << cMoney << "\n";
                int bet = Utilities::Bet(cMoney, aCasino);
                std::cout << '\n';

                std::cout << randy1 << " ";
                std::cout << randy2 << " ";
                std::cout << randy3 << " ";
                std::cout << randy4 << "\n";
                std::cout << randy5 << " ";
                std::cout << randy6 << " ";
                std::cout << randy7 << " ";
                std::cout << randy8 << "\n";

                std::cout << "Your guess: ";
                std::cin >> myUserIn;

                if (myUserIn == rightNum)
                {
                    std::cout << "You WON: " << rightNum << '\n';
                    Utilities::Win(bet * 2, cMoney, myLastResults, aCasino);
                }
                else
                {
                    Utilities::Lose(myLastResults, aCasino);
                    std::cout << /*aCasino.GetName() <<*/ "Randy was: " << rightNum << '\n';
                }

                Utilities::Stats(myLastResults);
                std::cout << '\n';

                std::cout << "Do you want to play again?\n1. Yes\n2. No\n: ";
                std::cin >> myUserIn;

                if (myUserIn == 1)
                {
                    mySann = true;
                }
                else
                {
                    mySann = false;
                }
                std::cout << '\n';
            }
            else
            {
                mySann = true; //Not compatible so it redo
            }
        }
    }
}
