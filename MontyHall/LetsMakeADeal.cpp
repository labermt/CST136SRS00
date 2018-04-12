#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <vector>
#include <random>


void LetsMakeADeal::open_random_door()
{
	auto door{ get_rand_door() };
	while (game_[door] != door_states::goat)
	{
		door = get_rand_door();
	}

	game_[door] = door_states::opened;
}

void LetsMakeADeal::set_car()
{
	game_[get_rand_door()] = door_states::car;
}

unsigned LetsMakeADeal::get_rand_door() const
{
	 std::random_device rd;
	 std::mt19937 gen(rd());
	 std::uniform_int_distribution<> rand_door(0, doors_ - 1);

	auto const result = rand_door(gen);
	return result;
}

void LetsMakeADeal::guess_door() 
{
	auto guess = get_rand_door();
	while (game_[guess] == door_states::opened || guess_ == guess)
	{
		guess = get_rand_door();
	}
	guess_= guess;
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

bool LetsMakeADeal::run_game()
{
	set_car();
	for (auto i = 0; i < open_doors_; ++i)
	{
		open_random_door();
	}
	guess_door();
	auto won = false;
	if (strat_ == strategy::change)
	{
		guess_door();
	}
	if (game_[guess_] == door_states::car)
	{
		won = true;
	}

	return won;
}

LetsMakeADeal::result LetsMakeADeal::get_result() const
{
	return result_;
}
