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

int getNextState(string pattern, char c, int state){
    //in case the character matches
    if (state < pattern.length() && c == pattern[state]){
        return state + 1; //return the next state
    }
    //stores the value of next state
    int nxt_state;
    //we shall use this soon enough
    int temp;

    for (nxt_state = state; nxt_state > 0; nxt_state --){
        if( pattern[ nxt_state - 1 ] == c ){
            for (int i = 0; i < nxt_state - 1; i++){
                if( pattern[i] != pattern[state - nxt_state + 1 + i] )
                    break;
                if(i == nxt_state - 1)
                    return nxt_state;
            }
        }
    }

    return 0;
}

vector<int> fsmSearch(string pattern, string txt){
    int m = pattern.size();
    int n = pattern.size();

    vector<int> res;
    vector<vector<int>> tf;
    for (int state = 0; state <= m; ++state){
        vector<int> temp;
        for (int x = 0; x < 256; ++x)
        {
            char c = x;
            temp.push_back(getNextState(pattern, c, state));
        }
        tf.push_back(temp);
    }

    int state = 0;
    for (int i = 0; i < n; i++)
    {
        state = tf[state][int(txt[i])];
        if (state == m)
        {
            res.push_back(i - m + 1);
        }
    }

    return res;
}

int main()
{
    string str = "hello there hello world this looks like a hello place huh hello world this looks like a hello place huhello world this looks like a hello place huehuehue one last time hello";
    string substr = "hello";
    vector<int> arr = fsmSearch(substr, str);
    cout << "Found \'"
         << substr
         << "\' in ";
    for (auto it : arr)
    {
        cout << it << ", ";
    }
    cout << endl;
}