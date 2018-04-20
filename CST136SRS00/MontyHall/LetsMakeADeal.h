#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>


class LetsMakeADeal
{
public:
enum class switchOrStay { unknown, noChange, change }; 
enum class outcome{ car, goat, open};
private: 
	int doorsAvailable_;
	int doorsRevealed_; 
	switchOrStay switchOrStay_;
	std::vector <outcome> doors_;

public:
	LetsMakeADeal(int doorsAvailable, int doorsRevealed, switchOrStay strategy);
	outcome gameInstance();
};

