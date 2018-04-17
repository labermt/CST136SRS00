#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
#include <string>
#include <cassert>
#include <complex>
#include <iomanip>

int main(int const argc, char* const argv[])
{
	auto doors = 3;
	auto open_doors = 1;
	std::string strat = "unknown";
	auto games = 0;
	auto fault = false;

	if ((argc - 1) / 2 < 2)
	{
		fault = true;
	}
	else
	{
		for (auto i = 1; i < argc; i += 2)
		{

			switch (argv[i][1])
			{
			case 'd':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> doors;
				if (doors < 3)
				{
					fault = true;
				}
				break;
			}
			case 'o':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> open_doors;
				if (open_doors < 0)
				{
					fault = true;
				}
				break;
			}
			case 's':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> strat;
				if (strat == "stay" || strat == "switch")
				{
					break;
				}
				fault = true;
				break;
			}
			case 'g':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> games;
				break;
			}
			default:
			{
				fault = true;
				break;
			}
			}
		}
	}

	if (games == 0 || fault || doors - open_doors < 2)
	{
		LetsMakeADeal::display_help();
	}
	else
	{
		std::vector<LetsMakeADeal> game_list;
		game_list.reserve(games);

		for (auto i = 0; i < games; i++)
		{
			LetsMakeADeal game(doors, open_doors, strat);
			game_list.emplace_back(game);
		}

		auto wins{ 0.0 };
		auto losses{ 0.0 };

		for (auto &game : game_list)
		{
			if (game.get_result() == LetsMakeADeal::result::won)
			{
				++wins;
			}
			else
			{
				++losses;
			}
		}
		auto const win_percent{ wins / (games *1.0) };
		auto const loss_percent{ losses  / (games *1.0) };
		assert(.999999 < win_percent + loss_percent && win_percent + loss_percent < 1.000001);
		printf("%#.2f \n", win_percent);
	}
	return 0;
}
