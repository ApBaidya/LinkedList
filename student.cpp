/*
1.6.2026  
*/
#include <cstring>
#include "Student.h"

Student::Student()
{
  fName = new char[16];
  lName = new char[16];
  //just remember id and gpa exist
}
Student::~Student()
{
  delete [] fName;
  delete [] lName;
}

void Student::setF(char* in_f)
{
  strcpy(fName, in_f);
}
void Student::setL(char* in_l)
{
  strcpy(lName, in_l);
}
void Student::setI(int in_i)
{
  id = in_i;
}
void Student::setG(float in_g)
{
  gpa = in_g;
}

char* Student::getF()
{
  return fName;
}
char* Student::getL()
{
  return lName;
}
int Student::getI()
{
  return id;
}
float Student::getG()
{
  return gpa;
}
