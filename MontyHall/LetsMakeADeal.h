#ifndef LETSMAKEADEAL_H
#define LETSMAKEADEAL_H

enum class Strategy { kKeep = 0, kTrade = 1, kError };

class LetsMakeADeal
{
private:

	const int doors_{ 3 };
	const int disclose_{ 1 };
	const Strategy strat_;

public:
	
	LetsMakeADeal(const int& doors, const int& disclose, const Strategy& strat);

	bool simulateDeal() const;

private:

	int randomDoor(const int doors) const;

};

#endif

