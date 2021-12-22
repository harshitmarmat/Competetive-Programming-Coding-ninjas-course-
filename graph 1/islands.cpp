#include<bits/stdc++.h>
using namespace std;

void update( int s, int V ,int ** edges , bool * visited){
    queue<int> q;
    q.push(s);
    visited[s]= true;
    while(!q.empty()){
        int current  = q.front();
        q.pop();
        for (int i=0 ; i<V ; i++){
            if(edges[V][i]==1 && !visited[i]){
                visited[i]= true;
                q.push(i);
            }
        }
    }
    return ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V;
        cin>>V;
        int E ; 
        cin>>E;
        int ** edges = new int * [V];
        for(int i=0 ; i<V ;i++){
            edges[i] = new int[V]();
        }
        for(int i=0 ; i<E ;i++){
            int fv,sv;
            cin>>fv>>sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        bool * visited = new bool[V]();
        int count = 0;
        for(int i=0 ; i<V; i++ ){
            if(!visited[i]){
                count++;
                update(i , V , edges , visited);
            }
        }
        cout<<count<<endl;
        for(int i=0 ;i<V;i++){
            delete [] edges[i];
        }
        delete [] edges;
        delete [] visited;
    }
}