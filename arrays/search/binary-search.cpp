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

bool binarySearch(int* begin, int* end, int X){
    int* middle  = begin + (end-begin)/2;
    if( *middle == X ) return true;
    else if(begin == end-1) return false;
    else{
        if(*middle > X){
            return binarySearch(begin,middle,X);
        }
        else if(*middle < X){
            return binarySearch(middle,end,X);
        }
    }
    return false;
}

void algoChecker(int* begin, int* end, bool(*search)(int*, int*,int)){
    bool ok = true;
    for(int* ptr = begin; ptr != end; ptr++){
        if(!search(begin,end,*ptr)){
            cout << "Couldn't find element " << *ptr << " at index " << ptr-begin << endl;
            ok = false;
        }
    }
    if(ok) cout << "All Checks Passed" << endl;
}

int main()
{
    int arr1[] = {1,3,6,9,10,11,124,235,456,586,698,890,1342,3524,4346,5477,5688,6798,7809,23466};
    int arr2[] = {1,4,7,9,12,42,65,74,86,99,123,234,315,451,512,674,721,893,901};
    cout << "Array1" << endl;
    algoChecker(arr1,arr1+20,&binarySearch);
    cout << "Array2" << endl;
    algoChecker(arr2,arr2+19,&binarySearch);
}