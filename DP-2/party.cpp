#include<bits/stdc++.h>
using namespace std;

int party( int * cost,int * fun ,int size, int total_cost ){
    int row = size;
    int col = total_cost;
    int ** dp = new int *[row+1];
    for (int i=0; i<=row ;i++){
        dp[i]=new int[col+1];
    }

    for( int i=0 ;i<=row ;i++){
        dp[i][0]=0;
    }
    for( int i=0 ; i<= col ; i++){
        dp[0][i] = 0;
    }

    for (int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++){
            if(cost[i-1]>total_cost){
                dp[i][j] =dp[i-1][j];
            }
            else{
                int option1 = fun[i-1]+dp[i-1][total_cost-cost[i-1]];
                int option2 = dp[i-1][j];
                dp[i][j] = max(option1,option2);
            }
        }
    }
    return dp[row][col];
}

int main(){
    int t;
    cin>>t;
    int * cost_arr = new int [t];
    for( int i=0 ; i<t ;i++){
        cin>>cost_arr[i];
    }
    int * fun_arr = new int [t];
    for(int i=0 ;i<t ; i++){
        cin>>fun_arr[i];
    }
    int total_cost ;
    cin>>total_cost;

    int ans = party(cost_arr,fun_arr,t,total_cost);
    cout<<total_cost<<" "<<ans<<endl;
}