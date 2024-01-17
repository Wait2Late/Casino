#pragma once
#include "Utilities.h"


namespace Games {
    class GuessRandys {
        int myRecordGameIndex = 0;
        int myUserIn;
        bool mySann = true;
    public:
        void GuessRandy(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino);
    };
}
