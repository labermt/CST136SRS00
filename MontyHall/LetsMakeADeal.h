#ifndef LETSMAKEADEAL_H
#define LETSMAKEADEAL_H

enum class Strategy { kKeep = 0, kTrade = 1, kError };

class LetsMakeADeal
{
private:

	const int doors_{ 3 };
	const int open_{ 1 };
	const Strategy strat_;

public:
	
	LetsMakeADeal(const int& doors, const int& open, const Strategy& strat);

	bool simulateDeal() const;

private:

	int randomDoor(const int doors) const;

};

#endif

//create doors 
//random pick door that hides car (1)
//set all other doors to goat (0)
//random pick initial door
//apply strat
//calculate probability and add to probability total
//
