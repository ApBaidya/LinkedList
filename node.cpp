/*
12.18.2025
*/
#include "node.h"
#include <iostream>
node::node(student* s)
{
  stud = s;
  next = NULL;
}
node::~node()
{
  //std::cout<< "a";
  delete stud;
  //std::cout << "b";
}
void node::setNext(node* in_n)
{
  next = in_n;
}
node* node::getNext()
{
  return next;
}
student* node::getStudent()
{
  return stud;
}
