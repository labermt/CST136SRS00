#pragma once
#include <vector>

class LetsMakeADeal
{

private:
	unsigned doors_{3};
	unsigned open_doors_{1};
	std::string strat_{};

public:
	LetsMakeADeal(unsigned doors, unsigned open_doors, std::string strat);
	bool run_game();
};