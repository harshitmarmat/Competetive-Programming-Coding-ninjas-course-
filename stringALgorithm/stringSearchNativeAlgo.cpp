#include<bits/stdc++.h>
using namespace std;

bool check(string s1 , string s2 , int size){
    if(size==0){
        return true;
    }
    if(s1[0]==s2[0]){
        return check(s1.substr(1),s2.substr(1),size-1);
    }
    
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        bool ans = false;
        for(int i=0 ; i<s.length()-p.length();i++){
            if(check(s.substr(i,p.length()),p,p.length())){
                ans = true;
                cout<<"Yes"<<endl;
            }
        }
        if(!ans){
            cout<<"No"<<endl;
        }
    }
}