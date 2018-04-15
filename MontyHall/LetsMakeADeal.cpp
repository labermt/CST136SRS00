#include "stdafx.h"

#include <random>
#include "gsl.h"

#include "LetsMakeADeal.h"

LetsMakeADeal::LetsMakeADeal(const int& doors, const int& disclose, const Strategy& strat) :
	doors_{ doors }, disclose_{ disclose }, strat_{ strat }
{}

bool LetsMakeADeal::simulateDeal() const
{
	const auto carDoor{ randomDoor(doors_) };
	const auto initialDoor{ randomDoor(doors_) };
	auto win{ false };

	switch (strat_)
	{
	case Strategy::kKeep:
	{
		if (initialDoor == carDoor)
		{
			win = true;
		}
		break;
	}
	case Strategy::kTrade:
	{
		if (initialDoor != carDoor)
		{
			win = true;
		}
		break;
	}
	case Strategy::kError:
		win = false;
		break;
	}

	Ensures(strat_ == Strategy::kKeep || strat_ == Strategy::kTrade); //stuff that should never happen

	return win;
}

int LetsMakeADeal::randomDoor(const int doors) const
{
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<int> const randDoor(0, doors);

	return randDoor(gen);
}
