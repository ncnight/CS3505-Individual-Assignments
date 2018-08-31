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

//Method stubs so that main will compile
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void plotPopulations(double numRabbits, double numFoxes, double fractionalScale);
void incrementCounter(int& counter);

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
  double fractionalScale = 0.1;

  //obtaining user inputs
  cout << "Enter initial population of the rabbits then the foxes." << endl;
  double foxPopulation, rabbitPopulation;
  if(!(cin >> rabbitPopulation >> foxPopulation)) {
    cout << "WARNING: Invalid inputs for the initial populations for either foxes or rabbits";
    cout << endl;
  }

  //Plot initial generation
  plotPopulations(rabbitPopulation, foxPopulation, fractionalScale);

  //Looping for each generation and printing the values for fox and rabbit populations
  int currentGeneration = 0;
  while(currentGeneration < 500 && foxPopulation > 0 && rabbitPopulation > 0) {

    updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity,
      rabbitPopulation, foxPopulation);

    plotPopulations(rabbitPopulation, foxPopulation, fractionalScale);

    incrementCounter(currentGeneration);
  }
}

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
Given a number of rabbits and foxes and a fractional scale,
the method prints r and F, respectively, in position floor(num*scale) + 1 from the
left margin where the first space is 1.
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
    //End with endl
    cout << endl;
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

  //end with endl
  cout << endl;
}

//Increments a given integer reference
void incrementCounter(int& counter) {
  counter++;
}
