#pragma once
class LetsMakeADeal
{
	
public:
	LetsMakeADeal();
	virtual ~LetsMakeADeal();

	LetsMakeADeal(const int total_doors, const int open_doors, const bool switch_strategy, const float win_probability)
		: totalDoors(total_doors),
		  openDoors(open_doors),
		  switchStrategy(switch_strategy),
		  winProbability(win_probability)
	{
	}

	const int totalDoors{3};
	const int openDoors{1};
	bool switchStrategy;
	float winProbability;
};

