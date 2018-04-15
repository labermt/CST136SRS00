// MontyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include "LetsMakeADeal.h"
using namespace std;



int main( int argc, char *argv[] )
{
	float cash_money;
	float totes_mygoats;

	

	LetsMakeADeal game;
	game.set_values(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	game.play_game(game.get_instances(), game.get_stay(), game.get_doors(), game.get_disclose());

	cash_money = game.car_prob(game.get_outcome(), game.get_instances());
	totes_mygoats = game.goat_prob(game.get_outcome(), game.get_instances());

	assert(cash_money + totes_mygoats == 1);
	cout << "The probability of winning a car is: " << cash_money << endl;

	
    return 0;
}

