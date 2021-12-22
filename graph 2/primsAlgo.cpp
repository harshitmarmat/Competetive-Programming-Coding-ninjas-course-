#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int * weight ,bool * visited , int V){
    int minVertex =-1;
    for(int i=0 ;i<V ;i++){
        if(!visited[i] && (minVertex ==-1 || weight[i]< weight[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}

int primsAlgo(int ** edges , int V){
    int * parent = new int [V];
    int * weight = new int [V];
    bool * visited = new bool[V]();

    for( int i= 0; i<V ;i++){
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;

    for(int i=0 ;i<V-1 ; i++){
        int minVertex = getMinVertex(weight,visited,V);
        visited[minVertex]=true;
        for(int j=0; j<V ;j++){
            if(edges[minVertex][j]!=0 && !visited[j]){
                int currentWeight = edges[minVertex][j];
                if(currentWeight<weight[j]){
                    weight[j] = currentWeight;
                    parent[j] = minVertex;
                } 
            }
        }
    }
    int sum=0;
    for(int i=0; i<V;i++){
        sum+=weight[i];
        // cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }

    delete [] parent;
    delete [] visited;
    delete [] weight;
    return sum;
}

int main(){
    int t ; 
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        int ** edges = new int*[V];
        for(int i=0; i<V ; i++){
            edges[i] = new int[V]();
        }

        for(int i=0 ; i<E;i++){
            int fv , sv,wt;
            cin>>fv>>sv>>wt;
            edges[fv][sv]=wt;
            edges[sv][fv]=wt;
        }

        cout<<primsAlgo(edges , V)<<endl;

        for(int i=0 ; i<V;i++){
            delete[] edges[i];
        }
        delete [] edges;
    }
}