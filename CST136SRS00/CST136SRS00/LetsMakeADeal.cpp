#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>
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

	//int remainingDoors = totalDoors - openDoors;

	
	//int winningDoor = distribution(generator);
	//cout << "Winning door is: " << winningDoor << endl; 

	if(switchStrategy)
	{
		
		
		//cout << "Winning door: " << winningDoor << endl; 
		return (winningDoor<=totalDoors-1);
	}
	else
	{

		
		//cout << "Winning door: " << winningDoor << endl;
		return(winningDoor==1);
	}
}


