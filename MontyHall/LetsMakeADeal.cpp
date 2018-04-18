#include "header.h"

LetsMakeADeal::LetsMakeADeal()
{
    totalDoors = 0;
    doorToReveal = 0;
    userStrat = "";
    carLocation = 0;
    swapLocation = 0;
}

void LetsMakeADeal::usage()
{
   cout << "Please supply values for all arguments." << endl;
   cout << "Usage: ./output -d <doors> -r <door to reveal> -g <games> -s <stay/swap>" << endl;
   exit(1);
 }

int LetsMakeADeal::getDoors() const
{
  return totalDoors;
}

int LetsMakeADeal::getReveal() const
{
  return doorToReveal;
}

string LetsMakeADeal::getStrat() const
{
  return userStrat;
}

void LetsMakeADeal::setDoors(int doors)
{
  totalDoors = doors;
}

void LetsMakeADeal::setReveal(int doors)
{
  doorToReveal = doors;
}

void LetsMakeADeal::setStrat(string strat)
{
  userStrat = strat;
}

int LetsMakeADeal::getCarLocation() const
{
  return carLocation;
}

int LetsMakeADeal::getSwapLocation() const
{
  return swapLocation;
}

void LetsMakeADeal::setCarLocation(int door)
{
  carLocation = door;
}

void LetsMakeADeal::setSwapLocation(int door)
{
  
  swapLocation = door;
  if (getCarLocation() == getReveal())
  {
      swapLocation = setRandom();
      while (getSwapLocation() == getCarLocation())
      {
	swapLocation = setRandom();
      }
  }

  else
  {
    swapLocation = getCarLocation();
  }
}


int LetsMakeADeal::setRandom()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, getDoors());

  return dis(gen);
}

bool LetsMakeADeal::playGame()
{

  bool win = false;
  setCarLocation(setRandom());
  setSwapLocation(setRandom());
  if (getStrat() == "swap")
    setReveal(getSwapLocation());
    
  if (getReveal() == getCarLocation())
  {
      win = true;
      return win;
  }

  else
  {
      return win;
  }
}
