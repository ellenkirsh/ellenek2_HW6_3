//
//  main.cpp
//  ellenek2_HW6_3
//
//  Created by Ellen Kirsh on 10/20/21.
//

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

bool isBipartite(int **G, int n){
    int s=0;
    int level[n];
    int levelval=0;
    for (int i=0; i<n; i++){
        level[i] = -1;
    }
    bool *explored = new bool[n];
    int *dist = new int[n];
    for(int i=0; i<n; i++){     // initializing arrays explored and dist
        explored[i] = false;
        dist[i] = -1;
    }
    dist[s] = 0;              // distance of s is 0
    explored[s] = true;       // s has been explored
    queue<int> q;             // create an empty queue of integers
    q.push(s);                // push s in queue
    while(! q.empty()){       // while queue is not empty
        int u = q.front();    // get the oldest element in queue
        q.pop();              // delete the oldest element in queue
        level[s]=levelval;
        levelval++;
        for(int i=0; i<n; i++){  // check for every other node whether it is adjacent to u
            if(G[u][i] == 1 && explored[i] == false){  // if i is adjacent to u and has not been explored so far
                level[i] = level[u] + 1;
                explored[i] = true;
                q.push(i);
            }
        }
        levelval = level[u];
    }
    int sum=0;
    for(int i=0; i<n; i++){
        if(explored[i] == false){
            sum = sum + 1;
        }
    }
    if (sum > 0){
        cout << "Graph is not connected" << endl;
    }else{
        for(int i = 0; i < n; i++){
            for(int j=0; j<n; j++){
                if(level[i] == level[j] && G[i][j] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ifstream file1;
    file1.open("input-graph.txt");
    int n;
    file1 >> n;
    cout << n << endl;
    int ** G;
    G = new int *[n];
    for(int i=0; i<n; i++){
        G[i] = new int[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            file1 >> G[i][j];
        }
    }
    int s;
    file1 >> s;
    file1.close();
    bool result;
    result = isBipartite(G, n);
    if(result == true){
        cout << "Graph is Bipartite"<< endl;
    }else{
        cout << "Graph is not Bipartite"<<endl;
    }
    return 0;
}
