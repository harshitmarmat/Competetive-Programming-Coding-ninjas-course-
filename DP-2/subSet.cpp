#include<bits/stdc++.h>
using namespace std;

// bool subSet( int * arr ,int n ,int sum, int **dp){
//     if(sum==0){
//         return true;
//     }
//     if( n==0 || sum<0){
//         return false;
//     }
//     if(dp[n][sum]==true){
//         return true;
//     }
    
//     dp[n][sum]= subSet(arr,n-1,sum,dp) || subSet(arr,n-1,sum-arr[n-1],dp);
//     return dp[n][sum];
// }

bool subSet( int * arr, int n , int sum){
    int row = n;
    int col = sum;
    bool ** dp = new bool* [row+1];
    for ( int i=0 ; i<= row ;i++){
        dp[i] = new bool [col+1];
    }

    for (int i=0 ; i<=row; i++){
        dp[i][0]=true;
    }
    for(int i=1 ; i<= col ; i++){
        dp[0][i]= false;
    }
    for (int i=1;i<=row ; i++){
        for(int j=1 ; j<=col ;j++){
            if(j-arr[i-1]>=0){
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[row][col];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr =new int [n];
        for (int i=0 ;i<n ;i++){
            cin>>arr[i];
        }
        int k ; 
        cin>>k;
        int ** dp = new int *[n+1];
        for (int i=0 ;i<=n ; i++){
            dp[i] = new int [k+1]{false};
        }
        if(subSet(arr,n,k)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}