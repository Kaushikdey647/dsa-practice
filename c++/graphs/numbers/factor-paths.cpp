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
using namespace chrono;

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

int paths(int N)
{
    if (N == 2)
        return 1;
    if (N == 1)
        return 0;

    int number_of_paths = 0;

    for (int i = 2; i <= N / i; i++)
    {
        if (N % i != 0)
            continue; // Not a factor
        number_of_paths += paths(i);
        if (i != N / i)
        { // if it is not a square root
            number_of_paths += paths(N / i);
        }
    }

    return number_of_paths + 1;
}

int paths_cached( int N, vector<int> cache ){
    if( N == 2 )
        return 1;
    if (N == 1)
        return 0;

    if (cache[N] != 0){
        return cache[N];
    }

    int number_of_paths = 0;

    for (int i = 2; i <= N / i; i++){
        if(N%i != 0)
            continue; //Not a factor
        number_of_paths += paths_cached(i, cache);
        if( i != N/i ){ //if it is not a square root
            number_of_paths += paths_cached(N / i, cache);
        }
    }

    cache[N] = number_of_paths + 1;
    return cache[N];
}

int main()
{
    int N = 10000;
    vector<int> cacheVect(N, 0);
    auto beg = high_resolution_clock::now();
    cout << "Cached: " << paths_cached(N, cacheVect) << " ";
    auto mid = high_resolution_clock::now();
    cout << "Time Taken: " << duration<double>(mid - beg).count() << endl;
    cout << "Uncached: " << paths(N) << " ";
    auto end = high_resolution_clock::now();
    cout << "Time Taken: " << duration<double>(end - mid).count() << endl;
}