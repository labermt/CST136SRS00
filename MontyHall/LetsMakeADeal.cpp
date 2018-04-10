#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


void LetsMakeADeal::open_random_door(std::vector<door_states>& game_instance)
{
	auto door{get_rand_num()};
	while (game_instance[door]!= goat)
	{
		door = get_rand_num();
	}

	game_instance[door] = opened;
}

void LetsMakeADeal::set_car(std::vector<door_states> &game_instance)
{
	// not sure if this and the function can be const or not? Resharper lies??
	auto door{get_rand_num()};
	while(game_instance[door] != goat)
	{
		door = get_rand_num();
	}
	game_instance[door] = car;
}

unsigned LetsMakeADeal::get_rand_num() const
{
	std::random_device rd;
	std::mt19937 gen(rd);
	//can this really be const when running the game multiple times?
	std::uniform_int_distribution<> const rand_door(0, doors_);
	
	auto const result = rand_door(gen);
	return result;
}

LetsMakeADeal::LetsMakeADeal(unsigned const doors, unsigned const open_doors, std::string const strat) :
	doors_{ doors }, open_doors_{ open_doors }
{
	if (strat.compare("stay") == 0)
	{
		strat_ = stay;
	}
	else
	{
		strat_ = change;
	}
}

bool LetsMakeADeal::run_game()
{
	std::vector<door_states> game_instance{doors_, goat};
	set_car(game_instance);
	// get random number between 0 and total doors
	//
	auto result = false;

	return result;
}