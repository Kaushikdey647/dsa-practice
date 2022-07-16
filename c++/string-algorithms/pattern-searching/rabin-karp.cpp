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


//BEHOLD THE ROLLING HASH
vector<int> rabinKarpSearch(string pattern, string text){
    
    //Initial Variables
    int exp;
    int patternHash, textHash;
    vector<int> result;
    int m = pattern.length();
    int n = text.length();
    // int maxval = (int('z') - int('a')) + 2; //calcualate the maximum possible value and one more :) this can act as a power while hashing
    int maxval = 2;

    //Calcualting pattern hash

    patternHash = 0;
    exp = 1;

    for (int x = 0; x < m; x++)
    {
        patternHash += (int( pattern[m-x-1] ) - int('a')+1) * exp;
        exp *= maxval;
    }

    //Now comes the matching part

    textHash = 0;
    exp = 1;

    //initial hash
    for (int x = 0; x < m; x++)
    {
        textHash += (int(text[m-x-1]) - int('a')+1) * exp;
        exp *= maxval;
    }

    exp = maxval; //will see later

    for (int i = 0; i <= n - m; i++)
    {
        //check for match (recommended when having a weak hash)
        if(textHash == patternHash){
            //we have a match
            int k = 0;
            while (k < m)
            {
                if(pattern[k] != text[i+k])
                    break;
                k++;
            }
            if (k == m)
                result.push_back(i); //match confirmed
        }

        //push directly (recommended when having a strong hash)
        // if(textHash == patternHash){
        //     result.push_back(i);
        // }

        if(i == n-m)
            break;
        // roll the hash
        textHash -= (text[i]-int('a')+1) * pow(exp, m - 1); //get the outest suffix gone
        textHash *= exp; //multiply with exponent
        textHash += (text[i+m]-int('a')+1); //get in the latest element
    }

    return result;
}

int main()
{
    string str = "hello there hello world this looks like a hello place huh hello world this looks like a hello place huhello world this looks like a hello place huehuehue one last time hello";
    string substr = "looks like a hello place";
    vector<int> arr = rabinKarpSearch(substr, str);
    cout << "Found \'"
         << substr
         << "\' in ";
    for (auto it : arr)
    {
        cout << it << ", ";
    }
    cout << endl;
}
/*
hello there hello world this looks like a hello place huh hello world this looks like a hello place huhello world this looks like a hello place huehuehue one last time hello
*/