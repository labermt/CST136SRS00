#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal(int doorsAvailable, int doorsRevealed, switchOrStay strategy):
	doorsAvailable_{ doorsAvailable },
	doorsRevealed_{ doorsRevealed }, 
	switchOrStay_{ strategy }
{
}

LetsMakeADeal::outcome LetsMakeADeal::gameInstance()
{
	outcome result = outcome::goat;
	std::random_device assignChoice1;
	std::mt19937 gen(assignChoice1());
	std::uniform_int_distribution<> dis(0, doorsAvailable_-1);	
	//Assign all items in vector to have goats
	doors_.assign(doorsAvailable_, outcome::goat);
	// assign car to one door randomly
	doors_[dis(gen)] = outcome::car;
	//Constestant door picked at random
	const int contestantDoor = dis(gen);
	for (int i = 0; i < doorsRevealed_; i++)
	{
		auto guess{ dis(gen) };
		while (doors_[guess] != outcome::goat || guess == contestantDoor)
		{
			guess = dis(gen);
		}
		doors_[guess] = outcome::open;
	}
	//switch or stay - reveal door person chose or switched to new door 
	if (switchOrStay_ == switchOrStay::change)
	{
		auto newContestantDoor{ 0 };
		while (doors_[newContestantDoor] == outcome::open || newContestantDoor == contestantDoor)
		{
			newContestantDoor = dis(gen);
			result = doors_[newContestantDoor];
		}
	}
	else
		{
		result = doors_[contestantDoor];
		}
	
	return result; 
	};
