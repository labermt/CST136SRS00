#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(const size_t numDoors, const size_t numDisclose, const choice strategy) :
	numDoors_{ numDoors },
	numDisclose_{ numDisclose },
	selectDoor_{ randomGen(numDoors - 1) },
	carDoor_{ randomGen(numDoors - 1) },
	strategy_{ strategy }
{
	for (size_t i{ 0 }; i < numDoors; i++)
	{
		doors_.push_back(prize::goat);
	}

	doors_[carDoor_] = prize::car;
}

LetsMakeADeal::prize LetsMakeADeal::runGame()
{
	auto discloseTally{ numDisclose_ };

	// Open numDisclose_ number of doors
	for (size_t i{ 0 }; i < numDoors_; i++)
	{
		auto cantOpen{2};

		if (selectDoor_ == carDoor_)
		{
			cantOpen = 1;
		}

		// for each door, decide to open based on p choose k
		if (doors_[i] != prize::car
			&& i != selectDoor_
			&& randomGen(numDoors_ - i - cantOpen) <= discloseTally)
		{
			doors_[i] = prize::open;
			discloseTally--;

			//Once all doors are selected, exit for loop
			if (discloseTally == 0)
			{
				break;
			}
		}
	}

	auto result{ selectDoor_ };

	// If the switch option is set, pick another unopened door
	if (strategy_ == choice::change)
	{
		for (size_t i{ 0 }; i < numDoors_; i++)
		{
			if (doors_[i] != prize::open
				&& i != selectDoor_
				&& randomGen(numDoors_ - numDisclose_ - 1) < 1)
			{
				result = i;
				break;
			}
		}
	}

	return doors_[result];
}

size_t LetsMakeADeal::randomGen(const size_t numDoors)
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, numDoors);

	return dis(gen);
}

std::ostream& operator<<(std::ostream& os, const LetsMakeADeal::choice& choice)
{
	if (choice == LetsMakeADeal::choice::stay)
	{
		os << "stay";
	}
	else
	{
		os << "switch";
	}
	return os;
}
