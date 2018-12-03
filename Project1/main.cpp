/*this is the console exe that makes the us of the bullcow class this acts as sthe view om the mvc pattern,
 and is responsible for all user interaction for the game logic see the fbullcowgame class*/
//TODO redo the theme of the game 
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntex Unreal friendly
using int32 = int;
using FText = std::string;

//this allows you to not need a std:: to find the name space
//funtion prototypes as ouside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //instantiate a new game, which we re-use across plays

int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		//loop for the number of turns asking for guesses
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

void PrintIntro() 
{
	//the std means standard name space if the name space is hidden you need to use << to find them std::endl means to end line \n is the same thing but can only be used with ""
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
		/*
		DODO 
		put 
		ascii 
		art 
		here
		Thank you for visiting https ://asciiart.website/
	This ASCII pic can be found at
		https ://asciiart.website//index.php?art=animals/cows
		*/
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
//plays a single game to completion 
void PlayGame() 
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is NOT won
	//and there are still tries remaining 
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
		//submit valid guess to the game
		BullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}
//loop untill given a valid guess

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);
		//check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			//default assumes the guess is valid 
			break;
		}
	} while (Status != EGuessStatus::OK);//keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again with the same hidden word(y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return(Response[0] == 'y') || (Response[0] == 'Y');
}


void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "                                                                                 __" << std::endl;
		std::cout << "                                                               __              / \\ \\ " << std::endl;
		std::cout << "        __    __      ___     __    __         __    __    __ /\\_ \\    ___      \\ \\ \\ " << std::endl;
		std::cout << "       /\\  \\/\  \\   /  __ `\\ /\\ \\ /\\  \\       /\\  \\ /\\  \\ /\\  \\/\\  \\ /' _ ` \\     \\ \\ \\ " << std::endl;
		std::cout << "       \\ \\  \\_\\  \\ /\\  \\L\\  \\  \\ \\_ \\  \\      \\ \\  \\_ / \\_/ \\  \\ \\  \\/\\ \\/\\ \\     \\ \\_\\ " << std::endl;
		std::cout << "        \\/`____   \\  \\ ____ /\\  \\ ____ /       \\ \\   ___x___   /'\\\\_ \\ \\_\\ \\_\\     \\/\\_\\ " << std::endl;
		std::cout << "         `/___ />  \\ / ___ /  \\ / ___ /         \\/_____/ /____/   \\/_/\\/_/\\/_/      \\/_/ " << std::endl;
		std::cout << "             / \\___ /                     " << std::endl;
		std::cout << "             \\ /__ /    " << std::endl;
		std::cout << std::endl;
	} 
	else
	{
	std::cout << "    __       __       ___ ___       __         ___    __  __     __   _ __  " << std::endl;
	std::cout << "  /'_ `\\   /'__`\\   /' __` __`\\   /'__`\\      / __`\\ /\\ \\/\\ \\  /'__`\\/\\`'__\\ " << std::endl;
	std::cout << " /\\ \\L\\ \\ /\\ \\L\\.\\_ /\\ \\/\\ \\/\\ \\ /\\  __/     /\\ \\L\\ \\\\ \\ \\_/ |/\\  __/\\ \\ \\/" << std::endl;
	std::cout << " \\ \\____ \\\\ \\__/.\\_\\\\ \\_\\ \\_\\ \\_\\\\ \\____\\    \\ \\____/ \\ \\___/ \\ \\____\\\\ \\_\\ " << std::endl;
	std::cout << "  \\/___L\\ \\\\/__/\\/_/ \\/_/\\/_/\\/_/ \\/____/     \\/___/   \\/__/   \\/____/ \\/_/ " << std::endl;
	std::cout << "    /\\____/                                                                 " << std::endl;
	std::cout << "    \\_/__/    " << std::endl;
	std::cout << std::endl;
	}
}     
