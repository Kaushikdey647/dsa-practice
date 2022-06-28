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

/*
 * Find the Minimum length Unsorted Subarray,
 * sorting which makes the complete array sorted

Given an unsorted array arr[0..n-1] of size n,
find the minimum length subarray arr[s..e] such that
sorting this subarray makes the whole array sorted.

 * Examples: 
1) If the input array is
    [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60],
    your program should be able to find that the subarray
    lies between the indexes 3 and 8.
2) If the input array is
    [0, 1, 15, 25, 6, 7, 30, 40, 50],
    your program should be able to find that the subarray
    lies between the indexes 2 and 5.

*/

pair<int*,int*> minimumUnsortedArray(int* begin, int* end){

    pair<int*,int*> result(begin,begin);

    //find the first point of disturbance
    for(int* i = begin; i != end-1; i++){
        if( *i > *(i+1)){
            result.first = i;
            break;
        } 
    }

    //find the second point of disturbance
    for(int* i = end-1; i != begin; i--){
        if( *i < *(i-1)){
            result.second = i;
            break;
        } 
    }

    //check in case the array is sorted
    if(result.second == result.first){
        return result;
    }

    int* max = result.first; //eh just random
    int* min = result.second; //both of em


    //Get the minimum and maximum elements in the array
    for (int* i = result.first; i != result.second+1; i++)
    {
        if(*i > *max) max = i;
        if(*i < *min) min = i;
    }

    // Check the smallest element greater than min
    for (int* i = begin; i != result.first; i++)
    {
        if(*i > *min){
            result.first = i;
            break;
        }
    }

    // Check the largest element smaller than max
    for (int* i = end-1; i != result.second; i--)
    {
        if(*i < *max){
            result.second = i;
            break;
        }

    }

    return result;
    
}

int main()
{
    int arr1[10] = {1,3,4,5,2,7,6,8,9}; //case 1, kinda normal
    int arr2[10] = {2,3,4,1,9,8,6,7,5}; //case 2, two sided shithead
    int arr3[10] = {1,2,3,4,5,9,7,6,8}; //case 3, one sided shithead
    int arr4[10] = {9,8,7,6,5,4,3,2,1}; //reverse sorted
    int arr5[10] = {1,2,3,4,5,6,7,8,9};  //straight sorted
    pair<int*,int*> sol;
    sol = minimumUnsortedArray(arr1,arr1+9);
    cout << "Begin: " << *sol.first << ", End: " << *sol.second << endl;
    sol = minimumUnsortedArray(arr2,arr2+9);
    cout << "Begin: " << *sol.first << ", End: " << *sol.second << endl;
    sol = minimumUnsortedArray(arr3,arr3+9);
    cout << "Begin: " << *sol.first << ", End: " << *sol.second << endl;
    sol = minimumUnsortedArray(arr4,arr4+9);
    cout << "Begin: " << *sol.first << ", End: " << *sol.second << endl;
    sol = minimumUnsortedArray(arr5,arr5+9);
    cout << "Begin: " << *sol.first << ", End: " << *sol.second << endl;


    // for(int i = 0; i < 5; i++){
    //     pair<int*, int*> sol = minimumUnsortedArray(&arr[i][0],&arr[i][10]);
    //     cout << "Begin: " << sol.first-(&arr[i][0]) << ", End: " << sol.second-(&arr[i][0]) << endl;
    // }

}