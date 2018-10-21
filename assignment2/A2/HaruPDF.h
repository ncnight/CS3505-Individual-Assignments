#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"

/*
Written by Nithin Chalapathi - u0847388
CS 3505 - Fall 2018
Assignment 2 - Libharu
A2: Classes and Facades
*/

/*
Facade class that wraps over haruPDF library.
Each instance represents a new PDF.
*/
class HaruPDF{
public:

  //Constructor - creates a new PDF
  HaruPDF();

  //Places the specified char at the location and Angle given
  // Angle is given in degrees
  void placeCharacter(char characterToPlace, float angle, float x, float y);

  //Finishs and closes writing to the file.
  //Saves the file as the specified name
  void save(const char* name);

private:

  //pdf object
  HPDF_Doc  pdf;

  //Current page
  HPDF_Page page;

  //Font of the pdf
  HPDF_Font font;
};

#endif
