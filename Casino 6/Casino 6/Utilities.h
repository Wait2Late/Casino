#pragma once
#include <array>
#include <string>
//#include "Casino 7.h"

class Casino;

namespace Utilities {

	enum class eGameResult { WIN, LOSE };

	enum class eInsideBet  {eStraightUp = 1, eSplit, eStreetTriple, eCornerFour, eLine };
	enum class eOutsideBet { eColumn = 1, eDozen, eLow, eHigh, eEvenOrOdd, eRedOrBlack };
	
	//std::array<eGameResult, 5> myLastResults;
	int Lobby(int& aMoney, const Casino& aCasino);
	int NumberInput(const int aMinValue, const int aMaxValue, const std::string& aMessage, const Casino& aCasino);
	int Bet(int& aPlayerMoney, const Casino& aCasino);
	int GuessDiceStake(int& aPlayerMoney, const int aMinBet, const int aMaxBet, const Casino& aCasino);
	void Win(const int aMoneys, int& ref, std::array<Utilities::eGameResult, 5>& myLastResults, const Casino& aCasino);
	void Lose(std::array<eGameResult, 5>& myLastResults, const Casino& aCasino);
	void Stats(const std::array<eGameResult, 5>& myLastResults);
	void uStats(const eGameResult aOutCome, std::array<eGameResult, 5>& myLastResults);
	int GuessNum();
	int GuessOddOrEven();
	int ANiceGame();
	int RandomNumbers();
	int RouletteNumber();

	//Roullete
	void GameBoard();
	void StreetTripleGameBoard();
	void CornerFourGameBoard();
	void LineGameBoard();
	void ColumnGameBoard();
	void DozenGameBoard();
	void LowBoard();
	void HighBoard();
	void RedAndBlackNumbers();

	void Roulette(const int param[], const int randy, const int length, std::array<eGameResult, 5>& myLastResults, int aMoneys, int& ref, const Casino& aCasino);
}