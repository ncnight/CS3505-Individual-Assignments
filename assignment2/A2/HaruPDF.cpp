#include "HaruPDF.h"
#include "hpdf.h"
#include <math.h>

/*
Written by Nithin Chalapathi - u0847388
CS 3505 - Fall 2018
Assignment 2 - Libharu
A2: Classes and Facades
*/

HaruPDF::HaruPDF(){
  pdf = HPDF_New (NULL, NULL);
  page = HPDF_AddPage (pdf);
  HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
  font = HPDF_GetFont (pdf, "Helvetica", NULL);
  HPDF_Page_SetTextLeading (page, 20);
  HPDF_Page_SetGrayStroke (page, 0);
  HPDF_Page_BeginText (page);
  font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
  HPDF_Page_SetFontAndSize (page, font, 30);
};

void HaruPDF::placeCharacter(char characterToPlace, float angle, float x, float y) {
  float angle_rads = (angle) * (M_PI / 180.0);
  HPDF_Page_SetTextMatrix(page,
                          cos(angle_rads), sin(angle_rads), -sin(angle_rads), cos(angle_rads),
                          x, y);
  char buffer[2];
  buffer[0] = characterToPlace;
  buffer[1] = 0;
  HPDF_Page_ShowText (page, buffer);
};

void HaruPDF::save(const char* name){
  HPDF_Page_EndText (page);
  HPDF_SaveToFile (pdf, name);
  HPDF_Free (pdf);
};
