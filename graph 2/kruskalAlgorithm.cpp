#include<bits/stdc++.h>
using namespace std;

class edges{
    public:
        int src, dest , weight;
};

bool compare(edges e1 , edges e2){
    return e1.weight < e2.weight;
}

bool unionAlg( int V1 , int V2 ,int *parent){
    while(parent[V1]!=V1 || parent[V2]!=V2){
        if(parent[V1]!=V1){
            V1= parent[V1];
        }
        if(parent[V2]!=V2){
            V2 = parent[V2];
        }
    }
    if(V1==V2){
        return true;
    }
    else{
        parent[V2] = V1;
        return false;
    }
}

int mst(int V, int E , edges * input, edges *ouput){
    sort(input, input+E , compare);
    int * parent = new int [V];
    for(int i=0 ;i<V;i++){
        parent[i]=i;
    }
    int count  =0;
    int i=0;
    while(count<V-1){
        edges current = input[i];
        int V1 = current.src;
        int V2 = current.dest;
        if(unionAlg(V1,V2,parent)){
            i++;
            continue;
        }
        else{
            ouput[count] = input[i];
            count++;

        }
        i++;
    }
    delete [] parent;
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V , E;
        cin>>V>>E;
        edges * input = new edges[E];
        for(int i=0 ; i< E ; i++){
            cin>>input[i].src>>input[i].dest>>input[i].weight;
        }
        edges * output = new edges[E]();
        cout<<mst(V,E,input,output)<<endl;
        for(int i=0 ;i<V ; i++){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight;
        }
        delete [] input;
        delete [] output;
    }
}