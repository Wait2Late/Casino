#pragma once
#include "GuessDice.h"
#include "GuessRandy.h"
#include "NiceGame.h"
#include "OddOrEven.h"
#include "Roullete.h"
#include "Utilities.h"

class Casino
{
	bool myPlayingCasino = true;
	int myHundred = 100;
	int myLobbyChoice;
	std::string myName;

	enum class eLobbyChoice { 
		eGuessDiceLowStakes = 1, 
		eGuessDiceHighStakes, 
		eOddOrEven, 
		eNiceGame, 
		eGuessRandy,
		eRoulette,
		eStatistics, 
		quit 
	};
public:
	Casino();
	void EnterLobby();


	Games::GuessDices objGuessDiceLowStakes;
	Games::GuessDices objGuessDiceHighStakes;
	Games::GuessRandys objGuessRandy;
	Games::NiceGames objNiceGame;
	Games::OddOrEvens objOddOrEven;
	Games::Roullete objRoullete;

	void ChooseYourName();
	void SetName(std::string aName);
	const std::string& GetName() const;
	bool IFValidName(const std::string& aName)const;
};