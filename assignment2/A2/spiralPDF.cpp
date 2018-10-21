#include <math.h>
#include <iostream>
#include <string.h>
#include "HaruPDF.h"
#include "Spiral.h"

/*
Written by Nithin Chalapathi - u0847388
CS 3505 - Fall 2018
Assignment 2 - Libharu
A2: Classes and Facades
*/

using namespace std;

/*
Generates a PDF with a spiral of the given string command line argument
If no string is given then an error message is displayed
PDF is named output.pdf
*/
int main(int argc, char** argv){

  if(argc != 2) {
    cout << "Incorrect number of arguments. Please only input a string to be displayed." << endl;
    return 0;
  };

  char* outputString = argv[1];
  HaruPDF pdf;

  double centerX = 210;
  double centerY = 300;
  double startingRadius = 65;
  double startingAngle = 180;
  Spiral spiral(centerX, centerY, startingRadius, startingAngle);


  for( int i = 0; i < (int) strlen(outputString); i++) {
    //getTextAngle() - 90 since the PDF needs a modified angle to display letters properly
    pdf.placeCharacter(outputString[i], spiral.getTextAngle()-90, spiral.getTextX(), spiral.getTextY());
    spiral++;
  };

  const char* fileName = "spiralPDF.pdf";
  pdf.save(fileName);
};
