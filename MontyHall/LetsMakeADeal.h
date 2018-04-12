#pragma once
#include <vector>
#include <random>

class LetsMakeADeal
{

private:
	enum class strategy { stay, change };
	enum class door_states { goat, car, opened };
	std::vector<door_states> game_{};

public:
	enum class result { lost, won };

private:
	int doors_{ 3 };
	int open_doors_{ 1 };
	int guess_{-1};
	result result_{};
	strategy strat_{};
	

	void open_random_door();
	void set_car();
	unsigned get_rand_door() const;
	void guess_door() ;

public:
	LetsMakeADeal(int const doors, int const open_doors, std::string const strat);
	void run_game();
	result get_result() const;
};
