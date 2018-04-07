#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
private:
	int numDoors_ = 3;
	int numDisclose_ = 1;
	std::vector<int> doors_;

public:
	LetsMakeADeal(int numDoors, int numDisclose);

public:
	void setCarDoor();

};
