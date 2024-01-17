#pragma once
#include "Utilities.h"


namespace Games {
    class OddOrEvens {
        bool myPenning = true;
        bool myPlaying = true;
        int myGuessNum = 0;
        int myPlay = 1;
        int myPlayerInput;
        int myGuessOddOrEven1 = Utilities::GuessOddOrEven();
        int myGuessOddOrEven2 = Utilities::GuessOddOrEven();
        int myEven = 2;
        int myOdd = 1;
        int myRecordGameIndex = 0;
    public:
        void OddOrEven(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino);
    };
}