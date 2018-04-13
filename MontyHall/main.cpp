// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <iostream>

void helper() {

	std::cout << "How to play" << std::endl << std::endl;
	std::cout << "First argument: \"switch\" or \"stay\" " << std::endl;
	std::cout << "Second argument: Enter the number of game instances" << std::endl;
	std::cout << "Third argument: Enter the number of doors" << std::endl;
	std::cout << "Third argument: Enter the number of doors to be revealed" << std::endl << std::endl;
	std::cout << "Example: switch 10 3 1" << std::endl;
	std::cout << "This will run 10 instances of the game with 3 doors and 1 revealed door with a decision to switch doors." << std::endl;
	
	//exits program
	exit(EXIT_FAILURE);
}

void startGame(int argc, char* argv[]) {

	//assign first command line argument to: 1 for switch; 2 for stay
	std::string switchOrStay = argv[1];
	int decideSwitchOrStay = 0;

	//decide to switch
	if (switchOrStay == "switch") {
		decideSwitchOrStay = 1;
	}
	//decide to stay
	else if (switchOrStay == "stay") {
		decideSwitchOrStay = 2;
	}
	//handle invalid command line argument
	else {
		helper();
	}

	//assign command line arguments to integers
	int numberGames = std::atoi(argv[2]);
	//check for errors negative number******************************
	
	int numberDoors = 3;
	if (argc > 3) {
		numberDoors = std::atoi(argv[3]);
	}

	int revealNumberDoors = 1;
	if (argc > 4) {
		revealNumberDoors = std::atoi(argv[4]);
	}

	//using atoi
	LetsMakeADeal startGame(decideSwitchOrStay, numberGames, numberDoors, revealNumberDoors);
}

int main(int argc, char* argv[]) {
	
	startGame(argc, argv);
	
	return 0;
}