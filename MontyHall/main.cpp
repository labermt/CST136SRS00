// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"

int main()
{
	//TODO: command line arguments (P 606 of the book)
	//TODO: add objects of LetsMakeADeal type into a vector (storage container)
	//TODO: tally results of runGame() to find probability of success with given paramaters
	
	for (auto i{ 0 }; i < 1000; i++)
	{
		auto testDeal{ LetsMakeADeal(3, 1, LetsMakeADeal::choice::stay) };

		auto testResult = testDeal.runGame();
	}

    return 0;
}
