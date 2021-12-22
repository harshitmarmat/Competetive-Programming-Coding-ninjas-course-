#include<bits/stdc++.h>
using namespace std;

void dfs( int start , vector<int>* edges , bool * visited , set<int> * ans){
    visited[start]= true;
    ans->insert(start);
    for(int i=0 ;i<edges[start].size();i++){
        int next = edges[start][i];
        if(!visited[next]){
            dfs(next , edges, visited , ans);
        }
    }
}

set<set<int>*>* getComponents(int V,int E , vector<int> * edges){
    bool * visited = new bool[V]();
    set<set<int>*>* final_ans  = new set<set<int>*>();
    for(int i=0 ;i<V ; i++){
        if(!visited[i]){
            set<int> * ans = new set<int>();
            dfs(i,edges , visited ,ans);
            final_ans->insert(ans);
        }
    }
    delete [] visited;
    return final_ans;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<int> * edges = new vector<int>[V];
    for(int i=0; i<E; i++){
        int fv , sv;
        cin>>fv>>sv;
        edges[fv-1].push_back(sv-1);
        edges[sv-1].push_back(fv-1);
    }

    set<set<int>*>* components = getComponents(V,E,edges);
    set<set<int>*> :: iterator it1 = components->begin();
    while(it1 != components->end()){
        set<int> * component  = *it1;
        set<int> :: iterator it2 = component->begin();
        while(it2 != component->end()){
            cout<<*it2+1<<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    delete [] edges;
}