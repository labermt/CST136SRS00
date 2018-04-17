#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>
#include <iostream>


void LetsMakeADeal::open_doors_randomly()
{
	auto unavailable_doors{ 2 };
	if (door_collection_[guess_] == door_state::car)
	{
		unavailable_doors = 1;
	}

	auto doors_to_open{ doors_to_open_ };
	while (doors_to_open > 0)
	{
		for (auto i = 0; i < total_doors_; ++i)
		{
			if (door_collection_[i] == door_state::goat && i != guess_)
			{
				auto const check = (total_doors_ - unavailable_doors);
				if (get_rand_num(check) < doors_to_open)
				{
					door_collection_[i] = door_state::opened;
					--doors_to_open;
				}
				++unavailable_doors;
			}
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
		auto unavailable_doors{ 1 + doors_to_open_ };

		for (auto i = 0; i < total_doors_; ++i)
		{
			auto const check = total_doors_ - unavailable_doors;
			auto const probability = get_rand_num(check);
			if (i != guess_ && door_collection_[i] != door_state::opened)
			{
				if (probability == 0)
				{
					guess_ = i;
					break;
				}
				++unavailable_doors;
			}
		}
	}
	else
	{
		auto guess = get_rand_num(total_doors_);
		while (door_collection_[guess] == door_state::opened)
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
	run_game();
}

void LetsMakeADeal::display_help()
{
	std::cout << "\nThere was an error with your input. Please follow the guidelines below and rerun the program.\n\n"
		"Parameter format:\n'-d' for total doors,\n"
		"'-o' for doors to open, followed by a number,\n"
		"'-g' for games to run, followed by a number\n"
		"'-s' for strategy followed by either 'change' or 'stay'.\n\n"
		"Notes: \nparameters can be in any order,\ndoors, and open are optional parameters (they default to 3 and 1 respectivly),\n"
		"-games needs to be be > 0, \n"
		"if you provide doors and / or open parameters doors needs to be at least 2 more than open doors.\n\n"
		"Example: 'MontyHall.exe -g 100 -s stay -d 5 -o 2'" << std::endl;
}

void LetsMakeADeal::run_game()
{
	set_car();
	guess_door();
	open_doors_randomly();
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
