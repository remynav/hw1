/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* in = new Node{1, nullptr};
  in->next = new Node{2, nullptr};

  Node* odds = nullptr;
  Node* evens = nullptr;
  split(in, odds, evens);

  cout << "odds: " ;
  for(Node* t = odds; t != nullptr; t = t->next){
    cout << t->value << " ";
  }
  cout << "/n";

  cout <<"evens: " ;
  for(Node* p = evens; p != nullptr; p = p->next){
    cout << p->value << " ";
  }

  while(odds){
    Node* temp = odds->next;
    delete odds;
    odds = temp;
  }

  while(evens){
    Node* temp = evens->next;
    delete evens;
    evens = temp;
  }

  return 0;

}
