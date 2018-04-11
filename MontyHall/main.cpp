// main.cpp : Defines the entry point for the console application.
//TODO: tally results of runGame() to find probability of success with given paramaters
//TODO: change to "S algorithm" for selecting doors to open.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>
#include <sstream>

static void showUsage()
{
	std::cerr << std::endl << 
		"Incorrect Parameters!\n"
		"\n"
		"\t Usage:\n"
		"\t -d,--doors			Number of doors (default = 3)\n"
		"\t -o,--open			Number of doors to open (default = 1)\n"
		"\t -i,--instances			Number of game instances to run (default = 1)\n"
		"\t -s,--strategy			Selected strategy (options: stay, switch; default = stay)\n"
		"\n"
		"\t Example(s):\n"
		"\n"
		"\t MontyHall.exe -doors 3 -open 1 -instances 1 -strategy stay\n"
		"\t MontyHall.exe -d 5 -o 3 -s switch -instances 100\n"
		"\t MontyHall.exe -d 30 -instances 5\n"
		"\n"
		"\t See README.md for details.\n"
		<< std::endl;
}

int main( int argc, char* argv[] )
{
	//default choices for input parameters
	size_t doorParam{ 3 };
	size_t openParam{ 1 };
	size_t instancesParam{ 1 };
	LetsMakeADeal::choice strategyParam{ LetsMakeADeal::choice::stay };
	auto failedParse = false;

	for ( size_t i{ 1 }; i < argc; i++)
	{
		const auto parameter = std::string(argv[i]);

		if ( parameter == "-d" || parameter == "--doors")
		{
			i++;
			std::istringstream iss(argv[i]);
			
			if ( !(iss >> doorParam) || iss.bad() )
			{
				failedParse = true;
			}
		}
		else if ( parameter == "-o" || parameter == "--open")
		{
			i++;
			std::istringstream iss(argv[i]);
			
			if ( !(iss >> openParam) || iss.bad() )
			{
				failedParse = true;
			}
		}
		else if ( parameter == "-i" || parameter == "--instances")
		{
			i++;
			std::istringstream iss(argv[i]);
			
			if ( !(iss >> instancesParam) || iss.bad() )
			{
				failedParse = true;
			}
		}
		else if ( parameter == "-s" || parameter == "--strategy" )
		{
			i++;
			const auto choice = std::string(argv[i]);

			if ( choice == "stay" )
			{
				strategyParam = LetsMakeADeal::choice::stay;
			}
			else if ( choice == "switch" )
			{
				strategyParam = LetsMakeADeal::choice::willswitch;
			}
			else
			{
				failedParse = true;
			}
		}
		else
		{
			failedParse = true;
		}
	}

	if ( failedParse )
	{
		showUsage();
		return 0;
	}


	std::vector<LetsMakeADeal> games;
	auto numCars{ 0 };
	auto numGoats{ 0 };
	auto probabilityCar{ 0.0 };
	auto probabilityGoat{ 0.0 };

	for ( auto i{ 0 }; i < instancesParam; i++)
	{
		games.push_back(LetsMakeADeal(doorParam, openParam, strategyParam));

		if ( games[i].runGame() == LetsMakeADeal::prize::car)
		{
			numCars++;
		}
		else
		{
			numGoats++;
		}
	}

	probabilityCar = double(numCars) / double(numCars + numGoats);
	probabilityGoat = double(numGoats) / double(numCars + numGoats);

	
    return 0;
}

