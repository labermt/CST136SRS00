#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(unsigned numDoors, unsigned numDisclose, choice strategy):
numDoors_{numDoors},
numDisclose_{numDisclose},
strategy_{strategy}
{
	doors_.push_back(true); 

	//Populate vector with a 0 (goat) for each door
	for (size_t i{ 1 }; i < numDoors; i++)
	{
		doors_.push_back(false);
	}
}

unsigned LetsMakeADeal::RunGame()
{
	const unsigned selectDoor = randomGen(numDoors_);

	for (size_t i{ 0 }; i < numDisclose_; i++)
	{
		// Select a door to disclose
		unsigned discDoor = randomGen(numDoors_ - i);
		
		while (discDoor == doors_[0] || discDoor == selectDoor)
		{
			discDoor = randomGen(numDoors_ - i);
		}
		doors_.erase(doors_.begin + discDoor);
	}

	unsigned result = selectDoor;

	if (strategy_ == choice::willswitch)
	{
		while (result == selectDoor)
		{
			result = randomGen(doors_.size());
		}
	}

	return result;
}

unsigned LetsMakeADeal::randomGen(unsigned maxNum) 
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<> dis(0, maxNum);

	return dis(gen);
}

