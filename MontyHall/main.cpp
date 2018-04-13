// main.cpp : Defines the entry point for the console application.
//TODO: change to "S algorithm" for selecting doors to open.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>

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
		"\t MontyHall.exe --doors 3 --open 1 --instances 100 --strategy stay\n"
		"\t MontyHall.exe -d 5 -o 3 -s switch --instances 1000\n"
		"\t MontyHall.exe -d 30 --instances 500\n"
		"\n"
		"\t See README.md for details.\n"
		<< std::endl;
}

int main(const int argc, char* argv[])
{
	// Default choices for input parameters
	size_t doorParam{ 3 };
	size_t openParam{ 1 };
	size_t instancesParam{ 100 };
	auto strategyParam{ LetsMakeADeal::choice::stay };
	auto failedParse = false;

	// Parse input parameters
	for (size_t i{ 1 }; i < argc; i += 2)
	{
		const auto parameter = std::string(argv[i]);

		if (parameter == "-d" || parameter == "--doors")
		{
			std::istringstream iss(argv[i + 1]);

			if (!(iss >> doorParam) || iss.bad())
			{
				failedParse = true;
			}
		}
		else if (parameter == "-o" || parameter == "--open")
		{
			std::istringstream iss(argv[i + 1]);

			if (!(iss >> openParam) || iss.bad())
			{
				failedParse = true;
			}
		}
		else if (parameter == "-i" || parameter == "--instances")
		{
			std::istringstream iss(argv[i + 1]);

			if (!(iss >> instancesParam) || iss.bad())
			{
				failedParse = true;
			}
		}
		else if (parameter == "-s" || parameter == "--strategy")
		{
			const auto choice = std::string(argv[i + 1]);

			if (choice == "stay")
			{
				strategyParam = LetsMakeADeal::choice::stay;
			}
			else if (choice == "switch")
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

	// Show help if input parameters are in error, or invalid doors / open doors
	if (failedParse || doorParam <= openParam + 1)
	{
		showUsage();
		return 0;
	}


	// Variables for games / tallies
	std::vector<LetsMakeADeal> games;
	auto carTally{ 0 };
	auto goatTally{ 0 };

	// Run the games
	for (auto i{ 0 }; i < instancesParam; i++)
	{
		games.push_back(LetsMakeADeal(doorParam, openParam, strategyParam));

		if (games[i].runGame() == LetsMakeADeal::prize::car)
		{
			carTally++;
		}
		else
		{
			goatTally++;
		}
	}

	const auto probabilityCar = (1.0 * carTally) / instancesParam;
	const auto probabilityGoat = (1.0 * goatTally) / instancesParam;

	assert(99 <= probabilityCar + probabilityGoat <= 100);

	std::cout << probabilityCar;

	// Output the results
	/*
	std::cout << "\n The probability of winning a car is "
		<< std::setprecision(3) << probabilityCar * 100 << "%";
	std::cout << " if there are "
		<< doorParam << " doors, \n of which "
		<< openParam << " doors are(is) opened and the contenstant chose to "
		<< strategyParam << ".\n\n";

	std::cout << " This was calculated over "
		<< instancesParam << " simulations of the game.\n";
	*/

	return 0;
}

