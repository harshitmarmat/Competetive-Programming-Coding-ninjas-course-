#include<bits/stdc++.h>
using namespace std;

bool checkITh(int n , int i){
    int ans = n & (1<<i-1);
    cout<<ans<<endl;
    if( ans==0 ){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int n;
    cin>>n;
    int i;
    cin>>i;
    if(checkITh(n,i)){
        cout<<"set"<<endl;
    }
    else{
        cout<<"unset"<<endl;
    }
}