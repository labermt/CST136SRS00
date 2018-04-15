#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>
#include <iostream>


void LetsMakeADeal::open_random_door()
{
	auto door_index{ 0 };
	auto unavailable_doors{ 2 };
	auto doors_to_open{ doors_to_open_ };

	if (door_collection_[guess_] == door_state::car)
	{
		unavailable_doors = 1;
	}

	for (auto &door : door_collection_)
	{
		if (door == door_state::goat && door_index != guess_)
		{
			auto const check = (total_doors_ - unavailable_doors);
			if (get_rand_num(check) < doors_to_open)
			{
				door = door_state::opened;
				--doors_to_open;
			}
			++unavailable_doors;
		}
		++door_index;
		if (doors_to_open == 0)
		{
			break;
		}
	}
}

int LetsMakeADeal::get_rand_num(int const max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> const rand_door(0, (max - 1));
	
	auto const result = rand_door(gen);
	return result;
}

void LetsMakeADeal::guess_door()
{
	if (guess_ >= 0)
	{
		auto door_index{ 0 };
		auto guessed_door{ 1 };
		
		for (auto &door : door_collection_)
		{
			auto const unavailable_doors{ guessed_door + doors_to_open_ + door_index };
			auto const check = total_doors_ - unavailable_doors +1 ;
			if (door_index != guess_ && door != door_state::opened && get_rand_num(check) == 0 )
			{
				guess_ = door_index;
				break;
			}
			if(door_index == guess_)
			{
				guessed_door = 0;
			}
			++door_index;
		}
	}
	else
	{
		auto guess = get_rand_num(total_doors_);
		while (door_collection_[guess] == door_state::opened )
		{
			guess = get_rand_num(total_doors_);
		}
		guess_ = guess;
	}
}

void LetsMakeADeal::set_car()
{
	door_collection_[get_rand_num(total_doors_)] = door_state::car;
}

LetsMakeADeal::LetsMakeADeal(int const doors, int const open_doors, std::string const strat) :
	total_doors_{ doors }, doors_to_open_{ open_doors }
{
	if (strat.compare("stay") == 0)
	{
		strat_ = strategy::stay;
	}
	else
	{
		strat_ = strategy::change;
	}
	door_collection_.assign(doors, door_state::goat);
}

void LetsMakeADeal::display_help()
{
	std::cout << "\nThere was an error with your input. Please follow the guidelines below and rerun the program.\n\n"
		"Parameter format:\n-doors followed by a number for the number of doors you would like in the game,\n"
		"-open followed by a number for the amount of doors you would like to open,\n"
		"-games followed by a number for the amount of games you would like to run,\n"
		"-strategy followed by either 'change' or 'stay' for your strategy of changing doors or not.\n\n"
		"Notes: \nparameters can be in any order,\n-doors , and -open are optional parameters (they default to 3 and 1 respectivly)\n"
		"-games needs to be be > 0, \n"
		"if you provide -doors and / or -open parameters doors needs to be +2 more than open doors otherwise, whats the point?\n"
		"Example: 'MontyHall.exe -games 100 -strategy stay -doors 5 -open 2'" << std::endl;
}

void LetsMakeADeal::run_game()
{
	set_car();
	guess_door();
	for (auto i = 0; i < doors_to_open_; ++i)
	{
		open_random_door();
	}
	if (strat_ == strategy::change)
	{
		guess_door();
	}
	if (door_collection_[guess_] == door_state::car)
	{
		result_ = result::won;
	}
	else
	{
		result_ = result::lost;
	}
}

LetsMakeADeal::result LetsMakeADeal::get_result() const
{
	return result_;
}
