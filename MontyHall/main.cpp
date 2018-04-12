#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
#include <string>
#include <cassert>
#include <complex>

int main(int const argc, char* argv[])
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
				break;
			}
			case 'o':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> open_doors;
				break;
			}
			case 's':
			{
				std::istringstream iss(argv[i + 1]);
				iss >> strat;
				if (strat == "stay" || strat == "change")
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

	if (games == 0 || fault || doors < open_doors + 2)
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

		for (auto &game : game_list)
		{
			game.run_game();
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
		auto const win_percent{ wins / games };
		auto const loss_percent{ losses / games };

		std::cout << "Out of " << games << " game(s) you won "
			<< wins << " which is "<< win_percent*100 <<"%. or to meet spec"<<  << std::endl;
		assert(win_percent + loss_percent > .999999 && win_percent + loss_percent < 1.000001);
	}
	return 0;
}