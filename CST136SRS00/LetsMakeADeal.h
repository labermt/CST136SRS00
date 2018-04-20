#pragma once
#include <vector>
#include <random>

enum Door { GOAT, CAR, CLOSED };
class LetsMakeADeal
{

public:
	LetsMakeADeal(const int, const int, const int, const bool);
	~LetsMakeADeal();
	float RunGame();//function to run the game
	LetsMakeADeal(const LetsMakeADeal & copy);//because we are using a vector we need a copy
private:                                      //constructor to call from
	int numDoors_;
	int predisclosed_;
	int gameInstances_;
	bool switchOrStay_;
	std::vector<Door> doors_;//A vector called Door that stores the private int doors_
	std::random_device random_device_;
	std::mt19937 gen;
	int car_;
};

