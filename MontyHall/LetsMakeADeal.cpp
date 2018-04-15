#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>


LetsMakeADeal::LetsMakeADeal(int numOfDoors, int openDoors, const Strategy strategy) :
	numOfDoors_{ numOfDoors },
	openDoors_{ openDoors },
	chosenDoor_{ randomDoor() },
	strategy_{ strategy },
	finalLength_{ 0 }
	{
		if (numOfDoors > openDoors)
		{
			finalLength_ = numOfDoors - openDoors;
		}
	for (int i{}; i < finalLength_;i++)
	{
		doors_.push_back( prize::goat);// this puts a goat in each door
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

void LetsMakeADeal::playGame()
{
	guessDoor(); 
	for (auto i{ 0 }; i < openDoors_; i++)
	{
		openDoors();
	}
	if (strategy_== Strategy::kSwitch)
	{
		guessDoor(); 
	}
	if (doors_ [guess_] == prize::car)
	{
		result_ = result::win; 
	}
	else
	{
		result_ = result::lose; 
	}
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

