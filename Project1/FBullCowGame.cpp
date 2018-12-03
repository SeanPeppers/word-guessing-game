#pragma once
#include "FBullCowGame.h"
#include <map>
//this is to make the code Unreal friendly 
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}
//DOTO make it so that the word is random
int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries
	{
		{3,  4},
		{4,  7},
		{5,  10},
		{6,  16},
		{7,  20},
		{8,  24},
		{9,  28},
		{10, 30},
		{11, 30},
		{12, 30},
		{13, 30},
		{14, 30}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "dog";// this MUST be an isogram
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))//if the guess isnt a isogram, return an error 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))//if the guess isnt all lowercase, return error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
//recieves a valid guess, adds turn and returns count
BullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	//setup a return varriable
	BullCowCount BullCowCount;
	//loop through all letters in the guess

	int32 WordLength = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			//if they match then
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				//if theyre in the same place
				if (HWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}

			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms 
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup our map
	for (auto Letter : Word)
	{
		
		Letter = tolower(Letter);//handle mixed case
		//loop through all the letters of the word
		if (LetterSeen[Letter]) //if the letter is the map
		{
			return false;//we do NOT have an isogram 
		}
		else
		{
			LetterSeen[Letter] = true;//we do NOT have an isogram
		//otherwise
			//add the letter to the map as seen
		}


	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))//if not a lowercase letter 
		{
			return false;
		}
	}
	return true;
}
