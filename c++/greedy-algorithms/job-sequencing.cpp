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

class job
{
public:
    char id;
    int deadline;
    int profit;

    job(){
        //Do Nothing 
    }

    job(char c, int d, int p){
        id = c;
        deadline = d;
        profit = p;
    }

    bool operator >(job x){
        return profit > x.profit;
    }
    bool operator <(job x){
        return profit < x.profit;
    }
};

vector<job> jobScheduling( vector<job> jobArr ){
    //Calculate length for obvious reasons
    int len = int(jobArr.size());
    //Sort all the jobs firsthand
    sort(jobArr.begin(), jobArr.end(), greater<>());
    // Storing the results
    vector<job> results(len);
    // free time slots
    vector<bool> slots;
    //Initialize all to false
    for(auto job: jobArr){
        slots.push_back(false);
    }
    //Iterate thru all jobs
    for(auto job: jobArr){
        //Find a free slot for this job
        for (int i = min(len, job.deadline) - 1; i >= 0; i--){
            if(slots[i] == false){
                cout << "Scheduled " << job.id << " at slot" << i+1 << endl;
                results[i] = job;
                slots[i] = true;
                break;
            }
        }
    }

    //Return your work
    return results;
}

int
main()
{
    vector<job> arr{
        job('a', 2, 100),
        job('b', 1, 19),
        job('c', 2, 27),
        job('d', 1, 25),
        job('e', 3, 15)};
    auto res = jobScheduling(arr);
    cout << "Job sequence: ";
    for (auto r: res){
        cout << r.id << " ";
    }
    cout << endl;
}