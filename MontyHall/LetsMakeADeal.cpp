#include "stdafx.h"
#include <random>
#include <vector>
#include "LetsMakeADeal.h"

LetsMakeADeal::LetsMakeADeal(const int& doors, const int& reveal, const Strategy& strategy) : 
numDoors_{ doors },
reveal_{ reveal },
strategy_{ strategy }
{
	
}

bool LetsMakeADeal::simulateGame() const
{
	// Set the car door & the initially selected door, plus create a vector of every door storing whether or not it is open
	const auto carDoor{ getRandomInt(0, numDoors_) };
	auto selDoor{ getRandomInt(0, numDoors_) };
	std::vector<bool> doors(numDoors_);
	auto doorsOpened = 0;

	// Continue to open doors until the amount asked for is reached
	while(doorsOpened < reveal_)
	{
		const auto doorToOpen{ getRandomInt(0, numDoors_) };
		if(doorToOpen != carDoor && doorToOpen != selDoor && !doors[doorToOpen])
		{
			doors[doorToOpen] = true;
			doorsOpened++;
		}
	}

	// If the user wants to test the Switch strategy, find a random, unopened door other than the selected door
	if(strategy_ == Strategy::kSwitch)
	{
		auto newSelDoor = selDoor;
		while(newSelDoor == selDoor || doors[newSelDoor])
		{
			newSelDoor = getRandomInt(0, numDoors_);
		}
		selDoor = newSelDoor;
	}

	return selDoor == carDoor;
}

int LetsMakeADeal::getRandomInt(const int lower, const int upper)
{
	static std::mt19937 seed{ 42 };
	const std::uniform_int_distribution<> dis(lower, upper - 1); // Open-closed; not pandering to Mitch, don't worry 'bout it
	return dis(seed);
}
