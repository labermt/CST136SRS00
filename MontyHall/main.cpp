﻿#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
#include <string>
#include <cassert>

//use string stream parse command line arguments
int main( int argc, char* argv[] )
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
		std::cout << 
		"It appears you entered an invalid strategy, case is important.\n"
		"Please rerun the program with argument[1] being 'stay' or 'change'."
		"Example: 'MontyHall.exe 100 stay 5 2'";
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
		auto games = 5;
		auto strat = "stay";
		auto const total_doors{doors - open_doors};
		auto wins{0.0};
		
		std::vector<LetsMakeADeal> game_list;
		game_list.reserve(games);
		for (auto i = 0; i < games; i++)
		{
			LetsMakeADeal game(doors, open_doors, strat);
			game_list.emplace_back(game);
		}

		for (auto &game : game_list)
		{
			game.run_game();
		}

		for (auto &game : game_list)
		{
			if (game.get_result() == LetsMakeADeal::result::won)
			{
				++wins;
			}
		}
		auto const win_percent{wins / games};
		
		std::cout << "Out of "<< games <<
					 " game(s) you won " << win_percent << "% of them" << std::endl;
	}
    return 0;
}
//TODO: figure out issues with input parameters.
//TODO: workout infinite loops if somehow all doors get opened guessing will keep guessing / go out of bounds somehow?
//TODO: final math described in readme.