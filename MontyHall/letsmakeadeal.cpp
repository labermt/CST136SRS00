#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(int numDoors, int numDisclose, choice strategy):
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

LetsMakeADeal::choice LetsMakeADeal::RunGame()
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	std::default_random_engine generator;
	const std::uniform_int_distribution<int> distribution(0, numDoors_ - 1);

	const int selectDoor = distribution(generator);

	// TODO: Finish Algorithm below
	for (size_t i{ 0 }; i < numDisclose_; i++)
	{
		// Select a door to disclose
		const int discDoor = distribution(generator);
		
		while (doors_[discDoor] != 1)
		{
			
		}
	}

	return choice::stay;
}

