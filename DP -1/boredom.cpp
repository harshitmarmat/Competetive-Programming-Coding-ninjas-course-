#include<bits/stdc++.h>
using namespace std;

int boredom(int * input, int n , int * output){
    output[0] = 0;
    output[1] = max( input[1],input[0]);
    for( int i=1 ; i<n ; i++){
        output[i] = max(output[i-2]+( i*input[i]),output[i-1]);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int * input = new int[n];
        for ( int i=0 ; i<n ;i++){
            cin>>input[i];
        }
        int * output = new int[n];
        cout<<boredom(input, n, output)<<endl;
    }
}