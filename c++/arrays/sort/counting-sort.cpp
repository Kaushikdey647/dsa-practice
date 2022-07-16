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

bool countingSort(int* begin, int* end, int range){
    try{
        int* count = new int[range];
        for(int* it = begin; it != end; it++){
            ++count[*it];
        }
        //make it cumulative count
        for(int i = 1; i < range; i++){
            count[i] += count[i-1];
        }

        int output[end-begin];
        //do some random shit
        for(int* it = begin; it != end; it++){
            output[count[*it] - 1] = *it;
            --count[*it];
        }
        //transfer all stuff
        for(int i = 0; i < end-begin; i++){
            begin[i] = output[i];
        }
    }
    catch(...){
        return false;
    }
    return true;
}

int main()
{
    int arr[] = {15,82,34,68,22,59,92,47,83,67,14,86,15,40,86,49,92,34,65,46,57,88,29,70,51,63,44,35,17,28,99,83,55,74,36,27,44}; //37 ELEMS
    countingSort(arr,arr+37,100);  
    for(int i = 0; i < 37; i++){
        cout << arr[i] <<" ";
    }
}