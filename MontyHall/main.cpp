// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"
#include <iostream>
#include <sstream>

static void showUsage(std::string name)
{
	std::cerr << std::endl << "Usage: " << name << " -d -o -i -s\n"
		<< "\t Parameters:\n"
		<< "\t -d, \t \t \t Number of doors (default = 3)\n"
		<< "\t -o, \t \t \t Number of doors to open (default = 1)\n"
		<< "\t -i, \t \t Number of game instances to run (default = 1)\n"
		<< "\t -s, \t \t Selected strategy (options: stay, switch; default = stay)"
		<< std::endl;
}

int main( int argc, char* argv[] )
{
	if (argc < 1) 
	{
		showUsage(argv[0]);
		return 1;
	}

	// TODO: Make check for actual numbers.
	std::istringstream iss(argv[1]);
	size_t doors;
	size_t instances;
	LetsMakeADeal::choice strategy;

	if (!(iss >> doors))
	{
		std::cerr << "Invalid number of doors \n";
	}
	else
	{
		std::cout << doors;
	}

	std::istringstream isr(argv[2]);


	/*
	if ((iss >> doors) && iss.eof()) // Check eofbit
	{
		// Conversion successful
	}
	*/

	size_t open;

	//TODO: command line arguments (P 606 of the book)
	//TODO: add objects of LetsMakeADeal type into a vector (storage container)
	//TODO: tally results of runGame() to find probability of success with given paramaters
	if ( argc > 1 )
	{
		enum class paramaters {numDoors = 1, discloseDoor, instances, strategy};

		for ( auto i{ 0 }; i < 10000; i++)
		{
			auto testDeal{ LetsMakeADeal(3, 1, LetsMakeADeal::choice::stay) };

			auto testResult = testDeal.runGame();
		}
	}
	else
	{
		
	}
	
    return 0;
}

