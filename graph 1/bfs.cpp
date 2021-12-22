#include<bits/stdc++.h>
using namespace std;

void print ( int sv , int ** edges , int n,  bool * visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int current = q.front();
        cout<<current<<" ";
        for(int i=0 ; i< n ;i++){
            if( edges[current][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}

int main(){
    int n ; 
    cin>> n ;
    int e ; 
    cin>> e;
    int ** edges = new int *[n];
    for(int i=0; i<n ;i++){
        edges[i] = new int[n]();
    }

    for( int i=0 ; i<e ;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] =1;
        edges[s][f] = 1;
    }

    bool * visited = new bool [n];
    for(int i=0 ; i<n;i++){
        visited[i]=false;
    }
    print(0  ,edges , n , visited);

    for(int i=0 ;i< n ;i++){
        delete edges[i];
    }
    delete edges;
}