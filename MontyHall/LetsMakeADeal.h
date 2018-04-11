#pragma once
#include <vector>
#include <random>

class LetsMakeADeal
{

private:
	enum class strategy { stay, change };
	enum class door_states { goat, car, opened };

public:
	enum class result { lost, won  };

private:
	unsigned doors_{3};
	unsigned open_doors_{1};
	result result_{};
	strategy strat_{};

	void open_random_door(std::vector<door_states> &game_instance);
	void set_car(std::vector<door_states> &game_instance);
	unsigned get_rand_door() const;
	unsigned guess_door(std::vector<door_states> &game_instance) const;

public:
	LetsMakeADeal(unsigned const doors, unsigned const open_doors, std::string const strat);
	bool run_game();
	result get_result() const;
};
