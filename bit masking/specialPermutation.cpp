#include<bits/stdc++.h>
using namespace std;

int solve(int n , int mask){
    if(mask== (1<<n)-2){
        return 1;
    }
    int ans= 0;
    for(int  i=0 ; i<n ;i++){
        if((mask & (1<<i))==0){
            for(int j=i ;j<n ;j++){
                if(j & i == j  && (mask&(1<<j))==0){
                    ans+=solve(n,mask|(1<<i));
                    // cout<<"hello"<<endl;
                }
            }
        }
    }
    return ans;
}

int main(){
    int t; 
    cin>>t;
    cout<<solve(t,0)<<endl;
}