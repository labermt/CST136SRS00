// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>
#include <sstream>

static void showUsage()
{
	std::cerr << std::endl << 
		"Incorrect Parameters!\n"
		"\t Parameters:\n"
		"\t -d,-doors			Number of doors (default = 3)\n"
		"\t -o,-open			Number of doors to open (default = 1)\n"
		"\t -i,-instances			Number of game instances to run (default = 1)\n"
		"\t -s,-strategy			Selected strategy (options: stay, switch; default = stay)\n"
		"\n"
		"\t Example:\n"
		"\n"
		"\t MontyHall.exe -doors 3 -open 1 -instances 1 -strategy stay"
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

	/*
	if (argc <= 1) 
	{
		showUsage(argv[0]);
		return 1;
	}
	*/
	showUsage();

	for ( size_t i{ 1 }; i < argc; i++)
	{
		if ( *(argv[i]) == '-' )
		{
			const auto parameter = std::string(argv[i] + 1);

			if ( parameter == "d" || parameter == "doors")
			{
				i++;
				std::istringstream iss(argv[i]);
				
				if ( !(iss >> doorParam) || iss.bad() )
				{
					failedParse = true;
				}
			}
			else if ( parameter == "o" || parameter == "open")
			{
				i++;
				std::istringstream iss(argv[i]);
				
				if ( !(iss >> openParam) || iss.bad() )
				{
					failedParse = true;
				}
			}
			else if ( parameter == "i" || parameter == "instances")
			{
				i++;
				std::istringstream iss(argv[i]);
				
				if ( !(iss >> instancesParam) || iss.bad() )
				{
					failedParse = true;
				}
			}
			else if ( parameter == "s" || parameter == "strategy" )
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
		}
		else
		{
			failedParse = true;
		}
		//auto test = *(argv[1] + 1); //this shows the second character of the first input parameter
	}

	if ( failedParse )
	{
		showUsage();
		return 0;
	}

	//TODO: add objects of LetsMakeADeal type into a vector (storage container)
	//TODO: tally results of runGame() to find probability of success with given paramaters

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

