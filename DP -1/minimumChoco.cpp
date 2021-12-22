#include<bits/stdc++.h>
using namespace std;

int minChocolate (int * input , int n , int * output){
        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        int * input = new int[n];
        for ( int  i=0 ; i< n ; i++){
            cin>>input[i];
        }
        int * output = new int[n];
        cout<<minChocolate(input , n ,output)<<endl;
        delete [] input;
        delete [] output;
    }
}