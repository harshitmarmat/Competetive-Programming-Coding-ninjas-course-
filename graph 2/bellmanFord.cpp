#include<bits/stdc++.h>
using namespace std;

class Edges{
    public:
        int v; 
        int u; 
        int w;
};

void bellmanAlgo(int V ,int E , Edges * input ){
    int * distance =  new int[V];
    for(int i=0 ; i<V;i++){
        distance[i]=INT_MAX;
    }
    distance[0]= 0;
    for(int i=0 ; i<V-1;i++){
        for(int j=0 ;j<E;j++){
            int u = input[j].u;
            int v = input[j].v;
            int w = input[j].w;
            if(distance[u]!=INT_MAX && (distance[v]>distance[u]+ w)){
                distance[v] = distance[u]+ w;
            }
        }
    }
    cout<<distance[end]-distance[start]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V, E;
        cin>>V>>E;
        int start,end;
        cin>>start>>end;
        Edges * input  = new Edges[E];
        for(int i=0 ; i<E; i++){
            cin>>input[i].u>>input[i].v>>input[i].w;
        }

        bellmanAlgo(V,E, input);
        delete [] input;
    }
}