#pragma once
#include <vector>
#include <string>

class LetsMakeADeal
{

private:
	enum class strategy { stay, change };
	enum class door_states { goat, car, opened };
	std::vector<door_states> game_{};

public:
	enum class result { lost, won };

private:
	int doors_{};
	int open_doors_{};
	int guess_{ -1 };
	result result_{};
	strategy strat_{};


	void open_random_door();
	int get_rand_door() const;
	void guess_door();

public:
	LetsMakeADeal(int const doors, int const open_doors, std::string const strat);
	static void display_help();
	void run_game();
	result get_result() const;
};
