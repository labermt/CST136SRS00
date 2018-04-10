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
		std::cout << "Example: 'LetsMakeADeal.exe 100 stay 5 2'";
	}
	else if (strat != "stay" || strat != "change" )
	{
		std::cout << "It appears you entered an invalid strategy, case is important.\n";
		std::cout << "Please rerun the program with argument[1] being 'stay' or 'change'.";
		std::cout << "Example: 'LetsMakeADeal.exe 100 stay 5 2'";
	}
	else*/
	{
		auto doors = 3;
		auto open_doors = 1;
		auto games = 1;
		auto strat = "stay";
		auto const total_doors{doors - open_doors};
		auto wins{0.0};
		
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

