#pragma once

class LetsMakeADeal
{
private:
	int doors_{ 3 };
	int disclosed_{ 1 };
	int instance_{};
	bool strat_{};

public:
	LetsMakeADeal(int door, int open, int times);


};