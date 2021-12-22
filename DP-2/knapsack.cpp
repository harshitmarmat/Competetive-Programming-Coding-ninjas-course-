#include<bits/stdc++.h>
using namespace std;

// int knapSack ( int * wt , int * val ,int n , int weight){
//     if( n==0 || weight == 0){
//         return 0;
//     }
//     if(wt[n-1]>weight){
//         return knapSack(wt,val,n-1,weight);
//     }
//     // int ans =0;
//     else{
//         int include = val[n-1] + knapSack(wt,val,n-1,weight-wt[n-1]);
//         int exclude = knapSack(wt,val,n-1,weight);
//         return max(include,exclude);
//     }
// }

// int knapSack ( int * wt , int * val ,int n , int weight,int ** dp){
//     if( n==0 || weight == 0){
//         return 0;
//     }
//     if(wt[n-1]>weight){
//         return knapSack(wt,val,n-1,weight,dp);
//     }
//        int ans =0;
//     if(dp[n][weight]>-1){
//         return dp[n][weight];
//     }
//     else{
//         int include = val[n-1] + knapSack(wt,val,n-1,weight-wt[n-1],dp);
//         int exclude = knapSack(wt,val,n-1,weight,dp);
//         ans= max(include,exclude);
//     }
//     dp[n][weight]=ans;
//     return ans;
// }

int knapSack ( int * wt , int * val ,int num , int weight){
    int m = num;
    int n = weight;
    int ** dp = new int * [m+1];
    for( int i=0 ; i<= m;i++){
        dp[i]= new int [n+1];
    }

    for( int  i=0 ;i<=m ;i++){
        dp[i][0]= 0;
    }
    for( int i=0 ; i<=n ;i++){
        dp[0][i]=0;
    }

    for ( int i=1; i<=m;i++){
        for ( int j=0 ; j<= n ;j++){
            if(wt[i-1]>weight){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    int ans =dp[m][n];
    for( int i=0 ;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;

}
int main(){
    int n; 
    cin>>n;
    int * wt = new int [n];
    int * val = new int [n];
    for ( int i=0 ;i<n ;i++){
        cin>>wt[i];   
    }
    for ( int i=0 ;i<n ;i++){
        cin>>val[i];   
    }
    int weight; 
    cin>>weight;
    int ** dp = new int *[n+1];
    for( int i=0 ; i<=n ;i++){
        dp[i]= new int [weight+1];
        for ( int j=0 ; j<= weight ; j++){
            dp[i][j]=-1;
        }
    }
    cout<< knapSack(wt,val,n,weight)<<endl;
    for ( int i=0 ; i<=n ;i++){
        delete [] dp[i];
    }
    delete [] dp;
}