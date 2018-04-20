#include "mhstats.h"
#include <iostream>



MHStats::MHStats() :

	_numberOfGames(0),
	_doorChanges(0),
	_won(0),
	_lost(0),
	_wonWhenNotChanged(0),
	_wonWhenChanged(0)
{
	;
}


void ::MHStats::addStatistic(const MHResult& result)
{
	_numberOfGames++;

	if (result.playerChangedDecision() == true)
	{
		_doorChanges++;
	}



	if (result.playerWonTheGame() == true)
	{
		_won++;
	}
	else
	{
		_lost++;
	}
	if (result.playerChangedDecision() == true && result.playerWonTheGame() == true) {
		_wonWhenNotChanged++;
	}

	if (result.playerChangedDecision() == false && result.playerWonTheGame() == true) {
		_wonWhenNotChanged++;
	}
}



void ::MHStats::printStats() const
{
	double wonPct = 100 * (double)_won / (double)_numberOfGames;
	double wonWhenChangedPct = 100 * (double)_wonWhenChanged / (double) _doorChanges;
	uint32_t doorNotChanges = (_numberOfGames - _doorChanges);
	double wonWhenNotChangedPct = 100 * (double)_wonWhenNotChanged / (double)doorNotChanges;

	std::cout << "Number of games (total): " << _numberOfGames << std::endl;
	std::cout << "Number of times the player changed doors: " << _doorChanges << std::endl;
	std::cout << "Games result (WON/TOTAL): " << _won << "/" << _numberOfGames << " (" << wonPct << "\%)" << std::endl;
	std::cout << "Winning rate when changing door: " << _wonWhenChanged << "/" << _doorChanges << " (" << wonWhenChangedPct << "\%)" << std::endl;
	std::cout << "Winning rate when NOT changing door: " << _wonWhenNotChanged << "/" << doorNotChanges << " (" << wonWhenNotChangedPct << "\%)" << std::endl;
	std::cout << std::endl;
}
