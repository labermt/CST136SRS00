#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


void LetsMakeADeal::open_random_door(std::vector<door_states> &game_instance)
{
	auto door{get_rand_door()};
	while (game_instance[door]!= goat)
	{
		door = get_rand_door();
	}

	game_instance[door] = opened;
}

void LetsMakeADeal::set_car(std::vector<door_states> &game_instance)
{
	// not sure if this and the function can be const or not? Resharper lies??
	auto door{get_rand_door()};
	while(game_instance[door] != goat)
	{
		door = get_rand_door();
	}
	game_instance[door] = car;
}

unsigned LetsMakeADeal::get_rand_door() const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	//can this really be const when running the game multiple times?
	std::uniform_int_distribution<> const rand_door(0, doors_);
	
	auto const result = rand_door(gen);
	return result;
}

void LetsMakeADeal::guess_door(std::vector<door_states>& game_instance)
{
	//need to change this, unless 2 states can be stored in a vector? multi dimentional array?
	auto guess = get_rand_door();
	while (game_instance[guess] == opened || game_instance[guess] == guessed)
	{
		guess = get_rand_door();
	}
	 game_instance[guess] == guessed;
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
	auto guess = guess_door(game_instance);
	for (auto i = 0; i < open_doors_; ++i)
	{
		open_random_door(game_instance);
	}
	auto result = false;
	if (strat_ == change)
	{
		guess = guess_door(game_instance);
	}
	if (game_instance[guess]==car)
	{
		result = true;
	}

	return result;
}