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

void LetsMakeADeal::setCarLocation(int locationOfCar) {
    carLocation = locationOfCar;
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
    //Create an array with numbers from 0 to numOfDoors
    int randomArray[numOfDoors];
    //arrDoorsToReveal holds the locations of the doors that will be reveals from the doorArray
    int arrDoorsToReveal[numOfDoorsToReveal];
    for(int i = 0; i < numOfDoors; i++) {
        randomArray[i] = i;
    }

    //Shuffle the array
    //tried implementing with random_shuffle but this is removed in c++17
    //https://www.quora.com/How-can-I-shuffle-the-numbers-in-c++
    //http://www.cplusplus.com/reference/algorithm/shuffle/
    random_device seed;
    mt19937 rng(seed());

    shuffle(&(randomArray[0]), &(randomArray[numOfDoors]), rng);

    cout << endl << endl << "Random Array: " << endl;
    for(int j = 0; j < numOfDoors; j++) {
        cout << " " << randomArray[j];
    }

    //Take only the numbers from element 0 to numOfDoorsToReveal --- Make sure carLocation is not included
    int l = 0;
    //l < numOfDoorsReveal because if k < numOfDoorsToReveal it can potentially reach 6 and exit the loop earlier than anticipated
    for(int k = 0; l < numOfDoorsToReveal; k++) {
        if(randomArray[k] == carLocation) {
            k++;
        }
        arrDoorsToReveal[l] = randomArray[k];
        l++;
    }

    cout << endl << endl << "DOORS TO REVEAL ARRAY" << endl;
    for(int m = 0; m < numOfDoorsToReveal; m++) {
        cout << arrDoorsToReveal[m] << " ";
    }
}