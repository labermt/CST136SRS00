#pragma once
#include "letsmakeadeal.h"
#include <vector>

class LetsMakeADeal
{
public:
	enum class choice { stay, change, unselected };
	enum class prize { goat, open, car };

private:
	size_t const numDoors_;
	size_t numDisclose_;
	size_t const selectDoor_;
	size_t const carDoor_;
	choice const strategy_;

	prize result_;
	std::vector<prize> doors_{};

public:
	LetsMakeADeal(size_t, size_t, choice);

public:
	prize getResult() const;
	void runGame();
	void static showUsage();
	int checkDoors(choice);

private:
	static size_t randomGen(size_t);
};
