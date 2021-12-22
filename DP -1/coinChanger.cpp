#include<bits/stdc++.h>
using namespace std;

int coinChanger( int v , int numd, int * d, int** output){
    if(numd==0){
        return 0;
    }
    if(v==0){
        return 1;
    }
    if(v<0){
        return 0;
    }
    if(output[numd][v]>-1){
        return output[numd][v];
    }

    int first = coinChanger(v-d[0],numd,d,output);
    int second = coinChanger(v,numd-1,d+1,output);
    output[numd][v]= first+second;
    return output[numd][v];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int numd;
        cin>>numd;
        int * d = new int [numd];
        for ( int i=0 ;i<numd;i++){
            cin>>d[i];
        }
        int v;
        cin>>v;
        
        int ** output = new int*[numd+1];
        for( int i=0;i<=numd;i++){
            output[i]=new int[v+1];
            for(int j=0 ;j<=v;j++){
                output[i][j]=-1;
            }
        }
        cout<<coinChanger(v,numd,d,output);
    }
}