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
    int doorToReveal;
    string userStrat;
    int carLocation;
    int swapLocation;

public:
  LetsMakeADeal();
  void usage();
  int getDoors() const;
  int getReveal()const;
  string getStrat() const;
  int getCarLocation() const;
  int getSwapLocation() const;
  void setDoors(int doors);
  void setReveal(int doors);
  void setStrat(string strat);
  void setCarLocation(int door);
  void setSwapLocation(int doors);
  bool playGame();
  int setRandom();
  int switchStrat();
};
