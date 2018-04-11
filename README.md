# CST136SRS00
---

Monty Hall

Name: Andrew Deraita

Class ID: Volbeat


---
### Program options:


Option | Description | Range
--- | --- | ---
`-d, --doors` | number of doors | `unsigned int`
`-o, --open` | number of doors to open | `unsigned int`
`-i, --instances` | number of game instances| `unsigned int`
`-s, --strategy` | door selection strategy | `switch or stay`


Some or all of the parameters may be input.

The default values are:

- 3 doors
- 1 open
- 1 instance
- stay strategy

The open parameter may not be more than (doors - 2).
If any parameter is intered incorrectly, a help menu will display.

Once the program has acceptable input parameters, it will display the resulting probability
of winning a car.

---
### Notes to self:


lookup: knuth's S algorithm for opening doors

so argv[] will look like this {"-d", "3", "-o", "1", "-i", "1", "-s", "stay"} for this example

so parsing will involve looping through each argv[i], starting with 1 (not 0)

first, set default values for doors, open, instances, and strategy

bool fail = false; (flag for if any command line params are invalid)

if first char of argv[i] is "-", then the following is a command
	switch(second char of argv[i]):
		doors:
			compare argv[i] (minus the -) to "d"
			if it is, increment i
			look at argv[i], istream it to an int.
			if successful, assign to doorsP variable (param class data member?) for the door parameter
			else fail = true;
		open:
			same with doors
		instance:
			same with doors
		strategy:
			same with doors except have to do strncmp for the second parameter
		default: (this is for when )
			fail = true;

if *(argv[1]) != '-', then fail = true;




if a parameter is missing, just use default value.


---
### SRS Details


Purpose: 

- Use the command line parameters for input
- Output command line usage help. 
- Learn about containers, including std::array, std::vector, gsl::span
- Learn about random number generators in C++11

Project Name(s): MontyHall

Create a simulation of the game show "Let's Make a Deal."

Take as input though the command line the following information:

- Number of doors. (default==3)
- Number of doors to pre-disclose. (default==1)
- Number of game instances.
- Switch or Stay strategy.

Create a class named "LetsMakeADeal" that represents a game instance. 

Store your game instances in a container obtained from a library. 

Output the probability of success as a single number in floating point format [0.0, 1.0]

After the simulations are run, total the probablity.

Display the probabilty of obtaining the Car.

Create an assert statement to ensure the probability of a Goat vs a Car is 1.0. 

Provide command line help in the event the command line is incomplete. Be concise and helpful. 
