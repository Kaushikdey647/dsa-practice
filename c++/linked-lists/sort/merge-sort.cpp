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
Github: https://github.com/Kaushikdey647?tab=repositories
Twitter: https://twitter.com/KayDee647


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

class node {
public:

    int data;

    node* next;
  
    // Default constructor
    node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist {
    node* head;
  
public:
    // Default constructor
    linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int data){
        node* newNode = new node(data);

        if(!head){
            head = newNode;
            return;
        }

        node* temp = head;

        while(temp->next){
            temp = temp->next;
        }

        temp->next = new node;

    }
  
    // Function to print the
    // linked list.
    void printList(){
        node* temp = head;

        if(!head){
            cout << "Empty List" << endl;
        }
        else{
            while(temp){
                cout << temp->data << " -> ";   
                temp = temp->next;
            }
            cout << "END" << endl;
        }
    }
  
    // Function to delete the
    // node at given position
    bool deleteNode(int position){
        node *x = head, *y = NULL;
        int len = 0;
        if(!head) return false;
        //Find the length of the list
        while(!x){
            x = x->next;
            len++;
        }
        if(len < position) return false;
        x = head;
        if(position==1){
            head = head->next;
            delete x;
            return true;
        }
        while(position > 1){
            y = x;
            x = x -> next;
            --position;
        }

        y->next = x->next;
        delete x;
        return true;
    }

    void mergeSort(){
        //If there's one or zero element in the array then just return it
        if(!head || !(head->next)) return;
        //get the middlePointer

    }
};



int main()
{

}