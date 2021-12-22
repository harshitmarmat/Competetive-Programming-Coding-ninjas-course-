#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        int count=0;

        int * arr = new int [n];
        for( int i=0 ; i< n ; i++){
            cin>>arr[i];
            count ^=arr[i];
        }
        cout<<count<<endl;
    }
}