#pragma once


class LetsMakeADeal
{
private:
	int doors_{ 5 };
	int disclosed_{ 2 };
	bool swap_{ false };

public:
	LetsMakeADeal(const int doors, const int open, const bool plan);

	bool play();
};