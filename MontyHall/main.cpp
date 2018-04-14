#include <iostream>
#include <sstream>
#include <cassert>
#include "LetsMakeADeal.h"

using namespace std;

//Convert character to an integer number
int toInt(char * character);

int main(int argc, char *argv[]) {
    vector<LetsMakeADeal> games;

    int numOfDoors = toInt(argv[1]);
    int numOfDoorsToReveal = toInt(argv[2]);
    int numOfGameInstances = toInt(argv[3]);
    char * switchOrStay = argv[4];
    int wins = 0;
    int losses = 0;
    float probabilityCar = 0.0;
    float probabilityGoat = 0.0;

    cout << "Number of doors: " << numOfDoors << endl;
    cout << "Number of doors to reveal: " << numOfDoorsToReveal << endl;
    cout << "Number of Game instances: " << numOfGameInstances << endl;

    //Run the game numOfGameInstances times
    for(int i = numOfGameInstances; i > 0; i--) {
        LetsMakeADeal newGame;
        newGame.setNumOfDoors(numOfDoors);
        newGame.setNumOfDoorsToReveal(numOfDoorsToReveal);
        newGame.setNumOfGameInstances(numOfGameInstances);
        newGame.setGuess();

        int carLocation = newGame.randomNumber(numOfDoors - 1);
        newGame.setCarLocation(carLocation);

        cout << "Location of car: " << carLocation << endl;

        newGame.createDoors();
        newGame.printArray();
        newGame.revealDoors();

        //If the user wants to switch doors, switch
        if(strcmp(switchOrStay, "switch") == 0) {
            newGame.switchDoor();
        }

        newGame.winningStatus();

        if(newGame.winningStatus() == 1) {
            wins++;
        } else {
            losses++;
        }

        //create an instance of the game
        games.push_back(newGame);
    }

    //Find the probability of winning car
    probabilityCar = (float)wins / (float)numOfGameInstances;

    //Find probability of losing and obtaining a goat
    probabilityGoat = (float)losses / (float)numOfGameInstances;

    cout << endl << "probability of winning: " << probabilityCar;

    assert((probabilityCar + probabilityGoat) == 1);

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