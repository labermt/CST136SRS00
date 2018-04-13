#include "stdafx.h"
#include <random>
#include "LetsMakeADeal.h"

std::default_random_engine generator;

LetsMakeADeal::LetsMakeADeal(const int doors, const int open, const bool plan) : doors_{ doors }, disclosed_{ open }, swap_{ plan }
{

}

bool LetsMakeADeal::play()
{
	std::uniform_int_distribution<int> distribution(1, doors_);
	int winningdoor = distribution(generator);
	int mydoor = distribution(generator);

	if (!swap_)
	{
		if (winningdoor == mydoor)
		{
			return true;
		}
		else if (winningdoor != mydoor)
		{
			return false;
		}
	}
	else if (swap_)
	{
		if (winningdoor == mydoor)
		{
			return false;
		}
		else if (winningdoor != mydoor)
		{
			std::uniform_int_distribution<int> newchance(1, doors_ - disclosed_);
			winningdoor = newchance(generator);
			mydoor = newchance(generator);
			if (winningdoor == mydoor)
			{
				return true;
			}
			else if (winningdoor != mydoor)
			{
				return false;
			}
		}
	}

}