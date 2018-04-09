#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice {stay, willswitch};
	enum class prize {goat, open, car};

private:
	const size_t numDoors_{ 3 };
	const size_t numDisclose_{ 1 };
	const size_t selectDoor_;
	const choice strategy_{};
	std::vector<prize> doors_{};

public:
	LetsMakeADeal(size_t , size_t , choice );

public:
	prize runGame();

private:
	size_t randomGen() const;
};
