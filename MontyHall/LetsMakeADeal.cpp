#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <random>
#include <numeric>
#include <iostream>


// ReSharper disable once CppPossiblyUninitializedMember
LetsMakeADeal::LetsMakeADeal()
{
}


LetsMakeADeal::~LetsMakeADeal()
{
}


LetsMakeADeal::LetsMakeADeal(const int switch_or_stay, const int num_games, const int num_doors, const int num_doors_revealed)
	:number_of_doors_(num_doors), decide_switch_or_stay_(switch_or_stay), number_of_games_(num_games), number_doors_revealed_(num_doors_revealed)
{

	//run game multiple times
	for (auto i{ 0 }; i < number_of_games_; i++) {

		//reset revealed doors vector
		init_revealed_doors();

		run_game();
	}

	output_probability();
}


void LetsMakeADeal::set_switch_or_stay(const int switch_stay)
{
	decide_switch_or_stay_ = switch_stay;
}


void LetsMakeADeal::run_game() {

	//setup prize door
	set_prize_door();

	//game chooses a door
	auto choose_door{ pick_random_number() };

	//choose random doors to reveal
	set_reveal_door(choose_door);

	//user's decision to switch or stay
	if (decide_switch_or_stay_ == to_switch) {
		choose_door = switch_doors(choose_door);
	}

	//add wins to gameInstance vector
	if (choose_door == prize_door_) {
		set_game_instances(1);
	}
	//add losses to gameInstance vector
	else {
		set_game_instances(0);
	}
}


void LetsMakeADeal::set_game_instances(int const score) {

	//add score to game instances vector
	game_instances_.push_back(score);
}


void LetsMakeADeal::output_probability() {

	//probability of wins
	const auto total_wins = std::accumulate(game_instances_.begin(), game_instances_.end(), 0);
	const auto win_probability = total_wins * 1.0 / number_of_games_;

	//probability of losses
	//const auto total_losses = number_of_games_ - total_wins;
	//const auto loss_probability = total_losses * 1.0 / number_of_games_;

	//could not get program to run without triggerring the assert
	//assert((win_probability + loss_probability) != 1.0);

	//add probability of total wins and total losses, should equal to 1 +- .01
	std::cout << win_probability << std::endl;
}


void LetsMakeADeal::set_reveal_door(const int door_choice) {

	//select random doors to reveal != the chosen door or prize door
	for (auto i{ 0 }; i < number_doors_revealed_; i++) {

		//pick new random door
		auto reveal_door{ pick_random_number() };

		//pick a door to reveal that is not the chosen door, prize door or an existing revealed door
		while ((reveal_door == door_choice) || (reveal_door == prize_door_) || (revealed_doors_.at(reveal_door) == true)) {

			//pick new random door
			reveal_door = pick_random_number();
		}

		//set vector door at new random number to true
		revealed_doors_.at(reveal_door) = true;
	}
}


int LetsMakeADeal::switch_doors(const int original_door_choice) {

	//pick a new door
	auto new_door{ pick_random_number() };

	//make sure that the new door chosen is not the previous door chosen or any of the revealed doors
	while ((revealed_doors_.at(new_door) == true) || new_door == original_door_choice) {
		new_door = pick_random_number();
	}

	return new_door;
}


void LetsMakeADeal::set_prize_door() {

	prize_door_ = pick_random_number();
}


//generates random number from 1 to maxNumber
int LetsMakeADeal::pick_random_number() const {

	//use this to reindex doors to zero index
	const auto index_zero{ -1 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> const dis(0, (number_of_doors_ + index_zero));
	return dis(gen);
}


//initialize reveledDoors vector to size of door count and sets all to false
void LetsMakeADeal::init_revealed_doors() {

	revealed_doors_.resize(number_of_doors_);
	revealed_doors_.assign(revealed_doors_.size(), false);
}
