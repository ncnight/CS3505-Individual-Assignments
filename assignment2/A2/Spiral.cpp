#include "Spiral.h"
#include <math.h>
#include <iostream>

/*
Written by Nithin Chalapathi - u0847388
CS 3505 - Fall 2018
Assignment 2 - Libharu
A2: Classes and Facades
*/


Spiral::Spiral(double _centerX, double _centerY, double startingRadius, double startingAngle):
  centerX(_centerX), centerY(_centerY),  currentRadius(startingRadius), currentAngle(startingAngle){

    //clamp currentRadius
    if(currentRadius < 30) {
      currentRadius = 30;
    }
    else if (currentRadius > 90) {
      currentRadius = 90;
    }

    double rad = (currentAngle) / 180 * M_PI;
    currentX = centerX + cos(rad) * currentRadius;
    currentY = centerY + sin(rad) * currentRadius;
  };

void Spiral::operator++ (){
  //Move to next angle and radius
  //Values choosen by experimentation
  currentAngle -= 900/currentRadius;
  currentRadius += 80/currentRadius + .3;

  double rad = (currentAngle) / 180 * M_PI;

  currentX = centerX + cos(rad) * currentRadius;
  currentY = centerY + sin(rad) * currentRadius;

};

void Spiral::operator++(int i) {
  operator++();
};

double Spiral::getTextX(){
  return currentX;
};

double Spiral::getTextY(){
  return currentY;
};

double Spiral::getTextAngle(){
  return currentAngle;
};

std::ostream& operator<<(std::ostream& stream, Spiral spiral) {
  stream << "Current X position: " << spiral.currentX << std::endl;
  stream << "Current Y position: " << spiral.currentY << std::endl;
  stream << "Current radius: " << spiral.currentRadius << std::endl;
  stream << "Current angle: " << spiral.currentAngle;
  return stream;
}
