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

bool bubbleSort(int* begin, int* end){
    try{
        bool sorted = false;
        while(!sorted){
            sorted = true; //lets assume
            for(int* itx = begin; itx+1 != end; itx++){
                if(*itx > *(itx+1)){
                    swap<int>(itx, itx+1);
                    sorted = false; //assumption wronged lmao   
                }
            }
        }
    }
    catch(...){
        return false;
    }
    return true;
}

int main()
{
    int arr[] = {54,346,478,347,554,1634,6134,2134,879,35,568,135}; //12 ELEMS
    bubbleSort(arr,arr+12);
    for(int i = 0; i < 12; i++){
        cout << arr[i] <<" ";
    }
}