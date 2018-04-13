#pragma once
#include <vector>
class LetsMakeADeal
{
public:
	int randomDoor() const;
	LetsMakeADeal(size_t numOfDoors, size_t openDoors);
	enum class behindTheDoor {goat, car};
	behindTheDoor makeDeal(bool stay); 

private: 
	const size_t numOfDoors_{}; //start amount of doors
	const size_t openDoors_{}; //how many doors to open or predisclose 
	const size_t finalLength_; //how many doors you wind up with
	bool stay_ = true;  //switch or stay doors, run at rungame
	size_t chosenDoor_; 
	std::vector<behindTheDoor> doors_{finalLength_}; 
};

