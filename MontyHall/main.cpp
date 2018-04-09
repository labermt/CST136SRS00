// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>

int main( int argc, char* argv[] )
{
	//TODO: add objects of LetsMakeADeal type into a vector (storage container)
	//TODO: tally results of runGame() to find probability of success with given paramaters
	if ( argc > 1 )
	{
		//TODO: command line arguments (P 606 of the book)
		enum class paramaters {numDoors, discloseDoor, instances, strategy};
		const auto firstParam = atoi(argv[1]);
		const auto secondParam = argv[2];
		const auto thirdParam = argv[3];
		const auto fourthParam = argv[4];
		if ( 0 < firstParam < 2 )
		{
			for (auto i{ 1 }; i < argc; i++)
			{
				std::cout << argv[i] << std::endl;
			}
			atoi(argv[1]);
		}

		/*
		for ( auto i{ 0 }; i < argv[paramaters::instances]; i++)
		{
			auto testDeal{ LetsMakeADeal(3, 1, LetsMakeADeal::choice::stay) };

			auto testResult = testDeal.runGame();
		}
		*/
	}
	else
	{
		
	}
	
    return 0;
}
