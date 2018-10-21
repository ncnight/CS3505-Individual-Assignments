#ifndef SPIRAL_H
#define SPIRAL_H

#include <iostream>

/*
Written by Nithin Chalapathi - u0847388
CS 3505 - Fall 2018
Assignment 2 - Libharu
A2: Classes and Facades
*/

/* A spiral is an outwardly expanding circle.
Each object represents an instance that can be used to generate spirals in an context.
A spiral object at any instance represents a point on the spiral.
*/
class Spiral{
public:

  //Creates a new spiral at the location centerX and centerY with a radius starting at startinRadius
  // startingAngle is the clockwise angle from 12 o'clock to start the spiral. startingAngle is in degrees
  //Starting radius is clamped to between 30 and 90
  Spiral(double _centerX, double _centerY, double startingRadius, double startingAngle);

  //Moves the spiral to the next position
  //Prefix ++
  void operator++();

  //Moves the spiral to the next position
  //Postfix ++
  void operator++(int i);

  //Returns the X position of the current spiral point
  double getTextX();

  //Returns the Y position of the current spiral point
  double getTextY();

  //Returns the angle of the current spiral point in degrees
  double getTextAngle();

  //Declares << for ostream to be a friend
  friend std::ostream& operator<<(std::ostream& stream, Spiral spiral);

private:

  //Current X position
  double currentX;

  //Current Y position
  double currentY;

  //Center X point
  double centerX;

  //Center Y point
  double centerY;

  //Current Radius of the spiral
  double currentRadius;

  //Current angle of the spiral - degrees
  double currentAngle;
};

#endif
