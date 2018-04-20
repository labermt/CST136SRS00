#include "stdafx.h"
#include "LetsMakeADeal.h"


LetsMakeADeal::LetsMakeADeal(const int numDoors, const int predisclosed, const int gameInstances,const bool switchOrStay)
	:gen(random_device_())
{

	numDoors_ = numDoors;//numDoors set to private numDoors_
	predisclosed_ = predisclosed;
	gameInstances_ = gameInstances;
	switchOrStay_ = switchOrStay;

	doors_.resize(numDoors_);
	std::uniform_int_distribution<> distribution(0, numDoors_ - 1);
	car_ = distribution(gen);
	doors_[car_] = Door::CAR;
}


LetsMakeADeal::~LetsMakeADeal()
{
	//std::cout << " I'm am in the destructor" << std::endl;
}

float LetsMakeADeal::RunGame()
{

	std::uniform_int_distribution<> distribution(0, numDoors_ - 1);
	int pick = distribution(gen);

	for (int i = 0;i < predisclosed_;++i)//for loop that looks though the predislosed doors
	{
		int random_door;
		do
		{
			random_door = distribution(gen);//random generator
		} while (random_door != pick && random_door != car_);//A check to see if its a pick door 
															 // or the car door
		doors_[random_door] = Door::GOAT;//if the predisclosed if not a car or pick than its a goat
	}
	int switch_door; 

	do
	{
		switch_door  = distribution(gen);
	} while (switch_door != pick && doors_[switch_door] != Door::GOAT);
	
	int selected_door;
	if (switchOrStay_ == true)
	{
		selected_door = switch_door;
	}
	else
	{
		selected_door = pick;
	}

	if(selected_door == car_)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

LetsMakeADeal::LetsMakeADeal(const LetsMakeADeal& copy)
	:gen(random_device_())
{
	numDoors_= copy.numDoors_;
	predisclosed_ = copy.predisclosed_;
	gameInstances_ = copy.gameInstances_;
	switchOrStay_ = copy.switchOrStay_;
	doors_ = copy.doors_;
	car_ = copy.car_;
}


