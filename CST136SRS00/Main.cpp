//Main.cpp : Defines the entry point for the console application.
//Bobby Mahaffey

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LetsMakeADeal.h"
#include <vector>



int main(int argc, char* argv[])
{
	int numDoors = 3;
	int predisclosed = 1;
	int gameInstances = 0;
	bool switchOrStay = true;
	
	

	std::vector<LetsMakeADeal> instances;//creating a container vector called instances that stores objects of from LetsmakeADeal

	if (argc != 5)
	{
		std::cout << " number of arguments is incorrect " << std::endl;
		std::cout << " Should take in four arguments #Doors #predisclosed doors #game instances and The word switch or stay" << std::endl;
		exit(1);
	}

	numDoors = std::stoi(argv[1]);//stores the command line argv 1 into numDoors
	predisclosed = std::stoi(argv[2]);//stores the command line argv 2 into predisclosed
	gameInstances = std::stoi(argv[3]);//stores the command line argv 3 into gameInstances
	switchOrStay = (strcmp(argv[4], "switch") == 0) ? true : false;//compares the argv 4 which we set to switch in the 

	for(int i=0;i<gameInstances;i++)
	{
		LetsMakeADeal game(numDoors, predisclosed, gameInstances, switchOrStay);
		instances.push_back(game);//stores choices in the vector after each gameInstance
	}
	float prob = 0;
	float sum = 0;

	for (int i = 0;i<gameInstances;i++)
	{
		 sum += instances[i].RunGame();//stores the added instances into a sum var
	}
	prob = sum / gameInstances;//assert statement
	std::cout << "The problility is: " << prob << std::endl;
	
	
	std::cin.get();//waiting for a charater to be pressed

    return 0;
}

