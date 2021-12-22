#include<bits/stdc++.h>
using namespace std;

// int lcs(string s1, string s2){
//     if(s1.size()==0|| s2.size()==0){
//         return 0;
//     }
//     if(s1[0]==s2[0]){
//         return 1+ lcs(s1.substr(1),s2.substr(1));
//     }
//     else{
//         int option1 = lcs( s1, s2.substr(1));
//         int option2 = lcs(s1.substr(1), s2);
//         return max(option1, option2);
//     }
// }

// int lcs_helper( string s1, string s2, int m, int n ,int ** dp){
//     if(m==0|| n==0){
//         return 0;
//     }
//     if(dp[m][n]>-1){
//         return dp[m][n];
//     }
//     int ans =0;
//     if(s1[0]==s2[0]){
//         ans= 1+ lcs_helper(s1.substr(1),s2.substr(1),m-1,n-1,dp);
//     }
//     else{
//         int option1 = lcs_helper( s1, s2.substr(1),m,n-1,dp);
//         int option2 = lcs_helper(s1.substr(1), s2,m-1,n,dp);
//         ans =  max(option1, option2);
//     }
//     dp[m][n]=ans;
//     return ans;
// }

int lcs_helper(string s1, string s2, int m , int n , int** dp){
    for( int i=0 ; i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for( int i=1 ; i<=m ;i++){
        for(int j=1 ;j<=n ; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int ** dp = new int*[m+1];
    for( int i=0;i<=m;i++){
        dp[i]=new int [n+1];
        // for ( int j=0 ; j<=n; j++){
        //     dp[i][j]=-1;
        // }
    }
    int ans =  lcs_helper(s1,s2,m,n,dp);
    for (int i=0 ;i<=m ;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}


 int main (){
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<lcs(s1, s2);
}
