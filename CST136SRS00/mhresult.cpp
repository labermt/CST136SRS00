#include "stdafx.h"
#include "mhresult.h"

MHResult::MHResult() :
	_playerChangedDecision(false),
	_playerWonTheGame(false)
{
	;
}

MHResult::MHResult(bool playerChangedDecision, bool playerWonTheGame) :
	_playerChangedDecision(playerChangedDecision),
	_playerWonTheGame(playerWonTheGame)
{
	;
}

void MHResult::setPlayerChangedDecision(bool value)
{
	_playerChangedDecision = value;
}

void MHResult::setPlayerWonTheGame(bool value)
{
	_playerWonTheGame = value;
}

bool MHResult::playerChangedDecision() const
{
	return _playerChangedDecision;
}

bool MHResult::playerWonTheGame() const
{
	return _playerWonTheGame;
}
