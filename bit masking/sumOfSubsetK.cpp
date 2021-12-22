#include<bits/stdc++.h>
using namespace std;

int sumToK( int * arr , int n ,int k){
    int z=0;
    for( int mask =0 ; mask <(1<<n) ; mask++){
        int count =0;
        for( int j=0 ; j<n ;j++){
            if((mask&(1<<j))!=0){
                count+=arr[j];
            }
        }
        if(count == k){
            for( int i =0 ; i<n ;i++){
                if( (mask&(1<<i))!=0){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
            z++;
        }
    }
    return z;
}

// int sumToK(int cost[4])
int main(){
    int n ;
    int k;
    cin>>n>>k; 
    int * arr = new int [n];
    for(int i=0 ;i<n ;i++){
        cin>>arr[i];
    }
    cout<<sumToK(arr,n,k)<<endl;
}