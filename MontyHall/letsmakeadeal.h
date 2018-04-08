#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice {stay, willswitch};
	enum class prize {closed, open, car};

private:
	const size_t numDoors_{ 3 };
	const size_t numDisclose_{ 1 };
	const size_t carDoor_;
	const size_t selectDoor_;
	const choice strategy_{ choice::stay };
	std::vector<prize> doors_{};

public:
	LetsMakeADeal(size_t numDoors, size_t numDisclose, choice strategy);

public:
	prize runGame();

private:
	static size_t randomGen(size_t maxNum);
};
