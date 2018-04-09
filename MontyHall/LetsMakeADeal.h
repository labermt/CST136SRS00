#pragma once
#include <vector>

class LetsMakeADeal
{

private:
	enum strategy {stay, change};
	enum prize{goat, car};
	
	unsigned doors_{};
	unsigned open_doors_{};
	strategy strat_{};

	unsigned get_random_door_index(unsigned const max_door) const;
	void set_prize(std::vector<unsigned> game_instance, unsigned location);

public:
	LetsMakeADeal(unsigned doors, unsigned open_doors, std::string strat);
	bool run_game();
};