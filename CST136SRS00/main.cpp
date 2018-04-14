#include "stdafx.h"
#include <iostream>
#include <ctype.h>
#include <random>
#include <cctype>
#include <algorithm>
#include <string>
#include "LetsMakeADeal.h"


int main(int argc, char* argv[])
{
	auto doors{ 3 }, reveal{ 1 }, instance{ 0 };
	std::string plan{ "unknown" };
	auto strat{ false };

	if (argc < 3)
	{
		instance = *argv[1];
		plan.assign(argv[2]);
	}
	else if (argc < 4)
	{
		doors = *argv[1];
		instance = *argv[2];
		plan.assign(argv[3]);
	}
	else if (argc < 5)
	{
		doors = *argv[1];
		reveal = *argv[2];
		instance = *argv[3];
		plan.assign(argv[4]);
	}

	while (doors < 2)
	{
		std::cout << "\nMust have at least two doors:";
		std::cin >> doors;
	}
	while (reveal < 0)
	{
		std::cout << "\nDoors revealed must be a positive integer (can include 0):";
		std::cin >> reveal;
	}
	while (instance < 1)
	{
		std::cout << "\nInsantance must be a positive integer (positive none zero number):";
		std::cin >> instance;
	}
	while (reveal + 2 > doors)
	{
		std::cout << "\nGame paramiters not met. Can't reveal more doors than there are doors, or revealing all but the door selected.\n"
			<< "please lower the doors revealed";
		std::cin >> reveal;
	}

	std::transform(plan.begin(), plan.end(), plan.begin(), ::toupper);

	while (!plan.compare("STAY") && !plan.compare("SWAP"))
	{
		std::cout << "\nYou didn't enter a valid number for your strategy. Please enter Stay, or Swap:";
		std::cin >> plan;
	}
	if (plan.compare("SWAP"))
	{
		strat = true ;
	}
	else
	{
		strat = false ;
	}
	/*
	std::vector<LetsMakeADeal> gameShow;
	gameShow.reserve(instance);
	
	for (auto i = 0; i != instance; i++)
	{
		const LetsMakeADeal game(doors, reveal, strat);
		gameShow.push_back(game);
	}

	float wincount{ 0.0 };

	for (auto& game : gameShow)
	{
		const auto didIWin{ game.play() };
		if (didIWin)
		{
			wincount++;
		}
	}

	std::cout << wincount / instance;

	*/
    return 0;
}