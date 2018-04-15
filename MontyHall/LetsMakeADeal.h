#pragma once
#include <vector>
#include <string>

class LetsMakeADeal
{

private:
	enum class strategy { stay, change };
	enum class door_state { goat, car, opened };

public:
	enum class result { lost, won };

private:
	int const total_doors_;
	int doors_to_open_;
	int guess_{ -1 };
	result result_{};
	strategy strat_;

	std::vector<door_state> door_collection_{};


	void open_random_door();
	static int get_rand_num( int const max);
	void guess_door();
	void set_car();

public:
	LetsMakeADeal(int const doors, int const open_doors, std::string const strat);
	static void display_help();
	void run_game();
	result get_result() const;
};
