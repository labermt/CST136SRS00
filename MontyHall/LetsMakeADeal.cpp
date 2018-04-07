#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


LetsMakeADeal::LetsMakeADeal(unsigned doors, unsigned open_doors) :
	doors_{ doors },
	open_doors_{ open_doors },
	length_{ doors_ - open_doors_ },
	total_doors_{length_,0}
{
	std::uniform_int_distribution<int> car(0, length_);
	// set index @ random number generated car = 1 representing the car
}

bool LetsMakeADeal::run_game()
{
	// get random number between 0 and total doors
	//
	auto result = false;

	return result;
}