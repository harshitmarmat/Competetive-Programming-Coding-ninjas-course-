#include<bits/stdc++.h>
using namespace std;

int numOfWays( int ** like, int n , int stud , int mask ,int * dp){
    if(stud>=n){
        return 1;
    }
    if( dp[mask] != INT_MIN){
        return dp[mask];
    }
    int ans =0;
    for (int i=0 ;i<n ;i++){
        if((mask&(1<<i))==0 && like[stud][i]==1){
            ans  += numOfWays(like, n, stud+1,(mask|(1<<i)),dp);
            // cout<<"hello"<<endl;
        }
    }
    dp[mask] = ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ; 
        cin>>n;
        int ** like = new int *[n];
        for( int i=0; i<n ;i++){
            like[i] = new int[n];
            for(int j=0 ;j<n ;j++){
                cin>>like[i][j];
            }
        }
        int * dp = new int [1<<n];
        for (int i=0 ;i<(1<<n) ; i++){
            dp[i]= INT_MIN;
        }

        cout<<numOfWays(like,n,0 ,0,dp)<<endl;
        for(int i=0 ;i< n ;i++){
            delete [] like[i];
        }
        delete [] like;
        delete [] dp;
    }
}