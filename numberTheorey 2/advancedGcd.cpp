#include<bits/stdc++.h>
using namespace std;

int solve(string b,int a){
    if(b.size()==0){
        return 0;
    }
    int c = solve(b.substr(0,b.size()-1),a);
    int current  = b[b.size()-1]-'0';
    return ((c*10)+current)%a;
}

int gcd( int b , int a){
    if(a==0){
        return b; 
    }
    // string c = solve(b);
    return gcd(a,b%a);
}

int main(){
    int a;
    cin>>a;
    string b;
    cin>>b;
    int c = solve(b,a);
    cout<<gcd(a,c);
}