#include "stdafx.h"
#include <iostream>
#include <random>
#include <cctype>
#include "LetsMakeADeal.h"


int main()
{
	auto doors{ 3 }, reveal{ 1 }, instance{ 0 }, plan{ 0 };
	auto strat{ false };

	std::cout << "How many doors are there?";
	std::cin >> doors;
	std::cout << "\nHow many doors are being revealed?";
	std::cin >> reveal;
	std::cout << "\nHow many instances are we running?";
	std::cin >> instance;
	std::cout << "\nWhat's your strategy? Stay(0) or Swap(1)?";
	std::cin >> plan;

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
	while (plan != 0 && plan != 1)
	{
		std::cout << "\nYou didn't enter a valid number for your strategy. Please enter 0 for Stay, or 1 for Swap:";
		std::cin >> plan;
	}
	if (plan = 1)
	{
		strat = true ;
	}
	else
	{
		strat = false ;
	}
	
	auto wincount{ 0.0 };
	std::vector<LetsMakeADeal> gameShow;
	gameShow.reserve(instance);
	
	for (auto i = instance; i != 0; i--)
	{
		const LetsMakeADeal game(doors, reveal, strat);
		gameShow.push_back(game);
	}

	for (auto i = instance; i != 0; i--)
	{
		auto SaturdayNight{ gameShow.at(i - 1) };
		const auto didIWin = SaturdayNight.play();
		if (didIWin)
		{
			wincount++;
		}
	}

	std::cout << wincount / instance;


    return 0;
}