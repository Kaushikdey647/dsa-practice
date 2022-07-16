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


/**
 * @brief A variation of counting sort that sorts in reference to digits in a
 * specific powers of 10.
 * @param begin(int*) : Points to the starting element of the array
 * @param end (int*) : Points after the last element of the array
 * @param power : Power of tens, to sort according to
 * @return true : Sort was successful
 * @return false : Sort failed due to some error
 */
/*
 * example assume the array arr[]
 * 
 *      413, 549, 219, 905, 672, 967, 293, 284, 543, 821, 593
 * 
 * we take the digits in tens place, i.e. power = 1, say this array num[]
 * 
 *      1,  4,  1,  0,  7,  6,  9,  8,  4,  2,  9
 * 
 * We store their count in a count[] array
 * 
 *      0   1   2   3   4   5   6   7   8   9
 *      1   2   1   0   2   0   1   1   1   2
 * 
 * Then we make count[] cumulative
 * 
 *      0   1   2   3   4   5   6   7   8   9
 *      1   3   4   4   6   6   7   8   9   11
 * 
 * Assume another output array
 * 
 *      0   1   2   3   4   5   6   7   8   9
 *      0   0   0   0   0   0   0   0   0   0
 * 
 * In output, output[ count[num[i]] ] = arr[i], and arrange accordingly
 * 
 */
bool countingSort(int* begin, int* end, int order){
    try{
        //create an array of outputs to store the same
        int output[end-begin];

        //an array to store the count of digits
        int* count = new int[10];

        //store the count of digits in respective places
        for(int* it = begin; it != end; it++){
            ++count[ ((*it)/order)%10 ];
        }
        //make it cumulative count
        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }

        //do some random shit
        for(int* it = begin; it != end; it++){
            output[count[((*it)/order)%10] - 1] = *it;
            --count[((*it)/order)%10];
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

bool radixSort(int* begin, int* end){

    //Overall Complexity: O(nlog10(max))
    try{
        int max = 0;
        //get the maximum element
        //Complexity: O(n)
        for(int* it = begin; it != end; it++){
            if(*it > max) max = *it;
        }

        //iterate for every power of 10
        //Complexity: O( log10(max))
        for(int exp = 1; max/exp >0 ; exp *= 10){
            //Complexity: 
            countingSort(begin,end,exp);
        }
    }
    catch(...){
        return false;
    }
    return true;
}

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

int main()
{
    int arr[] = {54,346,478,347,554,1634,6134,2134,879,35,568,135}; //12 ELEMS
    radixSort(arr,arr+12);  
    for(int i = 0; i < 12; i++){
        cout << arr[i] <<" ";
    }
}