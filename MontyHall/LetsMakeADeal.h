//
// Created by Thea Van Kessel on 4/7/18.
//

#ifndef MONTYHALL_LETSMAKEADEAL_H
#define MONTYHALL_LETSMAKEADEAL_H

#include <iostream>
#include <random>
#include <algorithm>

class LetsMakeADeal {
public:
    void setNumOfDoors(int numDoors);
    void setNumOfDoorsToReveal(int numDoorsToReveal);
    void setNumOfGameInstances(int numGameInstances);
    void setCarLocation(int locationOfCar);

    int randomNumber(int max);
    void createDoors(int carLocation);
    void printArray();
    void revealDoors();



private:
    int numOfDoors;
    int numOfDoorsToReveal;
    int numOfGameInstances;
    int carLocation;
    int * doorArray;
};


#endif //MONTYHALL_LETSMAKEADEAL_H
