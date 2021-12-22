#include<bits/stdc++.h>
using namespace std;

int flipI(int n, int i){
    return n ^ (1<<i);
}

int main(){
    int n ,i ;
    cin>> n >> i;
    cout<<flipI(n,i);
}