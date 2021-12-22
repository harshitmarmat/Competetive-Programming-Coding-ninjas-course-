#include<bits/stdc++.h>
using namespace std;

int primeToN(int n){
    bool * arr = new bool [n+1];
    for(int i=0 ; i<=n ;i++){
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    int count = 0;
    for(int i=2 ;i*i<=n ; i++){
        if(arr[i]){
            for(int j= i*i ; j<=n ;j+=i ){
                arr[j]= false;
            }
        }
    }
    for(int i=0 ; i<=n ;i++){
        if(arr[i]){
            cout<<i<<" ";
            count++;
        }
    }
    cout<<endl;
    delete [] arr;
    return count;
}

int main(){
    int  n ; 
    cin>>n;
    cout<<primeToN(n)<<endl;
}