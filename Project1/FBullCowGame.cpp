#pragma once
#include "FBullCowGame.h"
#include <map>
//this is to make the code Unreal friendly
#define TMap std::map
using int32 = int;
#include <stdlib.h>
#include <time.h>



 
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



  int RandIndex = NULL;
  FString RandW()
  {

	  srand(time(NULL)); //initialize the random seed


	  FString textArray[] = { "cake", "toast", "dog", "number", "dangerously", "disgraceful", "personality", "cat", "gas", "war", "iron", "foam", "sage", "visor", "sugar", "isogram", "fight", "black", "myth", "abuse", "advise", "baloney", "bandits", "machine", "mindful", "abolishment", "handsome", "hasteful", "holidays", "humanity", "hysteric",  "majority", "nifty", "zephyr", "nigma", "documentarily", "ambidextrous", "questionable", "habit", "hacker", "earing", "rabidly", "objectify", "cryptograph", "keyboard",  "knight", "security", "umbrae", "utopia", "ghost", "pixel", "badge", "bagel", "brain", "idea", "incubate" };
	  int number;
	  int RandIndex = rand() % 55; //generates a random number between 0 and how ever many words
	  srand(time(0));
	  if (RandIndex == 0) 
	  {
		  FString TheString = "Cake";
		  return TheString;
	  }
	  else if (RandIndex == 1)
	  {
		  FString TheString = "Toast";
		  return TheString;
	  }
	  else if (RandIndex == 2)
	  {
		  FString TheString = "dog";
		  return TheString;
	  }
	  else if (RandIndex == 3)
	  {
		  FString TheString = "number";
		  return TheString;
	  }
	  else if (RandIndex == 4)
	  {
		  FString TheString = "dangerously";
		  return TheString;
	  }
	  else if (RandIndex == 5)
	  {
		  FString TheString = "disgraceful";
		  return TheString;
	  }
	  else if (RandIndex == 6)
	  {
		  FString TheString = "disgraceful";
		  return TheString;
	  }
	  else if (RandIndex == 7)
	  {
		  FString TheString = "personality";
		  return TheString;
	  }
	  else if (RandIndex == 8)
	  {
		  FString TheString = "cat";
		  return TheString;
	  }
	  else if (RandIndex == 9)
	  {
		  FString TheString = "gas";
		  return TheString;
	  }
	  else if (RandIndex == 10)
	  {
		  FString TheString = "war";
		  return TheString;
	  }
	  else if (RandIndex == 11)
	  {
		  FString TheString = "iron";
		  return TheString;
	  }
	  else if (RandIndex == 12)
	  {
		  FString TheString = "foam";
		  return TheString;
	  }
	  else if (RandIndex == 13)
	  {
		  FString TheString = "sage";
		  return TheString;
	  }
	  else if (RandIndex == 14)
	  {
		  FString TheString = "visor";
		  return TheString;
	  }
	  else if (RandIndex == 15)
	  {
		  FString TheString = "sugar";
		  return TheString;
	  }
	  else if (RandIndex == 16)
	  {
		  FString TheString = "isogram";
		  return TheString;
	  }
	  else if (RandIndex == 17)
	  {
		  FString TheString = "fight";
		  return TheString;
	  }
	  else if (RandIndex == 18)
	  {
		  FString TheString = "black";
		  return TheString;
	  }
	  else if (RandIndex == 19)
	  {
		  FString TheString = "myth";
		  return TheString;
	  }
	  else if (RandIndex == 20)
	  {
		  FString TheString = "abuse";
		  return TheString;
	  }
	  else if (RandIndex == 21)
	  {
	  FString TheString = "advise";
	  return TheString;
	  }
	  else if (RandIndex == 22)
	  {
	  FString TheString = "baloney";
	  return TheString;
	  }
	  else if (RandIndex == 23)
	  {
	  FString TheString = "bandits";
	  return TheString;
	  }
	  else if (RandIndex == 24)
	  {
	  FString TheString = "machine";
	  return TheString;
	  }
	  else if (RandIndex == 25)
	  {
	  FString TheString = "mindful";
	  return TheString;
	  }
	  else if (RandIndex == 26)
	  {
	  FString TheString = "abolishment";
	  return TheString;
	  }
	  else if (RandIndex == 27)
	  {
	  FString TheString = "handsome";
	  return TheString;
	  }
	  else if (RandIndex == 28)
	  {
	  FString TheString = "hasteful";
	  return TheString;
	  }
	  else if (RandIndex == 29)
	  {
	  FString TheString = "holidays";
	  return TheString;
	  }
	  else if (RandIndex == 30)
	  {
	  FString TheString = "humanity";
	  return TheString;
	  }
	  else if (RandIndex == 31)
	  {
	  FString TheString = "hysteric";
	  return TheString;
	  }
	  else if (RandIndex == 32)
	  {
	  FString TheString = "majority";
	  return TheString;
	  }
	  else if (RandIndex == 33)
	  {
	  FString TheString = "nifty";
	  return TheString;
	  }
	  else if (RandIndex == 34)
	  {
	  FString TheString = "zephyr";
	  return TheString;
	  }
	  else if (RandIndex == 35)
	  {
	  FString TheString = "nigma";
	  return TheString;
	  }
	  else if (RandIndex == 36)
	  {
	  FString TheString = "documentarily";
	  return TheString;
	  }
	  else if (RandIndex == 37)
	  {
	  FString TheString = "ambidextrous";
	  return TheString;
	  }
	  else if (RandIndex == 38)
	  {
	  FString TheString = "questionable";
	  return TheString;
	  }
	  else if (RandIndex == 39)
	  {
	  FString TheString = "habit";
	  return TheString;
	  }
	  else if (RandIndex == 40)
	  {
	  FString TheString = "hacker";
	  return TheString;
	  }
	  else if (RandIndex == 41)
	  {
	  FString TheString = "earing";
	  return TheString;
	  }
	  else if (RandIndex == 42)
	  {
	  FString TheString = "rabidly";
	  return TheString;
	  }
	  else if (RandIndex == 43)
	  {
	  FString TheString = "objectify";
	  return TheString;
	  }
	  else if (RandIndex == 44)
	  {
	  FString TheString = "cryptograph";
	  return TheString;
	  }
	  else if (RandIndex == 45)
	  {
	  FString TheString = "keyboard";
	  return TheString;
	  }
	  else if (RandIndex == 46)
	  {
	  FString TheString = "knight";
	  return TheString;
	  }
	  else if (RandIndex == 47)
	  {
	  FString TheString = "security";
	  return TheString;
	  }
	  else if (RandIndex == 48)
	  {
	  FString TheString = "umbrae";
	  return TheString;
	  }
	  else if (RandIndex == 49)
	  {
	  FString TheString = "utopia";
	  return TheString;
	  }
	  else if (RandIndex == 50)
	  {
	  FString TheString = "ghost";
	  return TheString;
	  }
	  else if (RandIndex == 51)
	  {
	  FString TheString = "pixel";
	  return TheString;
	  }
	  else if (RandIndex == 52)
	  {
	  FString TheString = "badge";
	  return TheString;
	  }
	  else if (RandIndex == 53)
	  {
	  FString TheString = "bagel";
	  return TheString;
	  }
	  else if (RandIndex == 54)
	  {
	  FString TheString = "brain";
	  return TheString;
	  }
	  else if (RandIndex == 55)
	  {
	  FString TheString = "idea";
	  return TheString;
	  }
	  else 
	  {
	  FString TheString = "incubator";
	  return TheString;
	  }
	  
  }
  

  void FBullCowGame::Reset()
  {
	const FString HIDDEN_WORD = RandW();// this MUST be an isogram
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

  FString FBullCowGame::GetWordAfterLoss() const
  {
	  return MyHiddenWord;
  }
