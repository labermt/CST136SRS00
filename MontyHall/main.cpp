// MontyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LetsMakeADeal.h"
using namespace std;


int main( int argc, char *argv[] )
{


	LetsMakeADeal game;
	game.set_values(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	game.play_game(game.get_instances(), game.get_stay(), game.get_doors(), game.get_disclose());
	game.car_prob(game.get_outcome(), game.get_instances());

    return 0;
}

