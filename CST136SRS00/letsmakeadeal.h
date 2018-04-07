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
	std::vector<bool> doors_ {};

public:
	choice RunGame(int numDoors, int numDisclose, choice choice);

};
