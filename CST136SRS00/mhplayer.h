#ifndef MHPLAYER_H
#define MHPLAYER_H

/**
 * \brief 
 */
class MHPLAYER
{

public:
	/**
	* \brief Describes the second choice of the player, keep the chose door or choose the other one( if 3 doors)
	*/
	enum SecondChoice
	{
		ERROR = -1,
		KEEP_DOOR = 0,
		CHANGE_DOOR,

	};

private:
	/**
	 * \brief Keeps track of the first choice
	 */
	int _firstChoice;

	/*
	 * \brief Keeps track of the second choice
	 */
	SecondChoice _secondChoice;
public:
	/**
	 * \Default Constructor
	 */
	MHPLAYER();



	/**
	 * \brief Players first Choice within the provided ranges
	 * (door numbers)
	 */
	int doFirstChoice(int min, int max);

	int getFirstChoice() const;

	SecondChoice doSecondChoice();

	/**
	 * \brief doSecondChoice()
	 * \return _secondChoice
	 */
	SecondChoice getSecondChoice() const;
	
	

private:

	/**
	 * \brief Utility function to convert from integer to
	 * SecondChoice
	 */
	SecondChoice intToSecondChoice(int value);
};


#endif //MHPLAYER_H

