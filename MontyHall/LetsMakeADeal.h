#pragma once
#include <vector>
class LetsMakeADeal
{

public:
	enum class Strategy { kUnknown, kSwitch, kStay }; // 'k' lets you use switch 
	int randomDoor() const;
	LetsMakeADeal(size_t numOfDoors, size_t openDoors, Strategy strategy);
	enum class prize {goat, car, opened};
	prize playGame(); 


private: 
	bool stay_ = true;  // switch or stay doors, run at plaay game
	size_t chosenDoor_{};
	const size_t numOfDoors_{}; // start amount of doors
	const size_t openDoors_{}; // how many doors to open or predisclose 
	const size_t finalLength_; // how many doors you wind up with
	const Strategy strategy_; 
	int guess_; 
	void guessDoor(); 
	void openDoors(); 
	std::vector<prize> doors_{finalLength_}; 

};

