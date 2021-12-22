#include<bits/stdc++.h>
using namespace std;

void dfs( int start , vector<int>* edges , bool * visited , unordered_set<int> * ans){
    visited[start] = true;
    ans->insert(start);
    for( int i=0 ;i<edges[start].size() ;i++){
        int next = edges[start][i];
        if(!visited[next]){
            dfs(next , edges, visited , ans);
        }
    }
}

unordered_set<unordered_set<int>*>* getComponents( int n , int E,vector<int>* edges){
    unordered_set<unordered_set<int>*>* final_ans = new unordered_set<unordered_set<int>*>();
    bool * visited = new bool[n]();
    for(int i=0 ;i<n ;i++){
        if(!visited[i]){
            unordered_set<int>* ans= new unordered_set<int>();
            dfs(i,edges , visited , ans);
            final_ans->insert(ans);
        }
    }
    return final_ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int E; 
        cin>>E;
        int * p = new int [n];
        int * q = new int [n];
        for(int i=0 ;i<n ;i++){
            cin>>p[i];
        }
        for( int i=0 ;i<n ;i++){
            cin>>q[i];
        }

        vector<int>* edges= new vector<int>[n];
        for( int i=0 ;i<E;i++){
            int fv , sv;
            cin>>fv>>sv;
            edges[fv-1].push_back(sv-1);
            edges[sv-1].push_back(fv-1);
        }

        unordered_set<unordered_set<int>*>* components = getComponents(n,E,edges);
        unordered_set<unordered_set<int>*> :: iterator it1 = components->begin();
        bool flag = true;
        while(it1!= components->end()){
            unordered_set<int>* component = *it1;
            unordered_set<int> :: iterator it2 = compocdnent->begin();
            unordered_set<int> p_index;
            unordered_set<int> q_index; 
            while(it2!= component->end() && flag){
                p_index.insert(p[*it2]);
                q_index.insert(q[*it2]);
                it2++;
            }
            if(p_index != q_index){
                flag = false;
                break;
            }
            delete component;
            it1++;
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        delete components;
    }
}