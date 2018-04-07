#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>


LetsMakeADeal::LetsMakeADeal(unsigned numDoors_, unsigned numDisclosedDoors_, bool stay_)
	:numDoors{ numDoors_ }, numDisclosedDoors{ numDisclosedDoors_ }, stay{ stay_ }
{
}

bool LetsMakeADeal::getResult()
{
	//init doors vector
	std::vector<bool> doors(numDoors, false);

	//setup random generator
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(0, doors.size() - 1);
	
	//place the car in a random door
	doors[distr(generator)] = true;

	//randomly choose a door
	int chosenDoor = doors[distr(generator)];

	//predisclose doors
	int tempDoor;
	for (int i = 0; i < numDisclosedDoors;)
	{
		tempDoor = distr(generator);
		if (tempDoor != chosenDoor && doors[tempDoor] != true) {
			doors.erase(doors.begin() + tempDoor);
			i++;
		}
	}

	//switch or stay
	if (!stay)
	{
		//switch
		int oldDoor = chosenDoor;
		while (chosenDoor == oldDoor) 
			chosenDoor = distr(generator);
	}

	//open your door
	return doors[chosenDoor];
}


LetsMakeADeal::~LetsMakeADeal()
{
}
