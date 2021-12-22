#include<bits/stdc++.h>
using namespace std;
int output[19][19];


void helper( int rat[][19],int n,int i,int j){
    if(i==n-1 && j==n-1){
        output[i][j]=1;
        for( int p=0 ;p<n;p++){
            for( int q=0 ;q<n ;q++){
                cout<<output[p][q]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    if(i>=0 || i<n || j>=0 || j<n || rat[i][j]==1 || output[i][j]==0){
        return;
    }
        output[i][j]=1;
        helper(rat,n,i-1,j);
        helper(rat,n,i+1,j);
        helper(rat,n,i,j-1);
        helper(rat,n,i,j+1);
        output[i][j]=0;
}

void solve( int rat[][19],int n){
    
    memset(output,0,19*19*sizeof(int));
    helper(rat,n,0,0);
}


int main(){
    int n;
    cin>>n;
    int rat[19][19];
    for ( int i=0 ; i<n ;i++){
        for( int j=0 ;j<n ;j++){
            cin>>rat[i][j];
        }
    }
    
    solve(rat, n);
    
    // write your code here
    return 0;
}