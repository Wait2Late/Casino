#include "Roullete.h"
#include "Utilities.h"
#include <iostream>

namespace Games {

    void Roullete::RouletteGame(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino)
    {
        std::cout << "--Roulette--\n";
        std::cout << "Where do you want to place to your designated choice?\n";
        std::cout << "1. Inside Bet\n2. Outside Bet\n: ";
        std::cin >> userIn;
        std::cout << "\n";
        int boardNum = Utilities::RouletteNumber();

        if (userIn == insideBet) //Inside
        {
            std::cout << "Welcome to inside!\n";
            std::cout << "Choose between \n1. Straight Up\n2. Split\n3. Street Triple\n4. Corner Four\n5. Line\n";
            std::cin >> userIn;

            int bet = Utilities::Bet(cMoney, aCasino);

            switch (static_cast<Utilities::eInsideBet>(userIn))
            {
            case  Utilities::eInsideBet::eStraightUp://---------------------------------------------------------Straight
                std::cout << "-Straight Up-\n";
                Utilities::GameBoard();
                std::cout << "Place your choice in any singular number, 1 - 36: ";
                //std::cout << "\n" << boardNum << "\n"; //Secret number
                std::cin >> userIn;

                if (boardNum == loserZero)
                {
                    Lose(myLastResults, aCasino);
                    std::cout << "Board Number is: " << boardNum;
                    std::cout << "\n";
                }
                else if (userIn == boardNum)
                {
                    std::cout << "You won huge!\n";
                    Utilities::Win(bet * 36, cMoney, myLastResults, aCasino);
                }
                else
                {
                    std::cout << "\n";
                    Lose(myLastResults, aCasino);
                    std::cout << "Board Number is: " << boardNum;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case  Utilities::eInsideBet::eSplit://------------------------------------------------------------------------Split
                std::cout << "-Split-\n";
                sann = true;
                while (sann)
                {
                    Utilities::GameBoard();
                    //std::cout << boardNum << "\n"; //Secret number
                    std::cout << "Place your choice between two numbers next to each other, 1 - 36\n";
                    std::cout << "Your first number: ";
                    std::cin >> userIn;
                    std::cout << "Your second number: ";
                    std::cin >> userIn2;
                    std::cout << "\n";

                    if (userIn - userIn2 == 3 || userIn2 - userIn == 3 || userIn - userIn2 == 1 || userIn2 - userIn == 1)
                    {
                        if (userIn == 12 && userIn2 == 13 || userIn2 == 12 && userIn == 13 || userIn == 24 && userIn2 == 25 || userIn2 == 24 && userIn == 25)
                        {
                            std::cout << "Not valid, try again\n";
                            sann;
                        }
                        else if (boardNum == loserZero)
                        {
                            Lose(myLastResults, aCasino);
                            std::cout << "Board number is: " << boardNum;
                            sann = false;
                            std::cout << "\n";
                        }
                        else if (userIn == boardNum || userIn2 == boardNum)
                        {
                            std::cout << "You won!";
                            std::cout << "Board number is: " << boardNum;
                            Utilities::Win(bet * 18, cMoney, myLastResults, aCasino);
                            sann = false;
                        }
                        else
                        {
                            Lose(myLastResults, aCasino);
                            std::cout << "Board number is: " << boardNum;
                            std::cout << "\n";
                            sann = false;
                        }
                    }
                    else
                    {
                        std::cout << "Not valid, try again\n";
                        sann;
                    }
                    Utilities::Stats(myLastResults);
                    std::cout << '\n';
                }
                break;
            case  Utilities::eInsideBet::eStreetTriple://-------------------------------------------------------------------Street Triple
                std::cout << "-Street Triple-\n";
                //std::cout << "\n" << boardNum << "\n";

                sann = true;
                while (sann)
                {
                    Utilities::StreetTripleGameBoard();
                    std::cout << "Place your choice between lines 1-12 \n"; //Example later
                    std::cout << "Line: ";
                    std::cin >> userIn;

                    switch (userIn)
                    {
                    case  1:Utilities::Roulette(line01, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  2:Utilities::Roulette(line02, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  3:Utilities::Roulette(line03, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  4:Utilities::Roulette(line04, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  5:Utilities::Roulette(line05, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  6:Utilities::Roulette(line06, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  7:Utilities::Roulette(line07, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  8:Utilities::Roulette(line08, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case  9:Utilities::Roulette(line09, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case 10:Utilities::Roulette(line10, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case 11:Utilities::Roulette(line11, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    case 12:Utilities::Roulette(line12, boardNum, 3, myLastResults, bet * 12, cMoney, aCasino); break;
                    default: std::cout << "\n\n-Please try again between lines 1-12!-\n\n"; break;
                    }
                    sann = false;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case  Utilities::eInsideBet::eCornerFour://------------------------------------------------------------------------------Corner Four
                std::cout << "-Corner Four-\n";
                //std::cout << "\n" << boardNum << "\n";

                sann = true;
                while (sann)
                {
                    Utilities::CornerFourGameBoard();
                    std::cout << "Choose a combination between of four numbers, 1-22: ";
                    std::cin >> userIn;

                    switch (userIn)
                    {
                    case  1:Utilities::Roulette(comb01, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  2:Utilities::Roulette(comb02, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  3:Utilities::Roulette(comb03, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  4:Utilities::Roulette(comb04, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  5:Utilities::Roulette(comb05, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  6:Utilities::Roulette(comb06, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  7:Utilities::Roulette(comb07, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  8:Utilities::Roulette(comb08, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case  9:Utilities::Roulette(comb09, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 10:Utilities::Roulette(comb10, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 11:Utilities::Roulette(comb11, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 12:Utilities::Roulette(comb12, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 13:Utilities::Roulette(comb13, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 14:Utilities::Roulette(comb14, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 15:Utilities::Roulette(comb15, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 16:Utilities::Roulette(comb16, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 17:Utilities::Roulette(comb17, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 18:Utilities::Roulette(comb18, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 19:Utilities::Roulette(comb19, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 20:Utilities::Roulette(comb20, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 21:Utilities::Roulette(comb21, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    case 22:Utilities::Roulette(comb22, boardNum, 4, myLastResults, bet * 9, cMoney, aCasino); break;
                    default: std::cout << "Do it again! Correctly this time!\n\n"; break;
                    }
                    sann = false;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case  Utilities::eInsideBet::eLine://--------------------------------------------------------------------------------------Line
                std::cout << "-Line-\n";
                //std::cout << boardNum << "\n"; //Secret number
                sann = true;
                while (sann)
                {
                    Utilities::LineGameBoard();
                    std::cout << "Place your choice between a line of six numbers with eleven choices 1-11: "; // Example later
                    std::cin >> userIn;

                    switch (userIn)
                    {
                    case  1:Utilities::Roulette(sixNum01, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  2:Utilities::Roulette(sixNum02, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  3:Utilities::Roulette(sixNum03, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  4:Utilities::Roulette(sixNum04, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  5:Utilities::Roulette(sixNum05, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  6:Utilities::Roulette(sixNum06, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  7:Utilities::Roulette(sixNum07, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  8:Utilities::Roulette(sixNum08, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case  9:Utilities::Roulette(sixNum09, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case 10:Utilities::Roulette(sixNum10, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    case 11:Utilities::Roulette(sixNum11, boardNum, 6, myLastResults, bet * 6, cMoney, aCasino); break;
                    default: std::cout << "Do it again! Correctly this time!\n\n"; break;
                    }
                    sann = false;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
            }
        }
        else if (userIn == outsideBet) //Outside
        {
            std::cout << "Welcome to outside!\n";
            std::cout << "Choose between \n1. Column\n2. Dozen\n3. Low(1-18)\n4. High(19-36)\n5. Even/Odd\n6. Red/Black\n: ";
            std::cin >> userIn;

            int bet = Utilities::Bet(cMoney, aCasino);

            switch (static_cast<Utilities::eOutsideBet>(userIn))
            {
            case Utilities::eOutsideBet::eColumn:
                std::cout << "-Column-\n";
                //std::cout << boardNum << "\n"; //Secret number
                sann = true;
                while (sann)
                {
                    Utilities::ColumnGameBoard();
                    std::cout << "Place your choice between a column of these 3: "; // Example later
                    std::cin >> userIn;

                    switch (userIn)
                    {
                    case 1:Utilities::Roulette(Column01, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    case 2:Utilities::Roulette(Column02, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    case 3:Utilities::Roulette(Column03, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    default: std::cout << "Do it again! Correctly this time!\n\n"; break;
                    }
                    sann = false;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case Utilities::eOutsideBet::eDozen:
                std::cout << "-Dozen-\n";
                //std::cout << boardNum << "\n"; //Secret number

                sann = true;
                while (sann)
                {
                    Utilities::DozenGameBoard();
                    std::cout << "Place your choice between a Dozen of these 3: "; // Example later
                    std::cin >> userIn;

                    switch (userIn)
                    {
                    case 1:Utilities::Roulette(Dozen01, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    case 2:Utilities::Roulette(Dozen02, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    case 3:Utilities::Roulette(Dozen03, boardNum, 12, myLastResults, bet * 3, cMoney, aCasino); break;
                    default: std::cout << "Do it again! Correctly this time!\n\n"; break;
                    }
                    sann = false;
                }
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case Utilities::eOutsideBet::eLow:
                std::cout << "-Low(1-18)-\n";
                std::cout << "If you get one of these numbers you will win!";
                Utilities::LowBoard();
                Utilities::Roulette(Low, boardNum, 18, myLastResults, bet * 2, cMoney, aCasino);
                Utilities::Stats(myLastResults);
                std::cout << '\n';
            break;
            case Utilities::eOutsideBet::eHigh:
                std::cout << "-High(19-36)-\n";
                std::cout << "If you get one of these numbers you will win!";
                Utilities::HighBoard();
                Utilities::Roulette(High, boardNum, 18, myLastResults, bet * 2, cMoney, aCasino);
                Utilities::Stats(myLastResults);
                std::cout << '\n';
                break;
            case Utilities::eOutsideBet::eEvenOrOdd:
                std::cout << "-Even Or Odd-\n";
                sann;
                while (sann)
                {
                    std::cout << "1.Even \n2.Odd\n: ";
                    std::cin >> userIn;
                    switch (userIn)
                    {
                    case 1:Utilities::Roulette(Even, boardNum, 18, myLastResults, bet * 2, cMoney, aCasino); break;
                    case 2:Utilities::Roulette(Odd , boardNum, 18, myLastResults, bet * 2, cMoney, aCasino); break;
                    default: std::cout << "Do it again! Correctly this time!\n\n"; break;
                    }
                    Utilities::Stats(myLastResults);
                    std::cout << '\n';
                    sann = false;
                }
                break;
            case Utilities::eOutsideBet::eRedOrBlack:
                std::cout << "-Red Or Black-\n";
                Utilities::RedAndBlackNumbers();
                sann;
                while (sann)
                {
                    std::cout << "1. Red\n2. Black\n: ";
                    std::cin >> userIn;
                    switch (userIn)
                    {
                    case 1:Utilities::Roulette(Red  , boardNum, 18, myLastResults, bet * 2, cMoney, aCasino); break;
                    case 2:Utilities::Roulette(Black, boardNum, 18, myLastResults, bet * 2, cMoney, aCasino); break;
                    default: std::cout << "Do it again! \n\n"; break;
                    }
                    sann = false;
                    Utilities::Stats(myLastResults);
                    std::cout << '\n';
                    break;
            default: std::cout << "Do it again!\n"; break;
                }
            }
        }
        else
        {
            std::cout << "Good bye!\n";
        }
    }
}