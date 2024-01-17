#pragma once
#include "Utilities.h"
//#include "Casino 7.h"



namespace Games {
    class GuessDices {
        bool myPenning = true;
        bool myPlaying = true;
        bool myMinus = false;
        bool myPlus = false;
        int myGuessNum = 0;
        int myWon = 0;
        int myLoss = 0;
        int myPlay = 1;
        int myPlayerInput;
        int myRecordGameIndex = 0;

    public:
        void GuessDice(int& cMoney, std::array<Utilities::eGameResult, 5>& myLastResults, const int aMinValue, const int aMaxValue, const Casino& aCasino);
    
    
    
    };
}