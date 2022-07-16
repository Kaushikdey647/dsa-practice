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

int getMedian1(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();

    //since there are 2n elements in play, the median would be average of arr[n] and arr[n-1]

    int x1, x2;
    int k = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    while (i < n && j < n)
    {
        if(arr1[i] >= arr2[j]){
            temp = arr2[j];
            j++;
        }
        else{
            temp = arr1[i];
            i++;
        }
        k++;
        if(k == n)
            x1 = temp;
        if(k == n-1)
            x2 = temp;
        if(k == n+1)
            break;
    }

    return (x1 + x2) / 2;
}

int helper0(vector<int>::iterator arrbeg, vector<int>::iterator arrend){
    int n = arrend - arrbeg;
    // finds median
    if(n%2){
        return *(arrbeg + (n + 1) / 2);
    }
    else{
        return (*(arrbeg + n / 2) + *(arrbeg + (n / 2 + 1))) / 2;
    }
}

int split(vector<int>::iterator arrbeg, vector<int>::iterator arrend){
    
}

    int getMedian2(vector<int>::iterator arr1beg, vector<int>::iterator arr1end, vector<int>::iterator arr2beg, vector<int>::iterator arr2end)
{
    int m1 = helper0(arr1beg, arr1end);
    int m2 = helper0(arr2beg, arr2end);
    if (m1 == m2)
        return m1;
    else if (m1 > m2){
        
    }
    else if (m1 < m2){

    }
}

int main()
{
 ios_base::sync_with_stdio(false);
}