#include<bits/stdc++.h>
using namespace std;

void print ( int sv , int n , int ** edges){
    cout<<sv<<endl;
    for(int i=0 ; i <n ;i++){
        if(edges[sv][i] ==1 ){
            edges[sv][i] =0;
            edges[i][sv]=0;
            print(i,n,edges);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    int ** edges = new int *[n];
    for( int i=0 ;i<n ;i++){
        edges[i] = new int [n]();
    }

    for(int i=0 ; i<e; i++){
        int f , s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    print(0 ,n , edges);

    for(int i=0 ;i<n ;i++){
        delete edges[i];
    }
    delete edges;
}