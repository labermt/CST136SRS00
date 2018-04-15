#pragma once
#include <vector>
class LetsMakeADeal
{

public:
	enum class Strategy { kUnknown, kSwitch, kStay }; // 'k' lets you use switch 
	int randomDoor() const;
	LetsMakeADeal(int numOfDoors, int openDoors, Strategy strategy);
	enum class prize {goat, car, opened};
	enum class result {win, lose};
	result result_{};

	void playGame(); 
	
private: 
	bool stay_ = true;  // switch or stay doors, run at plaay game
	int chosenDoor_{};
	int finalLength_; // how many doors you wind up with
	const int numOfDoors_{}; // start amount of doors
	const int openDoors_{}; // how many doors to open or predisclose 
	const Strategy strategy_; 
	
	int guess_{ - 1 };
	void guessDoor(); 
	void openDoors(); 
	std::vector<prize> doors_{}; 

};

