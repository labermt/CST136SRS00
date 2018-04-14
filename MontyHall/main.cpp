#include <iostream>
#include <sstream>
#include "LetsMakeADeal.h"

using namespace std;

//Convert character to an integer number
int toInt(char * character);

int main(int argc, char *argv[]) {
    LetsMakeADeal newGame;

    int numOfDoors = toInt(argv[1]);
    int numOfDoorsToReveal = toInt(argv[2]);
    int numOfGameInstances = toInt(argv[3]);

    newGame.setNumOfDoors(numOfDoors);
    newGame.setNumOfDoorsToReveal(numOfDoorsToReveal);
    newGame.setNumOfGameInstances(numOfGameInstances);

    int carLocation = newGame.randomNumber(numOfDoors - 1);
    newGame.setCarLocation(carLocation);

    cout << "Location of car: " << carLocation << endl;

    cout << "Number of doors: " << numOfDoors << endl;
    cout << "Number of doors to reveal: " << numOfDoorsToReveal << endl;
    cout << "Number of Game instances: " << numOfGameInstances << endl;

    newGame.createDoors(carLocation);
    newGame.printArray();
    newGame.revealDoors();
    return 0;
}

//Converts a character to an integer number
int toInt(char * character) {
    stringstream str;
    str << character;
    int number;
    str >> number;
    return number;
}