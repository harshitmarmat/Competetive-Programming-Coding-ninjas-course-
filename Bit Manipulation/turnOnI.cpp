#include<bits/stdc++.h>
using namespace std;

int turnOnI(int n ,int i){
    if(i==0){
        return n;
    }
    return n | (1<<i-1);
}

int main(){
    int n ,i;
    cin>> n>> i;
    cout<<turnOnI(n,i);
}