// MontyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#include "gsl.h"
#include "LetsMakeADeal.h"
#include "Strategy.h"

Strategy getSwitchStrategy (std::stringstream& argStream)
{
	auto ret{ Strategy::kError };
	std::string strategyStr = "";
	argStream >> strategyStr;
	if (strategyStr == "Switch")
	{
		ret = Strategy::kSwitch;
	}
	else if (strategyStr == "Stay")
	{
		ret = Strategy::kStay;
	}
	return ret;
}

void runSimulation(const int argc, char* const argv[])
{
	std::stringstream argStream;
	for (auto i = 1; i < argc; i++)
	{
		argStream << argv[i] << " ";
	}

	auto numDoors{ 3 };
	auto doorsRevealed{ 1 };
	auto gameInstances{ 1 };
	auto switchStrategy{ Strategy::kError };
	auto badInput{ false };
	switch (argc)
	{
	case 3:
	{
		argStream >> gameInstances;
		switchStrategy = getSwitchStrategy(argStream);
	}
	break;

	case 4:
	{
		argStream >> numDoors;
		argStream >> gameInstances;
		switchStrategy = getSwitchStrategy(argStream);
	}
	break;

	case 5:
	{
		argStream >> numDoors;
		argStream >> doorsRevealed;
		argStream >> gameInstances;
		switchStrategy = getSwitchStrategy(argStream);
	}
	break;

	default:
	{
		badInput = true;
	}
		break;
	}

	if(switchStrategy == Strategy::kError || numDoors < 3 || doorsRevealed > numDoors - 2 || doorsRevealed < 1 || gameInstances < 1)
	{
		badInput = true;
	}

	if (badInput)
	{
		std::cout << "Your command line arguments are off. The syntax is \"MontyHall.exe [numDoors] [doorsRevealed] [gameInstances] [switchStrategy]\", where:\n" <<
			"- [numDoors] is the number of doors in each game, written as an integer. If left off, this will default to 3.\n" <<
			"- [doorsRevealed] is the number of doors to reveal in each game, written as an integer. If left off, this will default to 1.\n" <<
			"- [gameInstances] is the number of games to try and run, written as an integer.\n" <<
			"- [switchStrategy] is the strategy to use, written as \"Switch\" or \"Stay\", case sensitive." << std::endl;
	}
	else
	{
		std::vector<const LetsMakeADeal*> games;
		auto carsWon{ 0 };
		auto goatsWon{ 0 };
		for (auto i = 0; i < gameInstances; i++)
		{
			games.push_back(new LetsMakeADeal{ numDoors, doorsRevealed, switchStrategy });
		}
		for (auto game : games)
		{
			if(game != nullptr)
			{
				if (game->simulateGame())
				{
					carsWon++;
				}
				else
				{
					goatsWon++;
				}
				delete game;
			}
		}

		const auto carRatio = 1.0 * carsWon / gameInstances;
		const auto goatRatio = 1.0 * goatsWon / gameInstances;
		const auto delta = 1.0 - (carRatio + goatRatio);
		Expects(delta < 0.0001);
		std::cout << carRatio << std::endl;
		//std::cout << numDoors << ' ' << doorsRevealed << ' ' << gameInstances << ' ' << switchStrategy << ' ' << std::endl;
	}
}

int main (int argc, char* argv[])
{
	runSimulation(argc, argv);
	_CrtDumpMemoryLeaks();
    return 0;
}

