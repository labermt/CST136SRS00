// MontyHall.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

class Lmad {

	//vars
	int doors = 3;
	int disclosed = 1;
	bool strategy = 0; //0 for switch 1 for stay
	double probability = 0;
	//1 for win 0 for loose

	//default constructor
	Lmad();

	//constructor
	Lmad(int d, int disc, bool strat) {

		doors = d;
		disclosed = disc; 
		strategy = strat;

	}

	public:

	bool simulate(){
		//1 for win 0 for loose
		bool outcome = 0;

		//create a vector of doors
			
		//pick a random door

		//put car behind it

		//randomly pick door as contestant

		//disclose number of doors by picking number of doors that isnt car and popping them out of vector

		//if car is behind picked door and strategy is stay set outcome to 1

		//if not and strategy is stay set outcome to 0 for lose

		//if car is behind door and strategy is change set outcome to 0 for lose

		//if not and strategy is change randomly pick another door and check if car is behind it

		return outcome;
	}

};


int main(int argc, char *argv[])
{
	int numOfDoors, numOfDisc, instances = 0;
	bool strategy = 0;

	//argument 0 is the is the path to the .exe
	
	//check for correct number of args
	//+1 for path argument
	if (argc != 5) {
		cout << "This program requires 4 arguments \n";    
		cout << "arg1 = Number of doors \n";
		cout << "arg2 = Number of doors to disclose \n";
		cout << "arg3 = Number of game instances \n";
		cout << "arg4 = Strategy -> 0 for Switch or 1 for Stay \n";
		cout << "Please exit and retry with the correct number of arguments!\n";
	} //do more input checking later

	



	int temp = 0;
	cin >> temp;

	/*numOfDoors = atoi(argv[1]);

	cout << numOfDoors;*/

	


    return 0;
}

