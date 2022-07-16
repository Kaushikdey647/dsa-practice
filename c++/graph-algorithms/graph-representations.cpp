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

template <class T>
T cinget(std::istream &is)
{
    T result;
    is >> result;
    return result;
}

template <class T>
void swap(T *a, T *b)
{
    T temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * @brief Adjacency Matrix
 *
 * @pros : Adding, Removing and Query of edges can happen in O(1) time
 *
 * @cons : Consumes O(V^2) space, independent of the connectivity
 *
 */

bool arr[5][5] = {
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 0}};

/**
 * @brief Adjacency List
 *
 * @pros : Consumes O( |V| + |E| ) space, independent of the connectivity
 *
 * @cons : Querying edges can be done in O(|V|) time, adding and removing edges can be done in O(|E|) time
 */

vector<vector<int>> adjList;

void addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void removeEdge(int u, int v)
{
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (adjList[u][i] == v)
        {
            adjList[u].erase(adjList[u].begin() + i);
            break;
        }
    }
    for (int i = 0; i < adjList[v].size(); i++)
    {
        if (adjList[v][i] == u)
        {
            adjList[v].erase(adjList[v].begin() + i);
            break;
        }
    }
}

void printAdjList()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
}