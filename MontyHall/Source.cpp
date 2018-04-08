// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "letsmakeadeal.h"

int main()
{
	for (auto i{ 0 }; i < 1000; i++)
	{
		auto testDeal{ LetsMakeADeal(3, 1, LetsMakeADeal::choice::stay) };

		auto testResult = testDeal.runGame();
	}

    return 0;
}
