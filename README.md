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
- Must enter a value for instances or program will display help
- Must enter a value for strategy or program will display help

The open parameter may not be more than (doors - 2).
If any parameter is intered incorrectly, a help menu will display.

Once the program has acceptable input parameters, it will display the resulting probability
of winning a car.

The program uses Knuth's S Algorithm to choose doors to open via k-combination.

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
