#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <numeric>

class LetsMakeADeal {

private:
	int numberOfDoors;
	int decideSwitchOrStay;		//1 for Switch; 2 for Stay
	int numberOfGames;
	int numberDoorsRevealed;
	int prizeDoor;
	std::vector<bool> revealedDoors; //stores doors to reveal

	enum decideSwitchOrStay {
		toSwitch = 1,
		toStay = 2
	};

public:
	LetsMakeADeal();

	~LetsMakeADeal();

	LetsMakeADeal(int switchOrStay, int numGames, int numDoors, int numDoorsRevealed);

	void setNumberDoors(int numDoors);

	void setSwitchOrStay(int switchStay);

	void setNumberGames(int numGames);

	void setNumberDoorsRevealed(int numReveal);

	void runGame();

	void outputProbability(std::vector<float>* v);

	void setRevealDoor(int doorChoice);

	int switchDoors(int doorChoice);

	void setPrizeDoor();

	int pickRandomNumber();

	void initRevealedDoors();


};

