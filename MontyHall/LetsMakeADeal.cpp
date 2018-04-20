#include "stdafx.h"
#include <iostream>
#include <random>
#include <tuple>
#include "LetsMakeADeal.h"
using namespace std;


void LetsMakeADeal::set_values(int n, bool b , int x, int y)
{
	instances = n;
	stay = b;
	doors = x;
	disclose = y;
}

int LetsMakeADeal::get_instances()
{
	return instances;
}

int LetsMakeADeal::get_doors() 
{
	return doors;
}


int LetsMakeADeal::get_disclose()
{
	return disclose;
}


bool LetsMakeADeal::get_stay()
{
	return stay;
}

LetsMakeADeal::vect_tup LetsMakeADeal::get_outcome()
{
	return outcome;
}

int LetsMakeADeal::pick_door(int open, int num_door) 
{
	// en.cppreference.com/w/cpp/numeric/random
	std::random_device rd;  
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(open, num_door);
	return dis(gen);
}

void LetsMakeADeal::play_game(int num_game, bool stay, int doors, int disclose) 
{
	for (int i = 0; i < num_game; ++i)
	{
		int car = 0;
		int goat = 0;
		if (doors - disclose == 2)
		{
			int choice = pick_door(1, 3);
			if (stay == true) {
				if (choice == 1)
				{
					car = 1;
				}
				else
				{
					goat = 1;
				}
			}
			else {
				if (choice != 1) {
					car = 1;
				}
				else {
					goat = 1;
				}
			}
		}
		else 
		{
			if (stay == true) {
				int choice = pick_door(1, doors);
				if (choice == doors) {
					car = 1;
				}
				else {
					goat = 1;
				}
			}
			else {
				int new_choice = pick_door(disclose + 1, doors);
				if (new_choice == doors) {
					car = 1;
				}
				else {
					goat = 1;
				}
			}
		}
		outcome.push_back(std::make_tuple(car, goat));
	}
return;
}


float LetsMakeADeal::car_prob(vect_tup games, int num) 
{
	float sum{};
	for (std::tuple<int, int> n : games) {
		sum += get<0>(n);
	}
	//cout << "The probability of winning a car is: " << sum / num << endl;
	return sum / num;
}

float LetsMakeADeal::goat_prob(vect_tup games, int num)
{
	float sum{};
	for (std::tuple<int, int> n : games) {
		sum += get<1>(n);
	}
	//cout << "The probability of winning a goat is: " << sum / num << endl;
	return sum / num;
}