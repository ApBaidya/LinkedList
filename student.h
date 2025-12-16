/*
student header file
12.10.2025
*/

#ifndef STUDENT
#define STUDENT
#include <cstring>
class student
{
 private:
  char* fName;//first name = new char[16]
  char* lName; //last name = new char[16]
  int id; //student number ID
  float gpa; //...gpa
 public:
  student();//constructor
  ~student();//destructor
  void setF(char* in_f);//in_n = input first name
  void setL(char* in_l);//in_l = input last name
  void setI(int in_i);//in_i = input ID
  void setG(float in_g)//in_g = input GPA
  char* getF();//return first name
  char* getL();//return last name
  int getI();//return ID
  float getG();//return GPA
}

#endif //STUDENT
