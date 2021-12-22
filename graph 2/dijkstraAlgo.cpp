#include<bits/stdc++.h>
using namespace std;

int getIndex(bool * visited , int * distArr , int V){
    int index = -1;
    for(int i=0 ;i<V ;i++){
        if(!visited[i] && (i==-1 || distArr[i]<distArr[index])){
            index = i;
        }
    }
    return index;
}

void dijkstraAlgo(int V , int ** edges ){
    // int * vertex = new int[V];
    int * distArr = new int[V];
    bool * visited  = new bool [V]();
    for( int i=0 ; i<V ;i++){
        // vertex[i] = i;
        distArr[i] = INT_MAX;
    }
    distArr[0] = 0;
    for(int j=0 ; j<V-1 ;j++){
        int vertexIndex = getIndex(visited , distArr , V);
        visited[vertexIndex]=true;
        for(int i=0 ; i<V;i++){
            if(edges[vertexIndex][i]!=-1 && !visited[i] && distArr[i]> edges[vertexIndex][i]+distArr[vertexIndex]){
                distArr[i] = edges[vertexIndex][i]+distArr[vertexIndex];
            }
        }
    }
    for(int i=0 ;i<V;i++){
        cout<<i<<" "<<distArr[i]<<endl;
    }
    delete [] distArr;
    delete [] visited;
    return;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int V , E;
        cin>>V>>E;

        int ** edges = new int * [V];
        for(int i=0; i<V ;i++){
            edges[i] = new int [V];
            for(int j=0 ;j<V;j++){
                edges[i][j] = -1;
            }
        }   

        for(int i=0;  i<E ;i++){
            int fv , sv,dist;
            cin>>fv>>sv>>dist;
            edges[fv][sv] = dist;
            edges[sv][fv] = dist;
        }
         
        dijkstraAlgo(V,edges);
        for(int i=0 ; i<V ; i++){
            delete [] edges[i];
        }
        delete [] edges;
    }
}