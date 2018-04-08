#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(const size_t numDoors, const size_t numDisclose, choice strategy):
numDoors_{numDoors},
numDisclose_{numDisclose},
carDoor_{randomGen(numDoors)},
selectDoor_{randomGen(numDoors)},
strategy_{strategy}
{
	//Populate vector with a 0 (goat) for each door
	for (size_t i{ 0 }; i < numDoors; i++)
	{
		doors_.push_back(false);
	}

	//Place the car
	doors_[carDoor_] = true;
}

bool LetsMakeADeal::runGame()
{
	// Open all numDisclose_ number of doors and remove them from doors_
	for (size_t i{ 0 }; i < numDisclose_; i++)
	{
		auto discloseDoor = randomGen(numDoors_ - i);
		
		while (discloseDoor == carDoor_ || discloseDoor == selectDoor_)
		{
			discloseDoor = randomGen(numDoors_ - i);
		}
		doors_.erase(doors_.begin() + discloseDoor);
	}

	bool result = doors_[selectDoor_];

	// If the switch option is set, pick another unopened door
	if (strategy_ == choice::willswitch)
	{
		while (result == doors_[selectDoor_])
		{
			result = randomGen(doors_.size());
		}
	}

	return result;
}

size_t LetsMakeADeal::randomGen(const size_t maxNum) 
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, maxNum - 1);

	return dis(gen);
}

