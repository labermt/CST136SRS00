#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal( const size_t numDoors, const size_t numDisclose, const choice strategy ):
numDoors_{numDoors},
numDisclose_{numDisclose},
selectDoor_{randomGen(numDoors)},
carDoor_{randomGen(numDoors)},
strategy_{strategy} 
{
	for ( size_t i{ 0 }; i < numDoors; i++ )
	{
		doors_.push_back(prize::goat);
	}

	doors_[carDoor_] = prize::car;
}

LetsMakeADeal::prize LetsMakeADeal::runGame()
{
	// Open numDisclose_ number of doors
	for (size_t i{ 0 }; i < numDisclose_; i++)
	{
		auto discloseDoor = randomGen(numDoors_);
		
		while ( doors_[discloseDoor] == prize::car || 
				doors_[discloseDoor] == prize::open || 
				discloseDoor == selectDoor_ )
		{
			discloseDoor = randomGen(numDoors_);
		}
		doors_[discloseDoor] = prize::open;
	}

	auto result = selectDoor_;

	// If the switch option is set, pick another unopened door
	if ( strategy_ == choice::willswitch )
	{
		while ( result == selectDoor_ || doors_[result] == prize::open )
		{
			result = randomGen(numDoors_);
		}
	}

	return doors_[result];
}

size_t LetsMakeADeal::randomGen(const size_t numDoors)
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis( 0, numDoors - 1 );

	return dis( gen );
}

std::ostream& operator<<(std::ostream& os, const LetsMakeADeal::choice& choice)
{
	if ( choice == LetsMakeADeal::choice::stay)
	{
	os << "stay";
	}
	else
	{
	os << "switch";
	}
	return os;
}
