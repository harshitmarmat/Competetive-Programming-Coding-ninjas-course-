#include<bits/stdc++.h>
using namespace std;

vector<int> getGraph( int s , int V , int ** edges , bool * visited){
    queue<int> q;
    vector<int> ans;
    q.push( s);
    visited[s] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        ans.push_back(current);
        for(int i=0 ;i<V ;i++){
            if(edges[current][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
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
        for( int i=0 ;i<V;i++){
            edges[i] = new int[V]();
        }
        
        for(int i=0; i<E; i++){
            int fv , sv;
            cin>>fv>>sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        bool * visited = new bool[V]();
        vector<vector<int>> final_ans;
        for( int i =0 ; i<V ; i++){
            if(!visited[i]){
                vector<int> ans = getGraph(i,V,edges,visited);
                final_ans.push_back(ans);
            }
        }
        for( int i= 0 ; i<final_ans.size() ;i++){
            for(int j=0 ; j< final_ans[i].size();j++){
                cout<<final_ans[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1 ;i<=V;i++){
            delete [] edges[i];
        }
        delete [] edges;
        delete [] visited;
    }

}