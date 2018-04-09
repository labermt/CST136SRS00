#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


unsigned LetsMakeADeal::get_random_door_index(unsigned max_door) const
{
	auto result{0};
	// generate random number
	//assign it to result
	//while value @ result == car repeat steps
	//return result
	return result;
}

void LetsMakeADeal::set_prize(std::vector<unsigned> game_instance, unsigned const location)
{
	
}

LetsMakeADeal::LetsMakeADeal(unsigned doors, unsigned open_doors, std::string strat) :
	doors_{ doors }, open_doors_{ open_doors }
{
	if (strat.compare("stay")) {strat_ = stay;}
	else {strat_ = change;}
}

bool LetsMakeADeal::run_game()
{
	std::vector<unsigned> game_instance{doors_, goat};
	set_prize(game_instance, get_random_door_index(doors_));
	// get random number between 0 and total doors
	//
	auto result = false;

	return result;
}