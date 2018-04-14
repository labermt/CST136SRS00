#pragma once
#include <vector>


class LetsMakeADeal {

private:
	int number_of_doors_{};
	int decide_switch_or_stay_{};		// 1 for Switch; 2 for Stay
	int number_of_games_{};
	int number_doors_revealed_{};
	int prize_door_{};
	std::vector<bool> revealed_doors_{}; // store doors to revealed
	std::vector<float> game_instances_{}; // store game scores

	enum decide_switch_or_stay {
		to_switch = 1,
		to_stay = 2
	};

public:
	LetsMakeADeal();

	~LetsMakeADeal();

	LetsMakeADeal(const int switch_or_stay, const int num_games, const int num_doors, const int num_doors_revealed);

	void set_switch_or_stay(const int switch_stay);

	void run_game();

	void set_game_instances(int score);

	void output_probability();

	void set_reveal_door(int door_choice);

	int switch_doors(const int original_door_choice);

	void set_prize_door();

	int pick_random_number() const;

	void init_revealed_doors();


};

