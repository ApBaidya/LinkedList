
/*
12.16.2025
node class header file
*/
#ifndef NODE
#define NODE
#include "student.h"//because student pointer?

class node
{
 private:
  student* stud;//the student pointer --> set to student*
  node* next;//next node's pointer --> set to NULL
 public:
  node(student*);//constructor
  ~node();//destructor
  void setNext(node* in_n);//set next node
  node* getNext();//return next node pointer
  student* getStudent();//return student pointer
};

#endif //NODE
