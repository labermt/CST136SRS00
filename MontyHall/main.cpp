#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
#include <string>

//this isnt working right
int main(/*unsigned const games = 0, std::string const strat = "null", unsigned const doors = 3, unsigned const open_doors = 1*/ )
{
	/*if(games == 0 || strat == "null" )
	{
		std::cout << "The arguement order should be [0] number of games you want to run";
		std::cout << ", [1] your strategy 'stay' or 'change'";
		std::cout << ", [2] number of doors in the game, [3] number of doors you would like to be opened\nPlease rerun the program with the correct argument format.\n";
		std::cout << "Example: 'MontyHall.exe 100 stay 5 2'";
	}
	else if (strat != "stay" || strat != "change" )
	{
		std::cout << "It appears you entered an invalid strategy, case is important.\n";
		std::cout << "Please rerun the program with argument[1] being 'stay' or 'change'.";
		std::cout << "Example: 'MontyHall.exe 100 stay 5 2'";
	}
	else if (doors < open_doors +2)
	{
		std::cout << "It appears you entered an invaild number of doors  vs doors you want to open.\n";
		std::cout << "Please rerun the program with a number of doors at least 2 more than the doors you want to open.\n";
		std::cout << "In the following order, [0] Times to run, [1] Strategy 'stay' or 'switch' [2] Total doors, [3] Doors to open.\n";
		std::cout << "Example: MontyHall.exe 100 stay 5 2";
	else*/
	{
		auto doors = 3;
		auto open_doors = 1;
		auto games = 1;
		auto strat = "stay";
		auto const total_doors{doors - open_doors};
		auto wins{0.0};
		//use something like this to meet spec?
		//std::vector<LetsMakeADeal> game_instaces(games);
		for(auto i = 0; i < games;i++)
		{
			LetsMakeADeal game(doors, open_doors,strat);
			if(game.run_game() ){++wins;}
		}
		auto win_percent{wins / games};
		auto probability{1.0/total_doors};

	}
    return 0;
}
//TODO: figure out issues with input parameters.
//TODO: workout infinite loops if somehow all doors get opened guessing will keep guessing / go out of bounds somehow?
//TODO: change doors to a multi dimational array, will that allow 2 states to be saved? example door1 = opened + goat?
//TODO: fix out of bounds issue with guessing. I am not sure if that is the cause of the problem, bounds are set to be between 0 and # of doors.
//TODO: final math described in readme. line 36: unsure how, line 34: 
//TODO: argue const correctness? example set_car function. It changes the game_instance passed in..should be const or no?