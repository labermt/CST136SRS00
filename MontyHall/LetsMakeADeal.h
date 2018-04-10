#pragma once
#include <vector>
#include <random>

class LetsMakeADeal
{

private:
	enum strategy {stay, change};
	enum door_states{goat, car, opened};
	
	unsigned doors_{3};
	unsigned open_doors_{1};
	strategy strat_{};

	void open_random_door(std::vector<door_states>& game_instance);
	void set_car(std::vector<door_states> &game_instance);
	unsigned get_rand_num() const;

public:
	LetsMakeADeal(unsigned const doors, unsigned const open_doors, std::string const strat);
	bool run_game();
};
