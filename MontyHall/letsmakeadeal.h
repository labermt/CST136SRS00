#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice {stay = 0, willswitch};

private:
	unsigned numDoors_{ 3 };
	unsigned numDisclose_{ 1 };
	choice strategy_{ choice::stay };
	std::vector<bool> doors_ {};

public:
	LetsMakeADeal(unsigned numDoors, unsigned numDisclose, choice strategy);

public:
	unsigned RunGame();
	unsigned randomGen(unsigned maxNum);

};
