#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>


LetsMakeADeal::LetsMakeADeal(size_t numOfDoors, size_t openDoors, const Strategy strategy) :
	numOfDoors_{ numOfDoors },
	openDoors_{ openDoors },
	finalLength_{ numOfDoors - openDoors },
	chosenDoor_{randomDoor()},
	strategy_ { strategy } 
{
	for (size_t i{}; i < finalLength_;i++)
	{
		doors_[i] = prize::goat;// this puts a goat in each door
	}
	doors_[randomDoor()] = prize::car;
}

int LetsMakeADeal::randomDoor() const
{	
	//taken from http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, finalLength_ - 1);
	return dis(gen);
}

LetsMakeADeal::prize LetsMakeADeal::playGame()
{
	// choose a door at random
	doors_[randomDoor()] = prize::car;
	guessDoor(); 
	// disclose the doors that does not have the car or the chosen door 
	openDoors();
	// if switch, then choose an available door (cannot be disclosed)
	if (strategy_== Strategy::kSwitch);
	{
		guessDoor(); 
	}
	
	// open door, return prize 


}

void LetsMakeADeal::guessDoor()
{
	auto guess = randomDoor(); 
	while (doors_[guess] == prize::opened || guess_ == guess)
	{
		guess = randomDoor();
	}
	guess_ = guess; 
}

void LetsMakeADeal::openDoors()
{
	auto guess = randomDoor(); 
	auto doorTally{ 0 };
	while (doorTally < openDoors_)
	{
		while (doors_[guess] == prize::opened || guess_ == guess)
		{
			guess = randomDoor();
		}
		doors_[guess] = prize::opened;
		doorTally++; 
	}
}

