#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>
#include <iostream>


void LetsMakeADeal::open_random_door()
{
	auto const numer = open_doors_ * 1.0;
	auto const denom = doors_ * 1.0;
	auto door_index{ 0 };
	auto opened_doors{ 0 };

	for (auto &door : game_)
	{
		if (door == door_states::goat && door_index != guess_)
		{
			if ((numer - opened_doors) / (denom - door_index) == 0)
			{
				break;
			}
			auto const final_num =  (numer - opened_doors) / (denom - opened_doors);
			if (get_rand_door() - door_index <= final_num)
			{
				door = door_states::opened;
				++opened_doors;
			}
		}
		++door_index;
	}
}

int LetsMakeADeal::get_rand_door() const
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> rand_door(0, doors_ - 1);

	auto const result = rand_door(gen);
	return result;
}

void LetsMakeADeal::guess_door()
{
	if (guess_ >= 0)
	{
		auto door_index{0};
		auto const check = ( open_doors_ / doors_);
		for(auto &door : game_)
		{
			if (door != door_states::opened && (get_rand_door() / doors_) <= check)
			{
				guess_ = door_index;
				break;
			}
			++door_index;
		}
	}
	else
	{
		auto guess = get_rand_door();
		while (game_[guess] == door_states::opened || guess_ == guess)
		{
			guess = get_rand_door();
		}
		guess_ = guess;
	}
}

LetsMakeADeal::LetsMakeADeal(int const doors, int const open_doors, std::string const strat) :
	doors_{ doors }, open_doors_{ open_doors }
{
	if (strat.compare("stay") == 0)
	{
		strat_ = strategy::stay;
	}
	else
	{
		strat_ = strategy::change;
	}
	game_.assign(doors, door_states::goat);
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
	game_[get_rand_door()] = door_states::car;
	guess_door();
	for (auto i = 0; i < open_doors_; ++i)
	{
		open_random_door();
	}
	if (strat_ == strategy::change)
	{
		guess_door();
	}
	if (game_[guess_] == door_states::car)
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
