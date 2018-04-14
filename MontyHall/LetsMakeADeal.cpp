//
// Created by Thea Van Kessel on 4/7/18.
//

#include "LetsMakeADeal.h"

using namespace std;

void LetsMakeADeal::setNumOfDoors(int numDoors) {
    numOfDoors = numDoors;
}

void LetsMakeADeal::setNumOfDoorsToReveal(int numDoorsToReveal) {
    numOfDoorsToReveal = numDoorsToReveal;
}

void LetsMakeADeal::setCarLocation(int locationOfCar) {
    carLocation = locationOfCar;
}

void LetsMakeADeal::setGuess() {
    guess = randomNumber(numOfDoors);
}

// http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
// RandomNumber generates a random number between 0 and max
int LetsMakeADeal::randomNumber(int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, max);
    return dis(gen);
}

// createDoors creates an array of doors and behind each door is a goat or a car
// car represented with a 1 and goat represented with a 0
void LetsMakeADeal::createDoors() {
    for(int i = 0; i < numOfDoors; i++) {
        if(i == carLocation) {
            //the car is represented with a 1
            doorVector.push_back(1);
        }
        else {
            //goats are represented with 0s
            doorVector.push_back(0);
        }
    }
}

void LetsMakeADeal::printArray() {
    cout << "Printing VECTOR: " << endl;
    for(int i = 0; i < numOfDoors; i++) {
        cout << doorVector[i] << "  ";
    }
}

void LetsMakeADeal::revealDoors() {
  vector<int> randomNumbersVector;
    //Create a vector with numbers from 0 to numOfDoors
    for(int i = 0; i < numOfDoors; i++) {
        randomNumbersVector.push_back(i);
    }

    //shuffle vector
    //https://www.quora.com/How-can-I-shuffle-the-numbers-in-c++
    //http://www.cplusplus.com/reference/algorithm/shuffle/
    random_device seed;
    mt19937 rng(seed());
    shuffle(randomNumbersVector.begin(), randomNumbersVector.end(), rng);

    //take only the first 0 to numOfDoorsToReveal
    for(int k = 0; k < numOfDoorsToReveal; k++) {
        if(randomNumbersVector[k] == carLocation || randomNumbersVector[k] == guess) {
            //Do not reveal the car location or the selected guess door
            remainingDoors.push_back(randomNumbersVector[k]);
            randomNumbersVector.erase(randomNumbersVector.begin() + k);
            k--;
        } else {
            doorsToReveal.push_back(randomNumbersVector[k]);
        }
    }

    for(int m = numOfDoorsToReveal; m < numOfDoors - 1; m++) {
        remainingDoors.push_back(randomNumbersVector[m]);
    }

}

void LetsMakeADeal::switchDoor() {
    //Pick a random number within the unrevealed doors vector
    int randNumIndex = randomNumber(numOfDoors - numOfDoorsToReveal - 1);
    int newGuess = remainingDoors[randNumIndex];
    while(newGuess == guess) {
        randNumIndex = randomNumber(numOfDoors - numOfDoorsToReveal - 1);
        newGuess = remainingDoors[randNumIndex];
    }
    guess = newGuess;

}

//Return 0 if you lost, 1 if you won
int LetsMakeADeal::winningStatus() {
    if(guess == carLocation) {
        return 1;
    } else {
        return 0;
    }
}