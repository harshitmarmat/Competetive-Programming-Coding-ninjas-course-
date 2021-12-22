#include<bits/stdc++.h>
using namespace std;

int largestPiece(int i, int j,int n ,char** cake){
    cake[i][j]='0';
    int ans=0;
    if(j+1<n && cake[i][j+1]=='1'){
        ans+= largestPiece(i,j+1,n,cake);
    }
    if(i+1<n && cake[i+1][j]=='1'){
        ans+= largestPiece(i+1 , j , n , cake);
    }
    if(i-1>=0 && cake[i-1][j]=='1'){
        ans+=largestPiece(i-1,j,n,cake);
    }
    if(j-1>0 && cake[i][j-1] =='1'){
        ans+=largestPiece(i , j-1 ,n,cake);
    }
    return ans+1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char ** cake  = new char* [n];
        for(int i=0 ;i<n ;i++){
            cake[i] = new char [n];
            for(int j=0 ;j<n ;j++){
                cin>>cake[i][j];
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ;i++){
            for(int j=0 ;j<n ;j++){
                if(cake[i][j]=='1'){
                    int best = largestPiece(i,j,n,cake);
                    ans = max(best,ans);
                }
            }
        }
        cout<<ans<<endl;
        for(int i=0 ;i<n ;i++){
            delete [] cake[i];
        }
        delete [] cake;
    }
}