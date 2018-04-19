#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <iostream>

using namespace std; 

/**
 * \brief 
 */
LetsMakeADeal::LetsMakeADeal()
= default;

LetsMakeADeal::~LetsMakeADeal()
{
}

bool LetsMakeADeal::predictWin(int winningDoor, int winningDoor2)
{
	//using random # generator, define a "winning door" versus a "non-winning door" number
	// example: if true then "win" is if door is less than/equal to total doors minus 1
	//          if false then "win" is door 1.
	if(switchStrategy)
	{
		return (winningDoor<=totalDoors-1);
	}
	else
	{
		return(winningDoor==1);
	}
}


