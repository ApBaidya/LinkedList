/*
1.8.2026 - Linked Lists
Aparajita Baidya
Student list project, but now with nodes
*/

//include
#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

//func defs
Student* mkStud(Student*& s);//create student pointer
Node* SortList(Node* head);//sort linked list, return head of sorted list
void ADD(Node*& head);//add new student to linked list
void PRINT(Node* head);//print out linked list
void DELETE(Node*& head, int id);//delete a node from list
void AVERAGE(Node* head, float& aveGPA);//average GPAs
void QUIT(Node*& head);//delete all elements from list

//main
int main()
{
  int run = 0; //main while runs when 0
  char input[3]; //user input to decide what function to call
  Node* head = NULL;//head node, start of linked list
  int id; //id for deletion
  float aveGPA = 0; //average GPA
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
      DELETE(head, id);
    }
    else if(strcmp(input, "av") == 0)
    {
      AVERAGE(head, aveGPA);
    }
    else if(strcmp(input, "q") == 0)
    {
      QUIT(head);
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
  s->setF(in_f);
  s->setL(in_l);
  s->setI(in_i);
  s->setG(in_g);
  return s;
}

Node* SortList(Node* head)//sort Nodes by id, least to greatest 
{
  //end condition --> when head->getNext() == NULL
  if(head -> getNext() == NULL)
  {
    return head;
  }
  //Split condition --> pick pivot --> left linked list and right linked list
  Node* leftHead = NULL;//for the left list
  Node* rightHead = NULL;//for the right list
  Node* pivot = head;//just let the pivot be the head node, easy
  Node* current = head -> getNext(); //will be the value which will be looked at
  pivot -> setNext(NULL);//just in case, lets seperate it from the list
  while(current != NULL)//go through list
  {
    if(pivot->getStudent()->getI() > current->getStudent()->getI())//if current is less than pivot -> left
    {
      if(leftHead == NULL)
      {
	leftHead = current;//set left head
	current = current->getNext();//get the next value
	leftHead->setNext(NULL);//detach left head from list
      }
      else
      {
	Node* tempL = leftHead; //end of left list
	while(tempL->getNext!=NULL)//go thru list until reach end
	{
	  tempL = tempL->getNext();
	}
	tempL -> setNext(current);//add current to linked list
	current = current->getNext();//current becomes next val in list
	tempL -> getNext() -> setNext(NULL);//reset next in the new node added to left
      }
    }
    if(pivot->getStudent()->getI() < current->getStudent()->getI())//if current greater than pivot -> right
    {
      if(rightHead == NULL)//code is essentially the same as the left list code
      {
	rightHead = current;
	current = current -> getNext();
	rightHead->setNext(NULL);
      }
      else
      {
	Node* tempR = rightHead;//end of right list
	while(tempR->getNext!=NULL)//pretty much the same as setting the left list
	{
	  tempR = tempR -> getNext();
	}
	tempR->setNext(current);
	current = current -> getNext();
	tempR -> getNext() -> setNext(NULL);
      }
    }
  }
  //Recurse on both sides
  leftHead = SortList(leftHead);
  rightHead = SortList(rightHead);
  //Combine the left + pivot + right
  pivot -> setNext(rightHead);
  //find end of left list
  leftTail = leftHead;//default
  while(leftTail!=NULL)
  {
    if(leftTail->getNext() == NULL)
    {
      leftTail->getNext = pivot;//connect left tail to pivot
    }
  }
  //return list
  return leftHead;
}

void ADD(Node*& head)
{
  Node* current = head; //keep track of current with this temp pointer
  //make new stud
  if(current==NULL)//if the first node in the linked list is NULL
  {
    //We give it a student pointer
    Student* nStud = new Student;
    head = new Node(mkStud(nStud));//make head if head doesn't exist
  }
  else
  {
    //when there is a next node in linked list and wanna add
    while(current->getNext() != NULL && current ->getNext()!=0)
    {
      current = current->getNext(); //current pointer = next node in list
      //pretty much iterate until we find end of linked list where we wanna add
    }
    Student* nStud = new Student;//make new stud
    current->setNext(new Node(mkStud(nStud)));//add to end of linked list
    cout << current->getNext();
  }
  Node* temp = NULL;
  head = SortList(head);//sort ID nums
}

void PRINT(Node* head)
{
  Node* current = head; 
  if(current != NULL && current != 0)//if next exists, then let's cout all the student details!
  {
    //cout<<'a';
    Student* stud = current -> getStudent();//make a pointer to the node's student
    cout<<stud->getF()<<" "<<stud->getL()<<" "<<stud->getI()<<" "<<stud->getG()<<endl;
    PRINT((current->getNext()));//time to recurse haha.
  }
}

void DELETE(Node*& head, int id)
{
  int nodeNum = 0; //what node we are on
  Node* current = head;
  Node* previous = NULL;//need previous node so I can change it's nextNode to NULL after deleting current
  //no elements
  if(current == NULL)//if there isn't a list
  {
    cout << "There isn't anything for you to delete." << endl;
    return;
  }
  //one element
  //delete head
  //delete tail
  //normal delettion
}

void AVERAGE(Node* head, float& aveGPA)
{

}

void QUIT(Node*& head)
{
  Node* current = head;
  Node* previous = NULL;//previous node
} 
