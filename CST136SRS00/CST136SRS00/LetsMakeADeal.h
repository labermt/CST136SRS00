#pragma once
#include "LetsMakeADeal.h"
#include <vector>

class LetsMakeADeal
{
private:
	unsigned numDoors;
	unsigned numDisclosedDoors;
	bool stay;
public:
	LetsMakeADeal(unsigned numDoors_, unsigned numDisclosedDoors_, bool stay_);
	bool getResult();
	~LetsMakeADeal();
};

