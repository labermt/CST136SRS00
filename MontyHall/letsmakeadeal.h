#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice {stay = 0, willswitch};

private:
	int numDoors_ = 3;
	int numDisclose_ = 1;
	choice strategy_ = choice::stay;
	std::vector<bool> doors_ {};

public:
	LetsMakeADeal(int numDoors, int numDisclose, choice strategy);

public:
	choice RunGame();

};
