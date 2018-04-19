#include "header.h"

LetsMakeADeal::LetsMakeADeal()
{
    totalDoors = 0;
    UserDoor = 0;
    userStrat = "";
    carLocation = 0;
    swapLocation = 0;
}

void LetsMakeADeal::usage()
{
   cout << "Please supply values for all arguments." << endl;
   cout << "Usage: ./output -d <doors> -u <user door> -g <games> -s <stay/swap>" << endl;
   cout << "-d : the number of total doors in the game" << endl;
   cout << "-d : the user selected door" << endl;
   cout << "-g : the number of games to simulate" << endl;
   cout << "-s : the strategy to simulate <stay/swap>" << endl;
   exit(1);
}

int LetsMakeADeal::getTotalDoors() const
{
  return totalDoors;
}

int LetsMakeADeal::getUserDoor() const
{
  return UserDoor;
}

string LetsMakeADeal::getStrat() const
{
  return userStrat;
}

void LetsMakeADeal::setTotalDoors(int doors)
{
  totalDoors = doors;
}

void LetsMakeADeal::setUserDoor(int doors)
{
  UserDoor = doors;
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
  if (getCarLocation() == getUserDoor())
  {
      swapLocation = setRandom();
      while (getSwapLocation() == getCarLocation())
      {
	swapLocation = setRandom();
      }
  }
}


int LetsMakeADeal::setRandom()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, getTotalDoors());

  return dis(gen);
}

bool LetsMakeADeal::playGame()
{

  bool win = false;
  setCarLocation(setRandom());
  setSwapLocation(getCarLocation());
  if (getStrat() == "swap")
    setUserDoor(getSwapLocation());
    
  if (getUserDoor() == getCarLocation())
  {
      win = true;
      return win;
  }

  else
  {
      return win;
  }
}
