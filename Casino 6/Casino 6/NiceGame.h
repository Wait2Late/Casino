#pragma once
#include "Utilities.h"


namespace Games {
    class NiceGames {
    bool myPenning = true;
    int myPlayerInput;
    int myPlay = 1;
    bool myPlaying = true;
    int myGuessNum;
    int myRecordGameIndex = 0;

    public:
        void NiceGame(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino);
    };
}
