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
		doors_[i] = behindTheDoor::goat;// this puts a goat in each door
	}
	doors_[randomDoor()] = behindTheDoor::car;
}

int LetsMakeADeal::randomDoor() const
{	
	//taken from http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis(0, finalLength_ - 1);
	return dis(gen);
}

LetsMakeADeal::behindTheDoor LetsMakeADeal::playGame()
{

	auto result(behindTheDoor::goat);
	return result;
}


