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

void LetsMakeADeal::set_car()
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
	//TODO: understand how / why this works
	static std::random_device rd;
	static std::mt19937 gen(rd());
	//can this really be const when running the game multiple times?
	static std::uniform_int_distribution<> rand_door(0, doors_-1);
	
	auto const result = rand_door(gen);
	return result;
}

unsigned LetsMakeADeal::guess_door(std::vector<door_states> &game_instance) const
{
	//need to change this, unless 2 states can be stored in a vector? multi dimentional array?
	auto guess = get_rand_door();
	while (game_instance[guess] == opened)
	{
		guess = get_rand_door();
	}
	 return guess;
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
	std::vector<unsigned> guessed_doors{guess};
	for (unsigned i = 0; i < open_doors_; ++i)
	{
		open_random_door(game_instance);
	}
	auto won = false;
	if (strat_ == change)
	{
		guess = guess_door(game_instance);
		//untested code if this evaluates to true, it found the door number of guess to be in the guessed doors vector
		//and so it guesses again until it finds a door that isnt open, or hasn't been guessed yet.
		while (std::find(std::begin(guessed_doors), std::end(guessed_doors), guess) != std::end(guessed_doors) )
		{
			guess = guess_door(game_instance);
			guessed_doors.push_back(guess);
		}
	}
	if (game_instance[guess]==car)
	{
		won = true;
	}

	return won;
}

LetsMakeADeal::result LetsMakeADeal::get_result() const
{
	return result_;
}
