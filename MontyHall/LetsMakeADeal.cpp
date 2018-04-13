#include "stdafx.h"
#include "LetsMakeADeal.h"


LetsMakeADeal::LetsMakeADeal() 
{
}


LetsMakeADeal::~LetsMakeADeal()
{
}


LetsMakeADeal::LetsMakeADeal(int switchOrStay, int numGames, int numDoors, int numDoorsRevealed) {

	//assign command line arguments to private members
	setSwitchOrStay(switchOrStay);
	setNumberGames(numGames);
	setNumberDoors(numDoors);
	setNumberDoorsRevealed(numDoorsRevealed);

	//resize revealedDoors vector to number of revealed doors and set all to false
	initRevealedDoors();

	runGame();
}


void LetsMakeADeal::setNumberDoors(int numDoors) {
	numberOfDoors = numDoors;
}


void LetsMakeADeal::setSwitchOrStay(int switchStay) {
	decideSwitchOrStay = switchStay;
}


void LetsMakeADeal::setNumberGames(int numGames) {
	numberOfGames = numGames;
}


void LetsMakeADeal::setNumberDoorsRevealed(int numReveal) {
	numberDoorsRevealed = numReveal;
}


void LetsMakeADeal::runGame() {
	//create container to store game instances
	std::vector<float> gameInstances;

	setPrizeDoor();

	//variables to store chosen door and the door revealed
	int chooseDoor;
	
	for (int i = 0; i < numberOfGames; i++) {

		chooseDoor = pickRandomNumber();
		setRevealDoor(chooseDoor);

		//user's decision to switch or stay
		if (decideSwitchOrStay == toSwitch) {
			chooseDoor = switchDoors(chooseDoor);
		}

		//add wins to vector
		if (chooseDoor == prizeDoor) {
			gameInstances.push_back(1);
		}
		//add losses to vector
		else {
			gameInstances.push_back(0);
		}

	}

	outputProbability(&gameInstances);

}


void LetsMakeADeal::outputProbability(std::vector<float>* gameInstances) {
	
	float totalWins = std::accumulate(gameInstances->begin(), gameInstances->end(), 0);
	float probability = totalWins / gameInstances->size();
	
	//add probability of total wins and total losses, should equal to 1 +- .01
	std::cout << "Probability of obtaining a car is: " << probability << std::endl;
}


void LetsMakeADeal::setRevealDoor(int doorChoice) {
	int revealDoor = pickRandomNumber();

	//make sure that the door revealed is not the door chosen or the prize door
	for (int i = 0; i < numberDoorsRevealed; i++) {

		while ((revealDoor == doorChoice) || (revealDoor == prizeDoor)) {
		revealDoor = pickRandomNumber();
		}

		revealedDoors.at(revealDoor) = true;
		revealDoor = pickRandomNumber();
	}

}


int LetsMakeADeal::switchDoors(int doorChoice) {
	int newDoor = pickRandomNumber();

	//make sure that the door revealed is not the door chosen or the door revealed
	while ((revealedDoors.at(newDoor) == true) || newDoor == doorChoice) {
		newDoor = pickRandomNumber();
	}

	return newDoor;
}


void LetsMakeADeal::setPrizeDoor() {
	prizeDoor = pickRandomNumber();
}


//generates random number from 1 to maxNumber
int LetsMakeADeal::pickRandomNumber() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, numberOfDoors);
	return dis(gen);
}

void LetsMakeADeal::initRevealedDoors() {
	revealedDoors.resize(numberOfDoors+1, false);
}
