Monty Hall

Class ID: Phantump

Notes: When sending in parameters in the command line, they need to come in this order: [Instances], [Stay or Swap plan], [Doors total], [Doors to reveal]
The stay or swap plan asks for boolian logic, so 0 for stay and 1 for swap. If it doesn't get either of those numbers, it'll mention it to you.
The first two commands are required, and if not inputed, will prompt the user to do so, the last two are optional and will default to 3 and 1 as per specifications.
If any number is outside of bounds, or doesn't follow the rules of the game (like reveal more doors than there are doors) it will note that and prompt you for a new number.
Also, by the structure of the input, you can't change doors revealed without stateing doors, however you can just put 3 for the default if that's what you wish

---

Purpose: 

- Use the command line parameters for input
- Output command line usage help. 
- Learn about containers, including std::array, std::vector, gsl::span
- Learn about random number generators in C++11

SRS ID: CST136SRS00
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
