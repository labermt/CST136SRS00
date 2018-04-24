#ifndef MHSTATS_H
#define MHSTATS_H

#include <stdint.h>

#include "mhresult.h"

//class to collect statictics of N runs of the Monty Hall game.
class MHStats
{
	//Total number of games
	/**
	 * \Total number of games
	 */
	uint32_t _numberOfGames;


	/**
	 * \Number of games in which the player decided to change the door
	 */
	uint32_t _doorChanges;


	//number of won games
	uint32_t _won;



	//Number of lost games
	uint32_t _lost;


	/**
	* \Number of games won when the player changed the door
	*/
	uint32_t _wonWhenChanged;;

	//number of times that the player won when the player didn't change the door

	uint32_t _wonWhenNotChanged;

public:
	//default constructor
	MHStats();

	void addStatistic(const MHResult& result);

	//prints statistics

	void printStats() const;
};

#endif
