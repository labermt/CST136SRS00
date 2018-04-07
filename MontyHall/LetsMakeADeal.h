#pragma once
#include <vector>

class LetsMakeADeal
{

private:
	unsigned doors_{3};
	unsigned open_doors_{1};
	unsigned length_{};
	std::vector<unsigned> total_doors_{};
	

public:
	LetsMakeADeal(unsigned doors, unsigned open_doors);
	bool run_game();
};

