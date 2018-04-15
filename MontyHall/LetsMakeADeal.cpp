#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(int numOfDoors, int openDoors, const Strategy strategy) :
	numOfDoors_{ numOfDoors },
	openDoors_{ openDoors },
	chosenDoor_{ randomDoor() },
	strategy_{ strategy }
	{
	for (int i{}; i < numOfDoors; i++)
	{
		doors_.push_back( prize::goat);// this puts a goat in each door
	}
	doors_[randomDoor()] = prize::car;
	guessDoor();
}

int LetsMakeADeal::randomDoor() const
{	
	//taken from http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, numOfDoors_ - 1);
	return dis(gen);
}

void LetsMakeADeal::playGame()
{
	openDoors();
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

LetsMakeADeal::result LetsMakeADeal::getResult() const
{
	return result_;
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
	auto toOpen{ randomDoor() };
	auto doorTally{ 0 };
	while (doorTally < openDoors_)
	{
		while (doors_[toOpen] == prize::opened || guess_ == toOpen || doors_[toOpen] == prize::car) // guess_ is the contestants guess, guess picking a random door to open
		{
			toOpen = randomDoor();
		}
		doors_[toOpen] = prize::opened;
		doorTally++;
	}
}

