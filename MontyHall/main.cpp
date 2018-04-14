#include "stdafx.h"

#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>

#include <iostream>
#include <vector>
#include <sstream>
#include "gsl.h"

#include "LetsMakeADeal.h"

Strategy confirmStrat(int stratID)
{
	Strategy test{ Strategy::kError };

	Expects(stratID == 0 || stratID == 1) 
	{
		switch (stratID)
		{
		case 0:
		{
			test = Strategy::kKeep;
			break;
		}
		case 1:
		{
			test = Strategy::kTrade;
			break;
		}
		default:
			test = Strategy::kError;
			break;
		}
	}

	return test;
}

void simulateDeals(int argc, char* argv[])
{
	auto doorCount{ 3 };
	auto doorsOpen{ 1 };
	auto numDeals{ 1 };
	auto stratID{ 0 };
	auto currStrat{ Strategy::kError };
	auto dealInputError { false };

	Expects(argc >= 2)
	{
		for (auto i = 1; i < argc; i++)
		{
			std::istringstream gameInput(argv[i]); //toss all arguments into an basic input string stream to convert to usable values(int)

			Expects(i != 0 && argv[i] != nullptr)
			{
				switch (i)
				{
				case 1:
				{
					gameInput >> doorCount;
					Ensures(doorCount >= 3);
					break;
				}
				case 2:
				{
					gameInput >> doorsOpen;
					Ensures(doorsOpen == doorCount - 2);
					break;
				}
				case 3:
				{
					gameInput >> numDeals;
					Ensures(numDeals > 0);
					break;
				}
				case 4:
				{
					gameInput >> stratID;
					Expects(stratID == 0 || stratID == 1);
					currStrat = confirmStrat(stratID);
					Ensures(currStrat != Strategy::kError);
					break;
				}
				default:
					dealInputError = true;  //basically this should only be hit if argc >= 5
					break;
				}
			}
		}
	}
	if(dealInputError == true)
	{
		//command line help goes here. ie. make sure there is a space between each argument, etc.
		//Command line take the parameters in order: int doorCount -> int doorsOpen -> int numDeals -> int currStrat 0 = keep, 1 = trade
	}
	else
	{
		Expects(dealInputError == false)
		{
			std::vector<const LetsMakeADeal> dealSim;

			auto carsWon{ 0 }, goatsWon{0}; //to compare the probability later

			for(auto i = 0; i < numDeals; i++)
			{
				dealSim.push_back(LetsMakeADeal{ doorCount, doorsOpen, currStrat }); //adds numDeals LetsMakeADeal(s) into the dealSim vector
			}
			for(auto deal : dealSim)
			{
				Expects(deal != nullptr)
				{
					if
				}
			}


		}
	}

}

int main(int argc, char* argv[])
{
	simulateDeals(argc, argv);

    return 0;
}
