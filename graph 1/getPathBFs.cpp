#include<bits/stdc++.h>
using namespace std;

vector<int > getPathBFS(int start , int end  , int** edges , int V , bool* visited){
    queue<int> q;
    unordered_map<int,int> map;
    vector<int> ans;

    q.push(start);
    visited[start]= true;
    bool check = false;

    while(!q.empty() && !check){
        int current  = q.front();
        for(int i=0 ; i<V ;i++){
            if( edges[current][i]==1 && !visited[i]){
                if(i==end){
                    ans.push_back(end);
                    check = true;
                    break;
                }
                q.push(i);
                map[i]=current;
            }
        }
        q.pop();
    }
    if(!ans.empty()){
        int current  = end;
        while(current!= start){
            current = map[current];
            ans.push_back(current);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        int ** edges = new int * [V];
        for(int i=0 ;i <V ; i++){
            edges[i] = new int [V]();
        }
         
        for(int i=0 ; i<E ; i++){
            int fv,sv;
            cin>>fv>>sv ;
            edges[fv][sv]= 1;
            edges[sv][fv] = 1;
        }
        int start , end;
        cin>>start>>end;
        bool * visited  = new bool[V];

        vector <int > ans = getPathBFS(start , end , edges, V, visited);
        for(int i=0 ; i< ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;


        for(int i=0 ; i<V; i++){
            delete [] edges[i];
        }
        delete [] edges;
        delete [] visited;
    }
}