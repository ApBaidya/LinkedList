/*
12.10.2025
*/
#include "node.h"

node::node(student* s)
{
  stud = s;
  next = NULL;
}
node::~node()
{
  delete s;
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
  return s;
}
