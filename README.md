# CST136SRS00
Monty Hall

Name: Nathan Tout

Notes:
- takes in command line arguments (# games, bool 1/0, # doors, # disclosed)
- games are stored as tuples (car, goat) in a vector.


Unresolved Issues: 
- issue with taking in the default settings if not all peramiters are entered.
- currently no commandline help.
- Misunderstanding on how game is played with more than 3 doors.

---

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
