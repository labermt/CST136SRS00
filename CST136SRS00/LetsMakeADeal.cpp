#include "stdafx.h"
#include <random>
#include <cassert>
#include "LetsMakeADeal.h"

std::default_random_engine generator;

LetsMakeADeal::LetsMakeADeal(const int doors, const int open, const bool plan) : doors_{ doors }, disclosed_{ open }, swap_{ plan }
{ }

const bool LetsMakeADeal::play()
{
	std::uniform_int_distribution<int> distribution(1, doors_);
	auto winningdoor = distribution(generator);
	auto mydoor = distribution(generator);

	if (!swap_)
	{
		if (winningdoor == mydoor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (winningdoor == mydoor)
		{
			return false;
		}
		else
		{
			const auto pickedDoor{ 1 };
			std::uniform_int_distribution<int> newchance(1, doors_ - (disclosed_ + pickedDoor));
			winningdoor = newchance(generator);
			mydoor = newchance(generator);
			if (winningdoor == mydoor)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	assert(false); //if we've hit this, some logic went wrong
}