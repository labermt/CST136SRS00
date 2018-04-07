#pragma once
class LetsMakeADeal
{
private: 
	size_t numOfDoors_{ 3 }; //start amount of doors
	size_t openDoors_{ 1 }; //how many doors to open or predisclose 
	size_t finalLength_; //how many doors you wind up with
	bool stay = true;  //switch or stay doors 
public:
	LetsMakeADeal(size_t numOfDoors_, size_t openDoors_, size_t finalLength_);
	
};

