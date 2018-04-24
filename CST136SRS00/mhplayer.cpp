#include "mhplayer.h"

#include "proxyrandom.h"
#include <stdexcept>

/**
 * \brief firstchoice
 * \returns nothing
 */
MHPLAYER::MHPLAYER() : _firstChoice(-1),
_secondChoice(ERROR)
{
	; //do nothing
}

int MHPLAYER::doFirstChoice(int min, int max)
{
	int choice = ProxyRandom::get()->getUniformlyDistributedRandomBetween(min, max);
	_firstChoice = choice;
	return _firstChoice;
}



int MHPLAYER::getFirstChoice() const
{
	if (_firstChoice == -1)
	{
		throw std::range_error("FirstChoice value was not initialized");
	}

	return _firstChoice;
	
}


MHPLAYER::SecondChoice MHPLAYER::doSecondChoice()
{
	int choice = ProxyRandom::get()->getUniformlyDistributedRandomBetween(KEEP_DOOR, CHANGE_DOOR);
		_secondChoice = intToSecondChoice(choice);
	return _secondChoice;
}

MHPLAYER::SecondChoice MHPLAYER::getSecondChoice() const
{
	if (_secondChoice == ERROR)
	{
		throw std::out_of_range("SecondChoice value was not initialized");
	}

	return _secondChoice;
}


MHPLAYER::SecondChoice MHPLAYER::intToSecondChoice(int value)
{
	switch (value)
	{
	case KEEP_DOOR:
		return KEEP_DOOR;
		break;
	case CHANGE_DOOR:
		return CHANGE_DOOR;
		break;
	default:
		throw std::out_of_range("Error while converting integer to SecondChoice Type");
		break;
	}
}


