// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <vector>
#include "LetsMakeADeal.h"
#include <sstream>
#include "gsl.h"
using namespace std; 

namespace // unnamed 
{

	void userHelp()
	{
		cout <<
			"MontyHall Help \n"
			"---------------\n"
			"Input Example: MontyHall.exe 1 stay 3 1\n"
			"\n"
			"Usage: MontyHall.exe trials strategy doors disclose.\n"
			"trials: The number of times to run the simulation.\n"
			"strategy: stay | switch.\n"
			"doors: The total number of doors in the simulation.\n"
			"disclose: The number of doors to be disclosed in the simulation.\n"
			"Note: disclose < doors.\n";
	}

	LetsMakeADeal::Strategy parseStrategy(std::string const strategyParam)
	{
		LetsMakeADeal::Strategy result = LetsMakeADeal::Strategy::kUnknown;
		if (strategyParam == "stay")
		{
			result = LetsMakeADeal::Strategy::kStay;
		}
		else if (strategyParam == "switch")
		{
			result = LetsMakeADeal::Strategy::kSwitch; 
		}
		return result; 
	}
}

int main(int argc, char *argv[])
{
	constexpr auto kTrialsIndex{ 1 }; 
	constexpr auto kStrategyIndex{ 2 };
	constexpr auto kDoorsIndex{ 3 };
	constexpr auto kDiscloseIndex{ 4 };

	// default parameters
	size_t doors{ 3 }; 
	size_t disclose{ 1 }; 
	size_t trials{ 0 }; 
	LetsMakeADeal::Strategy strategy{ LetsMakeADeal::Strategy::kUnknown };

	if (argc>=3 && argc < 6)
	{
		istringstream iss;
		int tmp{ };

		iss.clear();
		iss.str(argv[kTrialsIndex]);
		tmp = trials;
		iss >> tmp; 
		if (iss.eof())
		{
			trials = tmp; 
		} 

		strategy = parseStrategy(argv[kStrategyIndex]);

		iss.clear();
		iss.str(argv[kDoorsIndex]);
		tmp = doors;
		iss >> tmp;
		if (iss.eof())
		{
			doors = tmp;
		}

		iss.clear();
		iss.str(argv[kDiscloseIndex]);
		tmp = disclose;
		iss >> tmp;
		if (iss.eof())
		{
			disclose = tmp;
		}
	}

	if (disclose >= doors || (strategy != LetsMakeADeal::Strategy::kSwitch && strategy != LetsMakeADeal::Strategy::kStay) || doors<2 || trials <1 || disclose<0)
	{
		userHelp();
	}
	else
	{
		std::vector<LetsMakeADeal> games;

		size_t carTotal{ 0 };
		size_t goatTotal{ 0 };

		for (auto i{ 0 }; i < trials; i++)
		{
			games.push_back(LetsMakeADeal(doors, disclose, strategy));
			if (games[i].playGame() == LetsMakeADeal::behindTheDoor::car)
			{
				carTotal++;
			}
			else
			{
				goatTotal++;
			}
		}

		const auto probabilityCar = (1.0 * carTotal) / trials;
		const auto probabilityGoat = (1.0 * goatTotal) / trials;

		assert(99 <= probabilityCar + probabilityGoat <= 100);
		cout << probabilityCar;
		return 0;
	}
}

