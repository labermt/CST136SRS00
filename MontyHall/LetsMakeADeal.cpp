#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


LetsMakeADeal::LetsMakeADeal(unsigned doors, unsigned open_doors, std::string strat) :
	doors_{ doors }, open_doors_{ open_doors }, strat_{strat}
{
}

bool LetsMakeADeal::run_game()
{
	std::vector<unsigned> total_doors{doors_};
	// get random number between 0 and total doors
	//
	auto result = false;

	return result;
}