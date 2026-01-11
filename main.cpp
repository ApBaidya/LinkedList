/*
1.10.2026 - Linked Lists
Aparajita Baidya
Student list project, but now with nodes
*/

//include
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//func defs
Student* mkStud(Student*& s);//create student pointer
void addList(Node* current, Node* newNode);//add node to the list
void ADD(Node*& head);//add new student to linked list
void PRINT(Node* head);//print out linked list
void DELETE(Node*& current, Node* prev, int id);//delete a node from list
void AVERAGE(Node* current, float& aveGPA, int& listLen);//average GPAs
void QUIT(Node*& current);//delete all elements from list

//main
int main()
{
  int listLen = 0;//help with ave
  int run = 0; //main while runs when 0
  char input[3]; //user input to decide what function to call
  Node* head = NULL;//head node, start of linked list
  int id; //id for deletion
  float aveGPA = 0; //average GPA
  Node* prev = NULL; //to aid with delete fuction
  while(run == 0)
  {
    cout << "What would you like to do? ([a] - add, [p] - print, [d] - delete, [av] - average, [q] - quit):" << endl;
    cin >> input;
    cin.ignore(10, '\n'); //because who would type something so ridiculously long that you would need more than 10 characters to ignore (o_o)
    cin.clear();
    if(strcmp(input, "a") == 0)
    {
      ADD(head);//put head pointer (start of list), will loop till reaches end, then add new node to end
    }
    else if(strcmp(input, "p") == 0)
    {
      //cout<<head->getNext()->getStudent()->getI();
      cout << "List:"<<endl;
      PRINT(head);
    }
    else if(strcmp(input, "d") == 0)
    {
      cout<< "What is the student's id?: "<<endl;
      cin >> id;
      cin.clear();
      DELETE(head, prev, id);
    }
    else if(strcmp(input, "av") == 0)
    {
      aveGPA = 0; //reset gpa
      listLen = 0;//reset list length 
      AVERAGE(head, aveGPA, listLen);
      cout<< "Average GPA: "<<aveGPA<<endl;
    }
    else if(strcmp(input, "q") == 0)
    {
      QUIT(head);
      run = 1;
    }
  }
  return 0;
}


Student* mkStud(Student*& s)
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
  //cout<<"2";
  s->setF(in_f);
  s->setL(in_l);
  s->setI(in_i);
  s->setG(in_g);
  //cout<<"Here";
  return s;
}

void addList(Node* current, Node* newNode)//find where to put new node
{
  if(newNode->getStudent()->getI()<current->getStudent()->getI())//if we get here, new node would have found it's position
  {
    return;
  }
  else
  {
    //if end of list
    if(current->getNext() == NULL || current->getNext() == 0)
    {
      current->setNext(newNode);//add to end of list
      return;
    }
    //if new node is greater than current but less than next
    if(newNode->getStudent()->getI()>current->getStudent()->getI() && newNode->getStudent()->getI()<current->getNext()->getStudent()->getI())
    {
      //put it between the values
      newNode -> setNext(current->getNext());
      current -> setNext(newNode);
    }
    else//if greater than student and greater than next
    {
      addList(current->getNext(), newNode);//recurse with next value in list
    }
  }
  return;
}

void ADD(Node*& head)
{
  Node* current = head; //keep track of current with this temp pointer
  Node* newnode = NULL;
  //make new stud
  if(current==NULL)//if the first node in the linked list is NULL
  {
    //We give it a student pointer
    cout << "made head"<<endl;
    Student* nStud = new Student;
    head = new Node(mkStud(nStud));//make head if head doesn't exist
    return;
  }
  else
  {
    Student* nStud = new Student;//make new stud
    newnode = new Node(mkStud(nStud));
    cout<<"made student"<<endl;
    //current->setNext(new Node(mkStud(nStud)));//add to end of linked list
    //cout << current->getNext();
  }
  if(head->getStudent()->getI()>newnode->getStudent()->getI())//if new node id is less tha head, make it new head
  {
    newnode -> setNext(head);
    head = newnode;
    return;
  }
  addList(head, newnode);
}

void PRINT(Node* head)
{
  Node* current = head; 
  if(current != NULL && current != 0)//if next exists, then let's cout all the student details!
  {
    //cout<<'a';
    Student* stud = current -> getStudent();//make a pointer to the node's student
    cout<<stud->getF()<<" "<<stud->getL()<<" "<<stud->getI()<<" "<<setprecision(3)<<stud->getG()<<endl;
    PRINT((current->getNext()));//time to recurse haha.
  }
}

void DELETE(Node*& current, Node* prev, int id)
{
  int nodeNum = 0; //what node we are on
  Node* c = current;
  //no elements
  if(current == NULL)//if there isn't a list
  {
    cout << "There isn't anything for you to delete." << endl;
    return;
  }
  if(current->getStudent()->getI()==id)
  {
    //head of list
    if(prev == NULL)
    {
      if(c->getNext() == NULL || c->getNext() ==0)//only value in list
      {
	c -> setNext(NULL);
	delete current;
	current = NULL;//reset head pointer
	return;
      }
      //something else in list
      else
      {
	c = current -> getNext();//store next pointer
	delete current;
	current = c;//replace head
	return;
      }
    }
    else//somewhere in the list
    {
      prev->setNext(current->getNext());//skip current
      delete current;
      return;
    }
  }
  c = current->getNext();
  prev = current;
  DELETE(c, prev, id);//recurse hahaha
}

void AVERAGE(Node* current, float& aveGPA, int& listLen)
{
  listLen ++;//keep track of how many values have been added to aveGPA
  if(current==NULL||current==0)//end condition
  {
    return;
  }
  if(current -> getNext()==NULL || current->getNext() ==0)//end of list, then average the values
  {
    aveGPA = aveGPA + (current ->getStudent()->getG());
    aveGPA = aveGPA/listLen;
    return;
  }
  else
  {
    aveGPA = aveGPA + (current -> getStudent() -> getG());//update average
    AVERAGE(current->getNext(), aveGPA, listLen);//recurse
  }
  return;
}

void QUIT(Node*& current)
{
  Node* c = current;
  if(current==NULL||current==0)
  {
    return;//end of list, then return
  }
  else
  {
    c = current -> getNext();//keep track of next value in list
    delete current;//delete current value
    QUIT(c);
  }
  return;
} 
