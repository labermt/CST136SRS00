#ifndef LETSMAKEADEAL_H
#define LETSMAKEADEAL_H

class LetsMakeADeal
{
private:

	int doors_{ 3 };
	int revealed_{ 1 };
	int strat_;

public:

	enum strategy { keep = 0, trade = 1 };

public:
	
	LetsMakeADeal(const int doors, const int revealed, const int strat);
	~LetsMakeADeal();

	void strat(int strat) const;
	void probability();
};

#endif

//create doors 
//random pick door that hides car (1)
//set all other doors to goat (0)
//random pick initial door
//apply strat
//calculate probability and add to probability total
//
