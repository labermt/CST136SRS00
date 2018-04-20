#ifndef MHMODEL_H
#define MHMODEL_H

#include "stdint.h"
#include <vector>

#include "mhdoor.h"
#include "mhplayer.h"
#include "mhresult.h"

/**
 * This class describes the Monty Hall Problem
 */
class MHMODEL
{
	/**
	 * Number of doors (redundant with the size of the _doors vector
	 */
	uint8_t number_of_doors{};

	/**
	 * Vector of doors to model the problem
	 */
	std::vector<MHDOOR> _doors{};

	/**
	 * Marylyn
	 */
	MHPLAYER _player;

	/**
	 * Index of the door hiding the car
	 */
	int _carDoorIndex{};

	/**
	 * Verbose mode
	 */
	bool _verbose{};
	


public:
	/**
	 * Default constructor
	 */
	MHMODEL(uint8_t numberOfDoors = 3, bool verbose = false);

	MHResult theGame();
	/**
	 * Destructor
	 */
	~MHMODEL();

private:
	/**
	 * The model opens one door hiding a goat
	 */
	int openAnotherDoor(int playerChoice, int hostChoice);

	/**
	 * Returns a vector containing the indexes of available doors, excluding those passed as params
	 */
	std::vector<int> getAvailableDoors(int exclude1, int excluse2);

	/**
	 * Logs the game status
	 */
	void gameLog(const std::string actor, const std::string action, int doorNumber) const;

};

#endif //MHMODEL_H