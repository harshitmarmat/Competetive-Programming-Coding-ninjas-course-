#include<bits/stdc++.h>
using namespace std;

void update( int s , int V , int ** edges, bool * visited){
    visited[s] = true;
    for(int i=0 ; i<V ;i++){
        if(edges[s][i]==1){
            visited[i] = true;
            update(i,V,edges ,visited);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        int ** edges = new int*[V];
        for(int i=0 ; i<V ;i++){
            edges[i] = new int [V]();
        }

        for(int i=0 ; i< E ;i++){
            int fv , sv;
            cin>>fv >>sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }

        bool * visited  = new bool [V]();
        update(0,V,edges ,visited);
        bool check = false;
        for(int i=0; i<V ;i++){
            if(!visited[i]){
                cout<<"false"<<endl;
        	    check = true;
                break;
            }
        }
        if(!check){
            cout<<"true"<<endl;
        }      
    }
}