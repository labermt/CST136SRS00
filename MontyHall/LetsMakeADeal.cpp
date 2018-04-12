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

void LetsMakeADeal::setNumOfGameInstances(int numGameInstances) {
    numOfGameInstances = numGameInstances;
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
void LetsMakeADeal::createDoors(int carLocation) {
    doorArray = new int[numOfDoors];
    cout << "Number of doors: " << numOfDoors << endl;
    for(int i = 0; i < numOfDoors; i++) {
        if(i == carLocation) {
            //the car is represented with a 1
            doorArray[i] = 1;
        }
        else {
            //goats are represented with 0s
            doorArray[i] = 0;
        }
    }

    cout << "door array: " << endl;
    for(int j = 0; j < numOfDoors; j++) {
        cout << doorArray[j];
    }

    cout << "The numbers are:: " << endl;
    cout << numOfDoors << endl;
    cout << numOfDoorsToReveal << endl;
    cout << numOfGameInstances << endl;
}

void LetsMakeADeal::printArray() {
    cout << "Printing array: " << endl;
    for(int i = 0; i < numOfDoors; i++) {
        cout << doorArray[i] << "  ";
    }
}

void LetsMakeADeal::revealDoors() {

}