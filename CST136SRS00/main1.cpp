// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/program_options.hpp>
#include "mhmodel.h"
#include "mhstats.h"
#include "mhresult.h"
#include <iostream>


namespace boost_program_options = boost::program_options;

int main(int argc, char ** argv)
{
	//<OPTIONS_HANDLER>
	int doors;
	int game_runs;
	bool verbose = false;

	boost_program_options::options_description description("Program options");
	description.add_options()
		("help", "Help message")
		("doors", boost_program_options::value<int>(&doors)->default_value(3), "Number of doors (default: 3)")
		("game_runs", boost_program_options::value<int>(&game_runs)->default_value(1), "Number of runs of the game (default :1)")
		("verbose", "Verbose mode, prints player and host actions (default: false)");

	boost_program_options::variables_map vm;
	boost_program_options::store(boost_program_options::parse_command_line(argc, argv, description), vm);
	boost_program_options::notify(vm);

	if (vm.count("help")) {
		std::cout << description << std::endl;
		return 0;
	}

	if (vm.count("verbose")) {
		verbose = true;
	}
	{	// </OPTIONS_HANDLER>

			//<MAIN>
		MHStats stats;
		MHModel montyHallGame(doors, verbose);
		MHResult results;
		for (int i = 0, i < game_runs; i++) {
			results = montyHallGame.theGame();
			stats.addStatistic(results);
			return 0;
		}
		stats.printStats();
		return 0;
	}



}


