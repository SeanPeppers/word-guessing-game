/*The game logic (no view code or direct user interaction)
the game is a simple guess the word game basedd on Mastermind*/

#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	FString GetWordAfterLoss() const;
	
	void Reset();
	EGuessStatus CheckGuessValidity(FString) const;
	//provide a mthod for counting bulls and cow, and increasing turn #
	BullCowCount SubmitValidGuess(FString);

private:
	//see contructor for initalisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
