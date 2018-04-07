# CST136SRS00
Monty Hall

Name: Andrew Deraita
Class ID: Volbeat

---

PseudoCode:

Class will contain data members:
- # of doors (default 3)
- # of pre-disclosed doors (default 1)
- Door the car is behind
- Vector to store the ordered contents of their doors


Class member fuctions:
- setter for # of doors
- setter for # pre-disclosed doors
- setter for door car is behind
- function(s) to calculate probabilites

Will use std::vector for storing the doors and their contents
Will use gsl::span as the container to store instances of the class
Main loop will keep track of probabilities and average them
Then, output the probability of obtaining a car with selected choice

* Command line help:

---

Making a deal algorithm

- set vector to size of #doors with
- first element 1, rest 0 (1 = car, 0 = goat)
- randomly choose any door (selectDoor)
- remove a random door thats not selectDoor or 1st element from the vector for disclose # of times 
- now the 1st element is the car, and there are (#doors - #disclose) "0" elements after it
- if stay, return value of selectDoor element
- if switch, randomly pick another door (not selectDoor) and return value

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
