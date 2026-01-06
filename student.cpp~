/*
12.16.2025  
*/
#include <cstring>
#include "student.h"

student::student()
{
  fName = new char[16];
  lName = new char[16];
  //just remember id and gpa exist
}
student::~student()
{
  delete [] fName;
  delete [] lName;
}

void student::setF(char* in_f)
{
  strcpy(fName, in_f);
}
void student::setL(char* in_l)
{
  strcpy(lName, in_l);
}
void student::setI(int in_i)
{
  id = in_i;
}
void student::setG(float in_g)
{
  gpa = in_g;
}

char* student::getF()
{
  return fName;
}
char* student::getL()
{
  return lName;
}
int student::getI()
{
  return id;
}
float student::getG()
{
  return gpa;
}
