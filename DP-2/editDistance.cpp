#include<bits/stdc++.h>
using namespace std;

// int editDistance(string s1, string s2,int m, int n ,int**dp){
//     if( m==0 && n==0){
//         return 0;
//     }
//     if(m==0  && n!=0){
//         return s2.size();
//     }
//     if(m!=0 && n==0){
//         return s1.size();
//     }
//     if(dp[m][n]>-1){
//         return dp[m][n];
//     }
//     if(s1[0]==s2[0]){
//         return editDistance(s1.substr(1),s2.substr(1),m-1,n-1,dp);
//     }
//     int ans = 0;
//     int optionAdd = 1 + editDistance(s1,s2.substr(1),m,n-1,dp);
//     int optionReplace = 1 + editDistance(s1.substr(1),s2.substr(1),m-1,n-1,dp);
//     int optionDelete = 1 + editDistance(s1.substr(1),s2,m-1,n,dp);
//     ans = min(optionAdd,min(optionDelete,optionReplace));
//     dp[m][n]=ans;
//     return ans;
// }
int editDistance(string s1, string s2,int m, int n ,int**dp){
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=n;i++){
        dp[0]][i]=i;
    }
    for( int i=1;i<=m;i++){
        for (int j=1;j<= n;j++){
            if(s1[i-1]==s2[i-1]){
                dp[i][j] = dj[i-1][j-1];
            }
            else{
                dp[i][j] = min(1+ dp[i][j-1],min(1+dp[i-1][j-1],dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1;
        string s2;
        cin>>s1>>s2;
        int m = s1.size();
        int n = s2.size();
        int ** dp= new int* [m+1];
        for(int i =0 ;i<= m ;i++){
            dp[i] = new int[n+1];
            for( int j=0 ;j<=n ;j++){
                dp[i][j]=-1;
            }
        }
        cout<<editDistance(s1,s2,m,n,dp)<<endl;
        for(int i=0 ; i<=m ;i++){
            delete [] dp[i];
        }
        delete [] dp;
    }
}