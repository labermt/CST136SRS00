#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <getopt.h>
#include <string>
#include <random>
#include <cassert>

using namespace std;

class LetsMakeADeal
{

private:
    int totalDoors;
    int UserDoor;
    string userStrat;
    int carLocation;
    int swapLocation;

public:
  LetsMakeADeal();
  void usage();
  int getTotalDoors() const;
  int getUserDoor()const;
  string getStrat() const;
  int getCarLocation() const;
  int getSwapLocation() const;
  void setTotalDoors(int doors);
  void setUserDoor(int doors);
  void setStrat(string strat);
  void setCarLocation(int door);
  void setSwapLocation(int doors);
  bool playGame();
  int setRandom();
  
};

#endif
