#include "stdafx.h"
#include "letsmakeadeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal( const size_t numDoors, const size_t numDisclose, const choice strategy ):
numDoors_{numDoors},
numDisclose_{numDisclose},
selectDoor_{randomGen()},
strategy_{strategy} 
{
	for ( size_t i{ 0 }; i < numDoors; i++ )
	{
		doors_.push_back(prize::goat);
	}

	doors_[randomGen()] = prize::car;
}

LetsMakeADeal::prize LetsMakeADeal::runGame()
{
	// Open numDisclose_ number of doors
	for ( size_t i{ 0 }; i < numDisclose_; i++ )
	{
		auto discloseDoor = randomGen();
		
		while ( doors_[discloseDoor] == prize::car || 
				doors_[discloseDoor] == prize::open || 
				discloseDoor == selectDoor_ )
		{
			discloseDoor = randomGen();
		}
		doors_[discloseDoor] = prize::open;
	}

	auto result = selectDoor_;

	// If the switch option is set, pick another unopened door
	if ( strategy_ == choice::willswitch )
	{
		while ( result == selectDoor_ || doors_[result] == prize::open )
		{
			result = randomGen();
		}
	}

	return doors_[result];
}

size_t LetsMakeADeal::randomGen() const
{
	// Create random number generator and generate a number between 0 and numDoors - 1
	static std::random_device rd;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
	const std::uniform_int_distribution<size_t> dis( 0, numDoors_ );

	return dis( gen );
}

