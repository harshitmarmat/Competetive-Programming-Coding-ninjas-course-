#include<bits/stdc++.h>
using namespace std;

bool hasPath( int n ,int s,int  e , int ** edges , bool * visited){
    if(s==e){
        return true;
    }
    for( int i= 0 ; i<n ;i++){
        if(edges[s][i] ==1 && !visited[i]){
            visited[i] = true;
            return hasPath(n , i , e , edges , visited );
        }
    }
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int E;
        cin>>E;
        int ** edges = new int * [n];
        for(int i=0; i<n ;i++){
            edges[i] = new int [n]();
        }

        for(int i=0 ;i<E ; i++){
            int fv ,sv;
            cin>>fv >>sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        int s,e;
        cin>>s>>e;

        bool * visited = new bool[n]();
        bool ans = hasPath(n,s,e,edges, visited);
        if(ans){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
}