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
			"There was an error with your entry\n"
			"---------------\n"
			"Input Example: MontyHall.exe 1 stay 3 1\n"
			"\n"
			"usage: MontyHall.exe trials strategy doors disclose.\n"
			"\n"
			"trials: The number of times to run the simulation.\n"
			"\n"
			"strategy: stay | switch.\n"
			"\n"
			"doors: The total number of doors in the simulation.\n"
			"\n"
			"disclose: The number of doors to be disclosed in the simulation.\n"
			"\n"
			"Note: disclose < doors.\n \n";
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
	auto doors{ 3 };
	auto disclose{ 1 };
	auto trials{ 1 };

	LetsMakeADeal::Strategy strategy{ LetsMakeADeal::Strategy::kUnknown };

	if (argc >= 3 && argc < 6)
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

	if (disclose >= doors
		|| (strategy != LetsMakeADeal::Strategy::kSwitch && strategy != LetsMakeADeal::Strategy::kStay)
		|| doors == disclose
		|| doors < 3
		|| trials < 1
		|| disclose < 0
		|| doors > disclose + 2)
	{
		userHelp();
	}
	else
	{
		std::vector<LetsMakeADeal> games;

		auto carTotal{ 0 };
		auto goatTotal{ 0 };

		for (auto i{ 0 }; i < trials; i++)
		{
			games.push_back(LetsMakeADeal(doors, disclose, strategy));
		}

		for (auto &game : games)
		{
			game.playGame();
			if (game.getResult() == LetsMakeADeal::result::win)
			{
				++carTotal;
			}
			else
			{
				++goatTotal;
			}
		}

		const auto probabilityCar{ (carTotal * 1.0) / (trials * 1.0 ) };
		const auto probabilityGoat{ (goatTotal * 1.0) / (trials * 1.0) };
		cout << probabilityCar;

		assert(0.999 < probabilityCar + probabilityGoat && probabilityCar + probabilityGoat < 1.001);
		return 0;
	}
}

