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

void start_game(const int argc, char* argv[]) {

	//assign first command line argument to: 1 for switch; 2 for stay
	const std::string switch_or_stay = argv[1];
	auto decide_switch_or_stay = 0;

	//decide to switch
	if (switch_or_stay == "switch") {
		decide_switch_or_stay = 1;
	}
	//decide to stay
	else if (switch_or_stay == "stay") {
		decide_switch_or_stay = 2;
	}
	//handle invalid command line argument
	else {
		helper();
	}

	//assign command line arguments to integers
	const auto number_games = std::atoi(argv[2]);
	//check for errors negative number******************************
	
	auto number_doors = 3;
	if (argc > 3) {
		number_doors = std::atoi(argv[3]);
	}

	auto reveal_number_doors = 1;
	if (argc > 4) {
		reveal_number_doors = std::atoi(argv[4]);
	}

	LetsMakeADeal play_game(decide_switch_or_stay, number_games, number_doors, reveal_number_doors);
}

int main(const int argc, char* argv[]) {
	
	start_game(argc, argv);

	return 0;
}