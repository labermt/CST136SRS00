#pragma once

#include <random>

class LetsMakeADeal
{
	
public:
	LetsMakeADeal();
	virtual ~LetsMakeADeal();

	LetsMakeADeal(const int total_doors, const int open_doors, const bool switch_strategy)
		: totalDoors(total_doors), openDoors(open_doors), switchStrategy(switch_strategy),
		  winProbability(0)
	{
	}

	bool predictWin(int winningDoor, int winningDoor2);
	
private: 
	int totalDoors;
	int openDoors;
	bool switchStrategy;
	float winProbability;

};

