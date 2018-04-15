// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>


int main(const int argc, char* argv[])
{

	// Default choices for input parameters
	size_t doorParam{ 3 };
	size_t openParam{ 1 };
	size_t instancesParam{ 0 };
	auto strategyParam{ LetsMakeADeal::choice::unselected };
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
				strategyParam = LetsMakeADeal::choice::change;
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
	// or no entry for instancesParam or strategyParam
	if (failedParse
		|| doorParam < openParam + 2
		|| instancesParam == 0
		|| strategyParam == LetsMakeADeal::choice::unselected
		|| doorParam < 3
		|| openParam < 1)
	{
		LetsMakeADeal::showUsage();
		return 0;
	}


	// Variables for games / tallies
	std::vector<LetsMakeADeal> games;

	// Add games to container
	for (auto i{ 0 }; i < instancesParam; i++)
	{
		games.push_back(LetsMakeADeal(doorParam, openParam, strategyParam));
	}

	auto carTally{ 0 };
	auto goatTally{ 0 };

	// Total probability 
	for (auto & game : games)
	{
		if (game.getResult() == LetsMakeADeal::prize::car)
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

	assert(.99 <= probabilityCar + probabilityGoat && probabilityCar + probabilityGoat <= 1.0);

	std::cout << probabilityCar;

	return 0;
}
