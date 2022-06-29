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

/**
 * @brief lps() longest proper prefix which is also a suffix
 * 
 */
vector<int> lps( string pattern ){
    int len = 0; // length of the previous longest prefix suffix

    vector<int> lpsvect( pattern.length(), 0 );

    lpsvect.push_back(0); //First Element of LPS is always zero
    for (int i = 1; i < pattern.length(); i++)
    {
        if ( pattern[i] == pattern[len] ){
            len++;
            lpsvect[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lpsvect[len - 1];
            }
            else{
                lpsvect[i] = 0;
                i++;
            }
        }
    }

    return lpsvect;
}

/**
 * @brief (Knuth Morris Pratt) Algorithm for Pattern Searching
 *
 * @param pattern
 * @param txt
 * @return vector<int>
 */
vector<int> KMPSearch( string pattern, string txt ){
    int m = pattern.length();
    int n = txt.length();

    vector<int> result;
    vector<int> lpsvect = lps(pattern);

    int i = 0;
    int j = 0;

    while(i < n){
        if(pattern[j] == txt[i]){
            j++;
            i++;
        }
        if(j == m){
            result.push_back(i - j);
            j = lpsvect[j - 1];
        }
        else if (i < n && pattern[j] != txt[i] ){
            if(j != 0){
                j = lpsvect[j - 1];
            }
            else{
                i++;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr =  KMPSearch("hello", "hello there hello world this looks like a hello place huehuehue one last time hello");
    cout << "Found \'" << "hello" << " \' in ";
    for (auto it : arr)
    {
        cout << it << ", ";
    }
    cout << endl;
}