#include<bits/stdc++.h>
using namespace std;

// int maxCost( int cost[4][4] , int n , int p , int mask){
//     if(p>=n){
//         return 0;
//     }
//     int maximum  = INT_MIN;
//     for(int i=0 ; i<n ; i++){
//         if((mask &(1<<i)) ==0 ){
//             int ans = maxCost(cost,n,p+1,mask |(1<<i))+cost[p][i];
//             if(ans>maximum){
//                 maximum = ans;
//             }
//         }
//     }
//     return maximum;
// }

int maxCost( int cost[4][4] , int n, int p , int mask,int * dp){
    if(p>=n){
        return 0;
    }
    if(dp[mask]!= INT_MIN){
        return dp[mask];
    }
    int maximum = INT_MIN;
    for(int i=0 ; i<n ;i++){
        if(!(mask&(1<<i))){
            int ans = maxCost( cost , n ,p+1, mask |(1<<i),dp)+ cost[p][i];
            if(ans>maximum){
                maximum = ans;
            }
        }
    }
    dp[mask] = maximum;
    return maximum;    
}

int main(){
    int cost[4][4]= {{10,2,6,5},{1,5,12,8},{7,8,9,3},{15,13,4,10}};
    int * dp = new int [1<<4];
    for(int i=0 ; i<(1<<4);i++){
        dp[i]=INT_MIN;
    }
    cout<<maxCost(cost,4,0,0,dp)<<endl;
    cout<<dp[0];
}