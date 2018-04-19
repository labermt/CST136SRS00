#pragma once
#include <vector>
class LetsMakeADeal
{
public:
	enum class Strategy { kUnknown, kSwitch, kStay }; // 'k' lets you use switch 
	enum class prize {goat, car, opened};
	enum class result {win, lose};

	int randomDoor() const;
	LetsMakeADeal(int numOfDoors, int openDoors, Strategy strategy);

	result result_{};
	result getResult() const;

	void playGame(); 

private: 
	bool stay_ = true;  // switch or stay doors, run at plaay game
	int chosenDoor_{};
	int guess_{ -1 };
	const int numOfDoors_{}; // start amount of doors
	const int openDoors_{}; // how many doors to open or predisclose 
	const Strategy strategy_; 
	
	void guessDoor(); 
	void openDoors(); 
	std::vector<prize> doors_{}; 
};

