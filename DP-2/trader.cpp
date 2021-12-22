#include<bits/stdc++.h>
using namespace std;

int maxProfit(int * arr, int n , int k , int ongoing, int *** dp){
    if(n==0 || k==0){
        return 0;
    }
    if(dp[n][k][ongoing]>-1){
        return dp[n][k][ongoing];
    }
    int option1 = maxProfit( arr+1 , n-1 , k , ongoing,dp);
    int option2;
    if(ongoing==1){
        option2 = maxProfit(arr+1,n-1,k-1, 0,dp) + arr[0];
    }else{
        if(k>0){
            option2 =maxProfit (arr+1,n-1,k,1,dp) - arr[0];
        }
    }
    dp[n][k][ongoing] = max(option1,option2);
    return dp[n][k][ongoing];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int n;
        cin>>n;
        int * stock = new int [n];
        for(int i=0 ;i<n ;i++){
            cin>>stock[i];
        } 

        
        int *** dp = new int **[n+1];
        for(int i=0 ; i<= n;i++){
            dp[i] = new int* [k+1];
            for(int j=0 ; j<=k ;j++){
                dp[i][j] = new int [2];
                for(int l =0 ;l<2 ;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        cout<<maxProfit(stock,n,k,0,dp)<<endl;
        for(int i=0 ; i<=n ;i++){
            for(int j = 0 ;j<=k ;j++){
                delete [] dp[i][j];
            }
            delete [] dp[i];
        }
        delete [] dp;
    }
}