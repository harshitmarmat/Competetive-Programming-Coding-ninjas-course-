#include<bits/stdc++.h>
using namespace std;

int fibDp( int n){
    int * dp = new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for( int i=2 ; i<=n ;i++){
        dp[i]= dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibMemo(int n , int * arr){
    if( n==0 | n==1){
        return 1;
    }
    if(arr[n]>0){
        return arr[n];
    }
    int output = fibMemo(n-1,arr)+ fibMemo(n-2,arr);
    arr[n]=output;
    return arr[n];
}

int fibRec(int n){
    if(n==0|| n==1){
        return 1;
    }
    return fibRec(n-1)+fibRec(n-2);
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n]{0};
    cout<<fibDp(n)<<endl;
    cout<<fibMemo(n,arr)<<endl;
    cout<<fibRec(n)<<endl;
    delete [] arr;

}