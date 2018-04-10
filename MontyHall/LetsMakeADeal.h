#pragma once
#include "Strategy.h"

class LetsMakeADeal
{
private:
	const int doors_;
	const int reveal_;
	const Strategy strategy_;
public:
	LetsMakeADeal(const int& doors, const int& reveal, const Strategy& strategy);
	bool simulateGame() const;
private:
	static int getRandomInt(const int lower, const int upper);
};