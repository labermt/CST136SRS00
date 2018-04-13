#include "stdafx.h"
#include <cassert>
#include "LetsMakeADeal.h"
#include <random>

LetsMakeADeal::LetsMakeADeal()
	:numDoors{ 3 }, numDisclosedDoors{ 1 }, stay{ true }
{

}
LetsMakeADeal::LetsMakeADeal(unsigned numDoors_, unsigned numDisclosedDoors_, bool stay_)
	:numDoors{ numDoors_ }, numDisclosedDoors{ numDisclosedDoors_ }, stay{ stay_ }
{
	playGame();
}

bool LetsMakeADeal::getResult()
{
	return result;
}

void LetsMakeADeal::playGame()
{
	//init doors vector
	std::vector<int> doors(numDoors, false);

	//setup random generator
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(0, doors.size() - 1);
	
	//place the car in a random door
	doors[distr(generator)] = true;

	//randomly choose a door
	int chosenDoor = doors[distr(generator)];

	//assert probabilities are correct
	double numCars = 0, numGoats = 0;
	for (int i = 0; i < doors.size(); i++)
	{
		if (doors[i] == 1) numCars++;
		else numGoats++;
	}
	double carsProbability = numCars / numDoors;
	double goatProbability = numGoats / numDoors;
	assert(carsProbability + goatProbability == 1.0);

	//predisclose doors
	int tempDoor;
	for (int i = 0; i < numDisclosedDoors;)
	{
		distr = std::uniform_int_distribution<int>(0, doors.size() - 1);
		tempDoor = distr(generator);
		if (tempDoor != chosenDoor && doors[tempDoor] != true) {
			doors.erase(doors.begin() + tempDoor);
			i++;
			if (tempDoor < chosenDoor) chosenDoor--; //move chosen door down one if necessary
		}
	}

	//switch or stay
	if (!stay)
	{
		//switch
		int oldDoor = chosenDoor;
		distr = std::uniform_int_distribution<int>(0, doors.size() - 1);
		while (chosenDoor == oldDoor) 
			chosenDoor = distr(generator); 
	}

	//open your door
	result = doors[chosenDoor];
}


LetsMakeADeal::~LetsMakeADeal()
{
}
