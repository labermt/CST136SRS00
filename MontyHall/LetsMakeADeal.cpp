#include "stdafx.h"

#include <vector>
#include <random>

#include "LetsMakeADeal.h"

LetsMakeADeal::LetsMakeADeal(const int& doors, const int& revealed, const Strategy& strat):
	doors_{ doors }, revealed_{ revealed }, strat_{ strat }
{}

bool LetsMakeADeal::simulateDeal() const
{
	
}

int LetsMakeADeal::randomDoor(const int doors)
{
	std::random_device randDoor;  
	std::mt19937 seed(randDoor());
	std::uniform_int_distribution<> dis(0, doors-1);

	return dis(seed);
}


