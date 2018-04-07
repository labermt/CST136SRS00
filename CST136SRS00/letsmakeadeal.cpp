#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(int numDoors, int numDisclose)
{
	//Populate vector with a 0 (goat) for each door
	for (int i{ 0 }; i < numDoors; i++)
	{
		doors_.push_back(0);
	}
	
	// Create random number generator and generate a number between 0 and numDoors - 1
	std::default_random_engine generator;
	const std::uniform_int_distribution<int> distribution(0, numDoors - 1);
	const int carDoor = distribution(generator);

	doors_[carDoor] = 1; //randomly select carDoor and add it to correct vector position as a 1

	for (int i{ 0 }; i < numDisclose; i++)
	{
		// Select a door to disclose
		const int discDoor = distribution(generator);
		
		while (doors_[discDoor] != 1)
		{
			
		}
	}
}

