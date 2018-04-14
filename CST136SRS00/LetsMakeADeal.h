#pragma once


class LetsMakeADeal
{
private:
	int doors_{ 3 };
	int disclosed_{ 1 };
	bool swap_{ false };

public:
	LetsMakeADeal(const int doors, const int open, const bool plan);

	bool play();
};