/*
12.18.2025
Aparajita Baidya
testing if node and student work
*/

//include
#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

//func defs
/*
student* mkStud(student* s);
void ADD(node* head);
void PRINT();
void DELETE();
*/
//main
int main()
{
  //Proof that node works
  student* s = new student;//making student and changing their values
  char* c = new char[16];
  strcpy(c, "banana");
  s->setF(c);
  c[0]='\0';
  strcpy(c, "milk");
  s->setL(c);
  s->setI(54321);
  s->setG(3.39);
  student* s1 = new student;
  node* test = new node(s);//construct a node (head)
  node* test1 = new node(s1);//just making a next node
  cout << "(test->getStudent())->getI()"<<endl;
  cout << ((test->getStudent())->getI())<<endl;//using getStudent func
  cout << "test->getNext()"<<endl;
  test->setNext(test1);//setNext func
  cout << test->getNext();//getNext func
  delete test;
  delete test1;
  //node* head = NULL;
  //ADD(head);
  return 0;
}

/*
student* mkStud(student* s)
{
  char in_f[16];//first name
  char in_l[16];//last name
  int in_i;//student id
  float in_g;//gpa
  cout << "1st name:"<< endl;
  cin >> in_f;
  cin.ignore(10, '\n');
  cin.clear();
  cout << endl;
  cout << "2nd name:"<< endl;
  cin >> in_l;
  cin.ignore(10, '\n');
  cin.clear();
  cout << endl;
  cout << "ID:" << endl;
  cin >> in_i;
  cout << endl;
  cout<<"GPA:"<< endl;
  cin >> in_g;
  cout<<endl;
  s->setF(in_f);
  s->setL(in_l);
  s->setI(in_i);
  s->setG(in_g);
  return s;
}
void ADD(node* head)
{
  node * current = head; //keep track of current with this temp pointer
  //make new stud
  if(current==NULL)//if the first node in the linked list is NULL
  {
    //We give it a value
    student* nStud = new student;
    head = new node(mkStud(nStud));
  }
  else
  {
    //when there is a next node in linked list and wanna add
    while(current->getNext() != NULL)
    {
      current = current->getNext(); //current pointer = next node in list
      //pretty much iterate until we find end of linked list where we wanna add
    }
    student* nStud = new student;//make new stud
    current->setNext(new node(mkStud(nStud)));//add to end of linked list
  }
}
void PRINT(node* head)
{
  
}
void DELETE()
{

}
*/
