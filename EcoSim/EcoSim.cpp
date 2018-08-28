#include <iostream>
#include <math.h>
using namespace std;

/*
Nithin Chalapathi - u0847388
CS3505 - Software practice II
Assignment 1 - EcoSim - C++ Starter
Fall 2018

EcoSim - Plots flucuations in rabbit and fox populations in an ascii chart using
         user inputed paramaters to the Lotka-Volterra equations.
*/

//Todo items
// Does it matter the order which initial fox and rabbit populations are captured?
// is it ok to declare functions before or is it standard to put main on the bottom?

//Declaring functions so that main will compile
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void plotPopulations(double numRabbits, double numFoxes, double fractionalScale);
void incrementCounter(int& counter);

/*
A main function that sets the parameters needed for the update
equation, that asks the user for an initial rabbit and
fox population and that runs the simulation for 500 steps
or until the predator or prey population goes below 1.
Store the number of rabbits and foxes as doubles to let the
equations work a little more smoothly. If the user enters
anything that cannot be converted to a double for an initial population,
give a warning message and terminate the program. Use cin as the mechanism
for capturing input.
*/
/*
Given an initial fox and rabbit population, the program prints out an ascii table of
population flucuations according to the Lotka-Volterra equations.
*/
int main(){

  //Initial paramaters
  double rabbitGrowth = 0.2; //g
  double predationRate = 0.002; //p
  double foxPreyConversion = 0.6; //c
  double foxMortalityRate = 0.2; //m
  double carryCapacity = 1000; //k
  int numberOfGenerations = 500; //Number of steps

  //obtaining user inputs
  cout << "Enter initial population of the foxes then the rabbits." << endl;
  double foxPopulation, rabbitPopulation;
  if(!(cin >> foxPopulation >> rabbitPopulation)) {
    cout << "WARNING: Invalid inputs for the initial populations for either foxes or rabbits";
    cout << endl;
  }

  //Looping for each generation and printing the values for fox and rabbit populations
  int currentGeneration = 0;
  while(currentGeneration < 500 && foxPopulation > 0 && rabbitPopulation > 0) {

    updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity,
      rabbitPopulation, foxPopulation);



  }
}

/*
A population update function that takes in the model parameters and
then the number of rabbits and number of foxes with a pass-by-reference style.
(This style of function is a good example for why
object-oriented programming was developed). Each iteration in the
main function should call this update function.
The function signature should be:
*/

//Given a g, p, c. m. and k (defined by the Lotka-Volterra equations), rabbit and fox populations are updated
void updatePopulations(double g, double p, double c, double m, double K,
  double& numRabbits, double& numFoxes) {

    double deltaRabbits, deltaFoxes;

    //Lotka-Volterra equations
    deltaRabbits = g*numRabbits * (1 - (numRabbits / K)) - p * numRabbits * numFoxes;
    deltaFoxes = c * p * numRabbits * numFoxes - m * numFoxes;

    //update populations
    numRabbits = numRabbits + deltaRabbits;
    numFoxes = numFoxes + deltaFoxes;
  }

/*
A void helper function plotCharacterAtPosition that takes in an int number
and a character and sends to std::cout number-1 spaces followed by the character.
Unlike array indexing, the position of the leftmost character on the screen is position 1.
If the positioning number is less than 1, just output the character.
*/
/*
Given a int num and char c, sends num-1 spaces followed by char c to std::cout.
If num < 1, the char c is just outputed.
*/
void plotCharacterAtPosition (int num, char c) {
  char space = ' ';

  //Print num - 1 spaces
  for(int numberOfSpaces = 0; numberOfSpaces < num-1; numberOfSpaces++) {
    cout << space;
  }

  //Print char c
  cout << c;
}


/*
A void charting function plotPopulations that has parameters for the number of rabbits,
the number of foxes, and a fractional scale factor in that order.
Using the plotCharacterAtPosition function as a helper,
it should draw a row of a text chart with an 'F' for foxes and 'r' for rabbits
and '*' if the drawing of each would overlap. The characters should be
drawn in position floor(num*scale) + 1 from the left margin (
with the first space being position 1).
As some examples, if the scale factor is 0.1
(which is the scale you should use in your submitted code):
- for a fox population of 10 and a rabbit population of 5, then the output should be
rF
- for a fox population of 52 and a rabbit population of 27, the output should be
  r  F
You may find it useful to use '-' during testing rather
than ' ' to position the 'F' and 'r' characters so you can count more easily.
Use ' ' in your final submission.
*/
void plotPopulations(double numRabbits, double numFoxes, double fractionalScale) {

  char foxChar = 'F';
  char rabbitChar = 'r';
  char tieChar = '*';

  int rabbitPosition = floor(numRabbits * fractionalScale) + 1;
  int foxPosition = floor(numFoxes * fractionalScale) + 1;

  //In the case both are positions are the same, output "*" instead and return.
  if(rabbitPosition == foxPosition) {
    plotCharacterAtPosition(rabbitPosition, tieChar);
    return;
  }

  //Determines which needs to be outputed first
  //Modifies the higher position so spaces aren't double outputed
  if(rabbitPosition > foxPosition) {
    rabbitPosition = rabbitPosition - foxPosition;
    plotCharacterAtPosition(foxPosition, foxChar);
    plotCharacterAtPosition(rabbitPosition, rabbitChar);
  }
  else if (foxPosition > rabbitPosition) {
    foxPosition = foxPosition - rabbitPosition;
    plotCharacterAtPosition(rabbitPosition, rabbitChar);
    plotCharacterAtPosition(foxPosition, foxChar);
  }
}

/*A helper function incrementCounter that returns void and
has a pointer to an integer parameter. The function should add 1
to the value pointed to by the pointer. You must use this function to
update your iteration count in the main function.
This is purely busy work to practice passing pointers.*/

//Increments a given integer reference
void incrementCounter(int& counter) {
  counter++;
}
