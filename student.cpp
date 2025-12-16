/*
12.16.2025  
*/
#include <cstring>
#include "student.h"

student::student()
{
  fname = new char[16];
  lname = new char[16];
  //just remember id and gpa exist
}
student::~student()
{
  delete [] fname;
  delete [] lname;
}

void student::setF(char* in_f)
{
  strcpy(fname, in_f);
}
void student::setL(char* in_l)
{
  strcpy(lname, in_l);
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
  return fname;
}
char* student::getL()
{
  return lname;
}
int student::getI()
{
  return id;
}
float student::getG()
{
  return gpa;
}
