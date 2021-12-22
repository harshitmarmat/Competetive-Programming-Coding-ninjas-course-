#include<bits/stdc++.h>
using namespace std;

vector<int> getPathDFS(int start , int end , int V , int ** edges , bool * visited){
    vector<int> ans;
    if(start==end){
        ans.push_back(start);
        visited[start]= true;
        return ans;
    }
    visited[start]= true;
    for(int i=0 ; i<V ;i++){
        if(edges[start][i]==1 && !visited[i]){
            ans = getPathDFS(i,end, V, edges , visited);
            if(!ans.empty()){
                ans.push_back(start);
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V;
        cin>>V;
        int E;
        cin>>E;
        int ** edges = new int *[V];
        for(int i=0 ; i<V ;i++){
            edges[i] = new int[V]();
        }

        for(int i=0 ; i<E;i++){
            int fv , sv;
            cin>>fv>>sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        int start , end;
        cin>>start>>end;
        bool * visited = new bool[V]();
        vector<int> path = getPathDFS(start,end,V,edges,visited);
        for(int i=0 ;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        for(int i=0 ; i<V ;i++){
            delete [] edges[i];
        }
        delete[] edges;
        delete [] visited;
    }
}