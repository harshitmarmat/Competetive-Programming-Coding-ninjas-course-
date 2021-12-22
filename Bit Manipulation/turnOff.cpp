#include<bits/stdc++.h>
using namespace std;

int turnOffI(int n ,int i){
    if(i<=0){
        return n;
    }
    int ans = n & ~(1<<(i-1));
    return ans;
}

int main(){
    int n;
    int i;
    cin>>n>>i;
    cout<<turnOffI(n,i);
}