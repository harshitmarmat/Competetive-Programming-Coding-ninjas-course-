#include<bits/stdc++.h>
using namespace std;

int dielemma( vector<string> v , int n ,int mask){

    int newmask1 = 0;
    int newmask2 = 0;

    for(int i=0; i<n ;i++){
        if((mask&(1<<i))){
            
        }
    }
}

int main (){
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0 ; i<n ; i++){
            string s;
            v.push_back(s);
        }
        cout<<dielemma(v,n,(1<<n)-1)<<endl;
    }   
}