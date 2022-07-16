/*
 /$$                                 /$$                      /$$$$$$  /$$   /$$ /$$$$$$$$
| $$                                | $$                     /$$__  $$| $$  | $$|_____ $$/
| $$   /$$  /$$$$$$  /$$   /$$  /$$$$$$$  /$$$$$$   /$$$$$$ | $$  \__/| $$  | $$     /$$/ 
| $$  /$$/ |____  $$| $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$| $$$$$$$ | $$$$$$$$    /$$/  
| $$$$$$/   /$$$$$$$| $$  | $$| $$  | $$| $$$$$$$$| $$$$$$$$| $$__  $$|_____  $$   /$$/   
| $$_  $$  /$$__  $$| $$  | $$| $$  | $$| $$_____/| $$_____/| $$  \ $$      | $$  /$$/    
| $$ \  $$|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/      | $$ /$$/     
|__/  \__/ \_______/ \____  $$ \_______/ \_______/ \_______/ \______/       |__/|__/      
                     /$$  | $$                                                            
                    |  $$$$$$/                                                            
                     \______/                                                             



Name: Kaushik Dey
Institute: IIT Bhubaneswar
Mail: 20cs01043@iitbbs.ac.in
Linkedin: https://www.linkedin.com/in/kaushik-dey-235531201/


    "Everything should be made as simple as possible, But not simpler"	


                                                                 - Anonymous
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <unordered_set>
#include <list>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;


template<class T>
T cinget(std::istream& is){
  T result;
  is >> result;
  return result;
}

template<class T>
void swap(T*a, T*b){
T temp = *b;
*b = *a;
*a = temp;
}

class node{
public:
  int data;
  node* next;
  node(){

  }
  node(int data){
    this->data = data;
  }
  node(int data, node* nxtptr){
    this->data = data;
    this->next = nxtptr;
  }
};

node* reverse(node* head){
  node* prevptr = NULL;
  node* nxtptr = NULL;
  while(head){
    nxtptr = head->next;
    head->next = prevptr;
    prevptr = head;
    head  = nxtptr;
  }
  return prevptr;
}

node* mklist(int arr[], int N){
  node* head = new node;
  node* item = head;
  for(int i = 0; i < N; i++){
    item->data = arr[i];
    item->next = new node;
    item = item->next;
  }
  
  return head;
}

void print(node* head){
  while(head){
    cout << head->data << " ";
    head = head -> next;
  }
  cout << endl;
}

int main()
{

  int arr[] = {2,3,4,5,1,3,2,4,2,9};
  node* head = mklist(arr,10);
  print(head);
  node* gaand = reverse(head);
  print(gaand);
}