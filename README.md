# CST136SRS00
Monty Hall

Name: 

---

Purpose: 

- Learn about random number generators in C++11
- Use the command line parameters for input
- Output command line usage help. 
- Learn about containers, including std::array

Project Name(s): MontyHall

Create a simulation of the game show "Let's Make a Deal."

Take as input though the command line the following information in this order:

- Number of doors.
- Number of trials.
- Switch or Stay strategy.

Output the probability of success as a single number in floating point format [0.0, 1.0]

Your code should create a class named "LetsMakeADeal".

Store in your class a std::array that contains the information if a Goat or Car was selected.

After the simulations are run, total the probablity of each strategy (Switch/Stay).

Display the probabilty of obtaining the Car.

Create an assert statement to ensure the probability of a Goat vs a Car is 1.0.

Provide command line help. Be concise and helpful. 
