#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice {stay, willswitch};
	enum class prize {goat, open, car};

private:
	const size_t numDoors_;
	const size_t numDisclose_;
	const size_t selectDoor_;
	const size_t carDoor_;
	const choice strategy_;
	std::vector<prize> doors_{};

public:
	LetsMakeADeal(size_t , size_t , choice );

public:
	prize runGame();

private:
	static size_t randomGen(size_t);
};
