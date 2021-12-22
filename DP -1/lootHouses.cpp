#include<bits/stdc++.h>
using namespace std;

int lootHouse( int * input , int n ,  int  * output){
    output[0] = input[0];
    output[1] = input[1];
    for ( int i=2 ; i<n ; i++){
        output[i] = max( input[i]+output[i-2],output[i-1]);
    }
    return output[n-1];
}

int main(){
    int n ; 
    cin>>n;
    int * input = new int[n];
    for (int i=0; i<n ;i++){
        cin>>input[i];
    }
    int * output = new  int [n];
    cout<<lootHouse( input, n , output)<<endl;
    delete [] input;
    delete [] output;
}