#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>
#include <iostream>

LetsMakeADeal::LetsMakeADeal(const size_t numDoors, const size_t numDisclose, const choice strategy) :
	numDoors_{ numDoors },
	numDisclose_{ numDisclose },
	selectDoor_{ randomGen(numDoors) },
	carDoor_{ randomGen(numDoors) },
	strategy_{ strategy },
	result_{}
{
	for (size_t i{ 0 }; i < numDoors; i++)
	{
		doors_.push_back(prize::goat);
	}

	doors_[carDoor_] = prize::car;

	runGame();
}

LetsMakeADeal::prize LetsMakeADeal::getResult() const
{
	return result_;
}

void LetsMakeADeal::showUsage()
{
	std::cout << std::endl <<
		"Incorrect Parameters!\n"
		"\n"
		"\t Usage:\n"
		"\t -d,--doors			Number of doors (default = 3)\n"
		"\t -o,--open			Number of doors to open (default = 1)\n"
		"\t -i,--instances			Number of game instances to run (default = 1)\n"
		"\t -s,--strategy			Selected strategy (options: stay, switch; default = stay)\n"
		"\n"
		"\t Example(s):\n"
		"\n"
		"\t MontyHall.exe --doors 3 --open 1 --instances 100 --strategy stay\n"
		"\t MontyHall.exe -d 5 -o 3 -s switch --instances 1000\n"
		"\t MontyHall.exe -d 30 --open 2\n"
		"\n"
		"\t Important:\n"
		"\n"
		"\t Instances and strategy must be entered as parameters or this help will display.\n"
		"\t The the following must be true: doors > (open + 2).\n"
		"\n"
		"\t See README.md for details.\n"
		<< std::endl;
}

void LetsMakeADeal::runGame()
{
	auto discloseTally{ 0 };
	auto cantOpen{ 2 };

	if (selectDoor_ == carDoor_)
	{
		cantOpen = 1;
	}

	// Open numDisclose_ number of doors
	for (size_t i{ 0 }; i < numDoors_; i++)
	{
		if (doors_[i] != prize::car
			&& i != selectDoor_
			&& randomGen(numDoors_ - cantOpen - discloseTally) < numDisclose_)
		{
			doors_[i] = prize::open;
			discloseTally++;
			numDisclose_--;
		}
		if (numDisclose_ == 0)
		{
			break;
		}
	}

	result_ = doors_[selectDoor_];

	// If the switch option is set, pick another unopened door
	if (strategy_ == choice::change)
	{
		if (carDoor_ != selectDoor_)
		{
			cantOpen = 1;
		}

		cantOpen += discloseTally;

		for (size_t i{ 0 }; i < numDoors_; i++)
		{
			if (doors_[i] != prize::open
				&& i != selectDoor_
				&& randomGen(numDoors_ - cantOpen) < 1)
			{
				result_ = doors_[i];
				break;
			}
		}
	}
}

size_t LetsMakeADeal::randomGen(const size_t numDoors)
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, numDoors - 1);

	return dis(gen);
}
